#ifndef INTEGRATEDSORT_MERGE_SORT_HPP
#define INTEGRATEDSORT_MERGE_SORT_HPP

#include <vector>

template <class T> class MergeSort {
  public:
    // this class should not be instantiated
    MergeSort() = delete;

    // sort array with default std::less() comparator
    static void sort(std::vector<T> &arr);

    // sort array with customized comparator
    static void sort(std::vector<T> &arr, auto cmp);

  private:
    // helper function: sort arr from index begin to end
    static void sort(std::vector<T> &arr, int lo, int hi, auto cmp);
    // helper function: merge two sorted array
    static void merge(std::vector<T> &arr, int lo, int mid, int hi, auto cmp);
};
template <class T> void MergeSort<T>::sort(std::vector<T> &arr) {
    sort(arr, std::less());
}

template <class T> void MergeSort<T>::sort(std::vector<T> &arr, auto cmp) {
    sort(arr, 0, arr.size() - 1, cmp);
}

template <class T>
void MergeSort<T>::sort(std::vector<T> &arr, int lo, int hi, auto cmp) {
    if (lo >= hi)
        return;

    int mid = (hi - lo) / 2 + lo;
    sort(arr, lo, mid, cmp);
    sort(arr, mid + 1, hi, cmp);
    merge(arr, lo, mid, hi, cmp);
}

template <class T>
void MergeSort<T>::merge(std::vector<T> &arr, int lo, int mid, int hi,
                         auto cmp) {
    // auxiliary array to help merging
    std::vector<T> aux(hi - lo + 1);
    int i = lo, j = mid + 1; // index at arr array
    int k = 0;               // index at aux array

    while (i <= mid && j <= hi) {
        if (cmp(arr[i], arr[j]))
            aux[k++] = arr[i++];
        else
            aux[k++] = arr[j++];
    }
    while (i <= mid)
        aux[k++] = arr[i++];
    while (j <= hi)
        aux[k++] = arr[j++];

    std::copy(aux.begin(), aux.end(), arr.begin() + lo);
}
#endif // INTEGRATEDSORT_MERGE_SORT_HPP
