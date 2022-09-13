#ifndef INTEGRATEDSORT_INTEGRATED_SORT_HH
#define INTEGRATEDSORT_INTEGRATED_SORT_HH

#include <vector>

template <class T> class IntegratedSort {
  public:
    // this class should not be instantiated
    IntegratedSort() = delete;

    static void sort(std::vector<T> &arr);
    static void sort(std::vector<T> &arr, auto cmp); // sort with customized comparator

  private:
    // THRESHOLD for switching between merge sort and insertion sort
    // when the size is smaller than THRESHOLD, insetion sort, vice versa.
    static const int THRESHOLD = 16;

    // helper function to sort array from index lo to hi
    static void sort(std::vector<T> &arr, int lo, int hi, auto cmp);

    // helper function to do inserton sort when the size of array is small
    static void insertion_sort(std::vector<T> &arr, int lo, int hi, auto cmp);

    // helper function to do the merge of two sorted subarrays
    static void merge(std::vector<T> &arr, int lo, int mid, int hi, auto cmp);
};

template <class T> void IntegratedSort<T>::sort(std::vector<T> &arr) {
    sort(arr, std::less());
}

template <class T> void IntegratedSort<T>::sort(std::vector<T> &arr, auto cmp) {
    IntegratedSort<T>::sort(arr, 0, arr.size(), cmp);
}

template <class T>
void IntegratedSort<T>::insertion_sort(std::vector<T> &arr, int lo, int hi, auto cmp) {
    for (int i = lo+1; i <= hi; ++i) {
        int j = i;
        while (j > 0 && cmp(arr[j], arr[j - 1])) {
            std::swap(arr[j - 1], arr[j]);
            j--;
        }
    }
}

template <class T>
void IntegratedSort<T>::sort(std::vector<T> &arr, int lo, int hi, auto cmp) {
    if (lo >= hi)
        return;
    if (hi - lo <= THRESHOLD) {
        insertion_sort(arr, lo, hi, cmp);
    } else {
        int mid = (hi - lo) / 2 + lo;
        sort(arr, lo, mid, cmp);
        sort(arr, mid + 1, hi, cmp);
        merge(arr, lo, mid, hi, cmp);
    }
}

template <class T>
void IntegratedSort<T>::merge(std::vector<T> &arr, int lo, int mid, int hi,
                              auto cmp) {
    // auxiliary array
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

#endif // INTEGRATEDSORT_INTEGRATED_SORT_HH
