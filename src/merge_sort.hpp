#ifndef INTEGRATEDSORT_MERGE_SORT_HPP
#define INTEGRATEDSORT_MERGE_SORT_HPP

#include <vector>

template <class T>
class MergeSort {
public:
    // this class should not be instantiated
    MergeSort() = delete;

    // sort array with default std::less() comparator
    static void sort (std::vector<T> &arr);

    // sort array with customized comparator
    static void sort (std::vector<T> &arr, auto cmp);

private:
    // helper function: sort arr from index begin to end
    static void sort (std::vector<T>& arr, int lo, int hi, auto cmp);
    // helper function: merge two sorted array
    static void merge (std::vector<T> &arr, int lo, int mid, int hi, auto cmp);
};

#endif //INTEGRATEDSORT_MERGE_SORT_HPP
