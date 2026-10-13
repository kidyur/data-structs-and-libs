
#include "segtree.hpp"
#include <cassert>
#include <iostream>

int main() 
{
    const int n = 5;
    Segtree sg = Segtree(n);
    for (int i = 0; i < n; i++) 
        assert(sg[i] == 0);
    std::cout << "Initializing passed;\n";

    for (int i = 0; i < 5; i++)
        sg.update(i, i+1);
    for (int i = 0; i < n; i++) 
        assert(sg[i] == i+1);
    std::cout << "Filling passed;\n";

    assert(sg.range(0, 4) == 15);
    std::cout << "range(0,4) passed;\n";

    sg.update(4, 20);
    std::cout << "update(4, 20) passed;\n";

    assert(sg.range(0, 3) == 10);
    std::cout << "range(0,3) passed;\n";
    assert(sg.range(0, 4) == 30);
    std::cout << "range(0,4) passed;\n";
}