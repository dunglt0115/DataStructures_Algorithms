#include "impl.h"

void swap(int *arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

bool less(int a, int b) { return a < b; }

// Elementary sort
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

void bubbleSort(int *arr, int size) {
    for (int i = 1; i <= size - 1; i++) {
        bool flag = false;

        for (int j = 0; j <= size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr, j, j + 1);
                flag = true;
            }
        }

        if (!flag) {
            break;
        }
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

// Shuffle sort
void KnuthShuffle(int *arr, int size) {
    srand(time(NULL));

    // Start from the last element and swap one by one. Don't
    // need to run for the first element that's why i > 0
    for (int i = size - 1; i > 0; i--) {
        // Pick a random index from 0 to i
        int j = rand() % (i + 1);
        swap(arr, i, j);
    }
}

// Merge sort
void merge(int *A, int *L, int *R, int nL, int nR) {
    int k = 0, i = 0, j = 0;

    while (i < nL && j < nR) {
        if (L[i] <= R[j]) { // <= for stable sort
            A[k++] = L[i++];
            continue;
        }

        if (L[i] > R[j]) {
            A[k++] = R[j++];
        }
    }

    while (i < nL) {
        A[k++] = L[i++];
    }

    while (j < nR) {
        A[k++] = R[j++];
    }
}

void mergeSort(int *A, int n) {
    if (n < 2) {
        return;
    }

    int mid = n / 2;
    int L[mid], R[n - mid];

    for (int i = 0; i < mid; i++) {
        L[i] = A[i];
    }

    for (int i = mid; i < n; i++) {
        R[i - mid] = A[i];
    }

    mergeSort(L, mid);
    mergeSort(R, n - mid);
    merge(A, L, R, mid, n - mid);
}

// Quick sort
int partition(int *A, int start, int end) {
    int pivot = A[end];
    // i and partitionIndex must equal to start, not 0, since
    // this segment of array can start from somewhere in the middle
    int partitionIndex = start;
    for (int i = start; i < end; i++) {
        if (A[i] <= pivot) {
            swap(A, i, partitionIndex);
            partitionIndex++;
        }
    }
    swap(A, partitionIndex, end);
    return partitionIndex;
}

int randomizePartition(int *A, int start, int end) {
    // diff is distance between end and start
    // plus 1 because we must include start to the range
    int diff = end - start + 1;
    // The formula to random between range
    int randomPartitionIndex = start + rand() % diff;
    swap(A, randomPartitionIndex, end);
    return partition(A, start, end);
}

void quickSort(int *A, int start, int end) {
    if (start >= end) {
        return;
    }
    int partitionIndex = randomizePartition(A, start, end);
    quickSort(A, start, partitionIndex - 1);
    quickSort(A, partitionIndex + 1, end);
}