#ifndef KIDYUR_SORT_HPP
#define KIDYUR_SORT_HPP


#include <vector>


template<typename TNumeric>
void bubblesort(
    std::vector<TNumeric> &v, 
    bool (*is_gt)(const TNumeric lhs, const TNumeric rhs)
) noexcept
{
	const int32_t n = v.size();
	for (int32_t i = 0; i < n; i++) {
		for (int32_t j = 1; j < n; j++) {
			if (is_gt(v[j-1], v[j])) {
				TNumeric tmp = v[j];
				v[j] = v[j-1];
				v[j-1] = tmp;
			}
		}
	}
}


template<typename TNumeric>
void selectionsort(
    std::vector<TNumeric> &v, 
    bool (*is_gt)(const TNumeric lhs, const TNumeric rhs)
) noexcept
{
	const int32_t n = v.size();
	for (int32_t i = 0; i < n; i++) {
		int32_t minidx = i;
		for (int32_t j = i; j < n; j++) {
			if (is_gt(v[minidx], v[j])) {
				minidx = j;
			}
		}
		TNumeric tmp = v[i];
		v[i] = v[minidx];
		v[minidx] = tmp;
	}
}


template<typename TNumeric>
void mergesort(std::vector<TNumeric> &v) noexcept
{
	// TODO:
}



#endif // KIDYUR_SORT_HPP
