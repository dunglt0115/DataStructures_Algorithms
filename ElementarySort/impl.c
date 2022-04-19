#include "impl.h"

void swap(int *arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

bool less(int a, int b) { return a < b; }

void selectionSort(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        int min = i;

        for (int j = i + 1; j < size; j++) {
            if (less(arr[j], arr[min])) {
                min = j;
            }
        }

        swap(arr, i, min);
    }
}

void insertionSort(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i; j > 0; j--) {
            if (!less(arr[j], arr[j - 1])) {
                break;
            }
            swap(arr, j, j - 1);
        }
    }
}

void shellSort(int *arr, int size) {
    int h = 1;

    // Calculate max h for this array
    while (h < size / 3) {
        h = 3 * h + 1; // 1, 4, 13, 40, 121...
    }

    while (h >= 1) {
        for (int i = h; i < size; i++) {
            for (int j = i; j >= h; j -= h) {
                if (!less(arr[j], arr[j - h])) {
                    break;
                }
                swap(arr, j, j - h);
            }
        }
        h = h / 3;
    }
}

void KnuthShuffle(int *arr, int size) {
    srand(time(NULL));

    // Start from the last element and swap one by one. We don't
    // need to run for the first element that's why i > 0
    for (int i = size - 1; i > 0; i--) {
        // Pick a random index from 0 to i
        int j = rand() % (i + 1);
        swap(arr, i, j);
    }
}