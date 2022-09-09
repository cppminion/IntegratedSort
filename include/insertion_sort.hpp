#ifndef INTEGRATEDSORT_INSERTION_SORT_HPP
#define INTEGRATEDSORT_INSERTION_SORT_HPP
#include <vector>

template <class T> class InsertionSort {
  public:
    // this class should not be instantiated
    InsertionSort() = delete;

    static void sort(std::vector<T> &arr);
    static void sort(std::vector<T> &arr, auto cmp);
};
template <class T> void InsertionSort<T>::sort(std::vector<T> &arr) {
    sort(arr, std::less());
}

template <class T> void InsertionSort<T>::sort(std::vector<T> &arr, auto cmp) {
    for (int i = 1; i < arr.size(); ++i) {
        int j = i;
        while (j > 0 && cmp(arr[j], arr[j - 1])) {
            std::swap(arr[j - 1], arr[j]);
            j--;
        }
    }
}
#endif // INTEGRATEDSORT_INSERTION_SORT_HPP
