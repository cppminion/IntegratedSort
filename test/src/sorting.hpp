#ifndef SORTCOMP_SORTING_HPP
#define SORTCOMP_SORTING_HPP
#include <vector>

int KEY_COMPS;

void insertion_sort(std::vector<int> &arr) {
    for (int i = 1; i < arr.size(); ++i) {
        int j = i;
        while (j > 0 && (arr[j] < arr[j - 1])) {
            ++KEY_COMPS;
            std::swap(arr[j - 1], arr[j]);
            j--;
        }
    }
}

void merge(std::vector<int> &arr, int lo, int mid, int hi) {
    std::vector<int> aux(hi - lo + 1);
    int i = lo, j = mid + 1; // index at arr array
    int k = 0;               // index at aux array

    while (i <= mid && j <= hi) {
        ++KEY_COMPS;
        if ((arr[i] < arr[j]))
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

void integrated_sort(std::vector<int> &arr, int lo, int hi, int S) {
    if (lo >= hi)
        return ;

    if (arr.size() < S) {
        insertion_sort(arr);
    } else {
        int mid = (lo + hi) / 2;
        integrated_sort(arr, lo, mid, S);
        integrated_sort(arr, mid+1, hi, S);
        merge(arr, lo, mid, hi);
    }
}

void integrated_sort(std::vector<int> &arr, int S) {
    integrated_sort(arr, 0, arr.size()-1, S);
}

#endif //SORTCOMP_SORTING_HPP
