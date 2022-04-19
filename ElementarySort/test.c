#include "impl.c"

int main() {
    int arr[] = {1, 4, 6, 2, 23, 15, 32, 94};
    int size = sizeof(arr) / sizeof(int);
    shellSort(arr, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}