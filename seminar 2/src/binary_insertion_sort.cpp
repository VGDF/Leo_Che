#include "binary_insertion_sort.h"

template <typename T>
int binarySearch(T arr[], T key, int left, int right) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] > key)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return left;
}

template <typename T>
void binaryInsertionSort(T arr[], int size) {
    for (int i = 1; i < size; ++i) {
        T key = arr[i];
        int j = i - 1;
        int pos = binarySearch(arr, key, 0, j);

        while (j >= pos) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[pos] = key;
    }
}

template void binaryInsertionSort<int>(int[], int);
template void binaryInsertionSort<double>(double[], int);
