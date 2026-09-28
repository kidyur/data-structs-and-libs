#include <iostream>
#include <vector>
#include "sort.hpp"



/**
* This file exists to manually test the libraries.
*/

std::string printvec(std::vector<int> &v) 
{
	std::string vecstr = "{";
	for (int i = 0; i < v.size(); i++) {
		vecstr += std::to_string(v[i]);
		if (i != v.size() - 1)
			vecstr += ", "; 
	}
	vecstr += "}";
	return vecstr;
}

bool is_gt(const int lhs, const int rhs) 
{
    return lhs > rhs;
}

int main() 
{
	std::vector<int> v1 = {1, 3, 2, 4, 5};
	std::vector<int> v2 = {5, 4, 3, 2};
	std::vector<int> v3 = {2, 1};
	std::vector<int> v4 = {1};

	std::vector<
		std::vector<int>*
	> reftovec = {&v1, &v2, &v3, &v4};

	for (int i = 0; i < reftovec.size(); i++) {
		std::vector<int> sorted_v = *reftovec[i];
		bubblesort<int>(sorted_v, is_gt);
		std::cout 
			<< printvec(*reftovec[i]) 
			<< " | "
			<< printvec(sorted_v)
			<< std::endl;
	}

	return 0;
}
