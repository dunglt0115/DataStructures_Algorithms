#include "impl.c"

int main() {
    int arr[ARRAY_SIZE], size[ARRAY_SIZE];
    initArrayValue(arr);
    initSizeValue(size);

    wqupcUnion(arr, size, 6, 5);
    wqupcUnion(arr, size, 5, 0);
    wqupcUnion(arr, size, 0, 1);
    wqupcUnion(arr, size, 2, 1);
    wqupcUnion(arr, size, 7, 2);
    wqupcUnion(arr, size, 1, 8);
    wqupcUnion(arr, size, 4, 3);
    wqupcUnion(arr, size, 3, 8);
    wqupcUnion(arr, size, 9, 8);

    printf("Node %d and %d: %s\n", 7, 0,
           quFind(arr, arr[7], arr[0]) ? "true" : "false");
}