#include "integrated_sort.hpp"

template <class T>
void IntegratedSort<T>::sort(std::vector<T> &arr) {
    sort(arr, std::less());
}

template <class T>
void IntegratedSort<T>::sort(std::vector<T> &arr, auto cmp) {
    IntegratedSort<T>::sort(arr, 0, arr.size(), cmp);
}

template <class T>
void IntegratedSort<T>::insertion_sort(std::vector<T> &arr, auto cmp) {
    for (int i = 1; i < arr.size(); ++i) {
        int j = i;
        while (j > 0 && cmp(arr[j], arr[j-1])) {
            std::swap(arr[j-1], arr[j]);
            j--;
        }
    }
}

template <class T>
void IntegratedSort<T>::sort(std::vector<T> &arr, int lo, int hi, auto cmp) {
    if (lo >= hi)
        return ;
    if (hi - lo <= THRESHOLD) {
        insertion_sort(arr, cmp);
    } else {
        int mid = (hi - lo) / 2 + lo;
        sort(arr, lo, mid, cmp);
        sort(arr, mid+1, hi, cmp);
        merge(arr, lo, mid, hi, cmp);
    }
}

template<class T>
void IntegratedSort<T>::merge(std::vector<T> &arr, int lo, int mid, int hi, auto cmp) {
    // auxiliary array
    std::vector<T> aux(hi - lo + 1);
    int i = lo, j = mid + 1; // index at arr array
    int k = 0; // index at aux array

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

    std::copy(aux.begin(), aux.end(), arr.begin()+lo);
}
