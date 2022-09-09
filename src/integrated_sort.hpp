#ifndef INTEGRATEDSORT_INTEGRATED_SORT_HH
#define INTEGRATEDSORT_INTEGRATED_SORT_HH

#include <vector>

template <class T>
class IntegratedSort {
public:
    // this class should not be instantiated
    IntegratedSort() = delete;

    static void sort(std::vector<T> &arr);
    static void sort(std::vector<T> &arr, auto cmp);

private:
    // THRESHOLD for switching between merge sort and insertion sort
    // when the size is smaller than THRESHOLD, insetion sort, vice versa.
    static const int THRESHOLD = 16;

    // helper function to sort array from index lo to hi
    static void sort(std::vector<T> &arr, int lo, int hi, auto cmp);

    // helper function to do inserton sort when the size of array is small
    static void insertion_sort(std::vector<T> &arr, auto cmp);

    // helper function to do the merge of two sorted subarrays
    static void merge(std::vector<T> &arr, int lo, int mid, int hi, auto cmp);
};

#endif //INTEGRATEDSORT_INTEGRATED_SORT_HH
