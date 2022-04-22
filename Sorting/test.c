#include "impl.c"

int main() {
    int arr[] = {1, 4, 6, 2, 23, 15, 32, 94};
    // int arr[] = {1, 2, 3, 4, 5, 6};
    // int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    // int arr[] = {4, 33, 21, 87, 45, 33, 21, 0, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    srand(time(NULL));
    quickSort(arr, 0, size - 1);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}