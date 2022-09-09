#ifndef INTEGRATEDSORT_INSERTION_SORT_HPP
#define INTEGRATEDSORT_INSERTION_SORT_HPP
#include <vector>

template <class T>
class InsertionSort {
public:
    // this class should not be instantiated
    InsertionSort() = delete;
    
    static void sort(std::vector<T> &arr);
    static void sort(std::vector<T> &arr, auto cmp);
};

#endif // INTEGRATEDSORT_INSERTION_SORT_HPP
