#include "quick_sort.h"

template <typename T>
int partition(T arr[], int left, int right) {
    T pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            T temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    T temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;

    return i + 1;
}

template <typename T>
void quickSort(T arr[], int left, int right) {
    if (left < right) {
        int p = partition(arr, left, right);
        quickSort(arr, left, p - 1);
        quickSort(arr, p + 1, right);
    }
}

template <typename T>
void quickSort(T arr[], int size) {
    if (size > 0)
        quickSort(arr, 0, size - 1);
}

template void quickSort<int>(int[], int);
template void quickSort<double>(double[], int);
