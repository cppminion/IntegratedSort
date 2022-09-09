#include "insertion_sort.hpp"

template<class T>
void InsertionSort<T>::sort(std::vector<T> &arr) {
    sort(arr, std::less());
}

template <class T>
void InsertionSort<T>::sort(std::vector<T> &arr, auto cmp) {
    for (int i = 1; i < arr.size(); ++i) {
        int j = i;
        while (j > 0 && cmp(arr[j], arr[j-1])) {
            std::swap(arr[j-1], arr[j]);
            j--;
        }
    }
}