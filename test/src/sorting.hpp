#ifndef SORTCOMP_SORTING_HPP
#define SORTCOMP_SORTING_HPP
#include <vector>

long long KEY_COMPS;
namespace SORTING {
std::vector<int> arr, aux;
int S;
void insertion_sort(int lo, int hi) {
    for (int i = lo + 1; i <= hi; ++i) {
        int j = i;
        while (j > 0 && (arr[j] < arr[j - 1])) {
            ++KEY_COMPS;
            std::swap(arr[j - 1], arr[j]);
            j--;
        }
        ++KEY_COMPS;
    }
}

void merge(int lo, int mid, int hi) {
    int i = lo, j = mid + 1; // index at arr array
    int k = 0;               // index at aux array

    while (i <= mid && j <= hi) {
        ++KEY_COMPS;
        if ((arr[i] < arr[j]))
            aux[k++] = arr[i++];
        else
            aux[k++] = arr[j++];
    }
    while (i <= mid) {
        aux[k++] = arr[i++];
    }
    while (j <= hi) {
        aux[k++] = arr[j++];
    }
    for (int i = lo; i <= hi; ++i) {
        arr[i] = aux[i - lo];
    }
}

void integrated_sort(int lo, int hi) {
    if (lo >= hi)
        return;

    if (hi - lo < S) {
        insertion_sort(lo, hi);
    } else {
        int mid = (lo + hi) / 2;
        integrated_sort(lo, mid);
        integrated_sort(mid + 1, hi);
        merge(lo, mid, hi);
    }
}

void integrated_sort(std::vector<int> &tmp, int S) {
    swap(tmp, arr);
    aux.resize(arr.size());
    integrated_sort(0, arr.size() - 1);
    swap(tmp, arr);
}
} // namespace SORTING
#endif // SORTCOMP_SORTING_HPP
