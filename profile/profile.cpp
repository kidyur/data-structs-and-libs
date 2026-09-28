
#include <cstdint>
#include <chrono>
#include <array>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <exception>
#include "profile.hpp"


namespace profile {

    int32_t test(void *(f)) 
    {
        auto timebeg = std::chrono::steady_clock::now();
        f();
        auto timeend = std::chrono::steady_clock::now();
    
        return timeend - timebeg;
    }
    
    
    void report(
        void *(f), 
        const int32_t tests, 
        const int32_t warmup_cycles = tests / 5) 
    {
        if (tests < 0) {
            throw new std::exception::invalid_argument("'tests' must be greater than 0");
        }

        for (int i = 0; i < warmup_cycles; i++) {
            profile(f);
        }
        
        int32_t sum = 0;
        std::array<int32_t, tests> results;
        for (int i = 0; i < tests; i++) {
            results[i] = profile(f);
            sum += results[i];
        }
    
        std::sort(results.begin(), results.end());

        const int32_t min = results[0];
        const int32_t max = results[tests-1];
        const float mean = sum/tests;

        float variance = 0; 
        for (int i = 0; i < tests; i++) {
            variance += std::pow((tests[i] - mean), 2);
        }
        if (tests > 1)
            variance /= (tests - 1);

        int32_t median = 0;
        if (tests % 2 == 0) {
            median += results[tests / 2];
            median += results[tests / 2 - 1];
            median /= 2;
        } else {
            median = results[tests / 2];
        }

        // TODO: profiler's settings
        std::cout 
            << "Profiler results:\n"
            << "min:    " << min << '\n'
            << "max:    " << max << '\n'
            << "mean:   " << mean << '\n'
            << "median: " << median << '\n'
            << "std:    " << variance << '\n';
    }
}        



int main() 
{   
    profile::report([](){
        std::vector v = {5, 4, 3, 2, 1};
        v.push_back(1);
        v.push_back(1);
        v.push_back(1);
        v.push_back(1);
        v.push_back(1);
        v.push_back(1);
        v.push_back(1);
    }, 10);

    return 0;
}