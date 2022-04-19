#include "impl.h"

void initArrayValue(int *arr) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = i;
    }
}

void initSizeValue(int *size) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        size[i] = 1;
    }
}

// Quick-find
bool qfFind(int *arr, int p, int q) { return arr[p] == arr[q]; }

void qfUnion(int *arr, int p, int q) {
    int src = arr[p];
    int des = arr[q];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (arr[i] == src) {
            arr[i] = des;
        }
    }
}

// Quick-union
int quRoot(int *arr, int i) {
    while (i != arr[i]) {
        i = arr[i];
    }
    return i;
}

bool quFind(int *arr, int p, int q) {
    return quRoot(arr, arr[p]) == quRoot(arr, arr[q]);
}

void quUnion(int *arr, int p, int q) {
    int pRoot = quRoot(arr, p);
    int qRoot = quRoot(arr, q);
    arr[pRoot] = qRoot;
}

// Weighted Quick-union with Path Compression
int wqupcRoot(int *arr, int i) {
    while (i != arr[i]) {
        arr[i] = arr[arr[i]];
        i = arr[i];
    }
    return i;
}

bool wqupcFind(int *arr, int p, int q) {
    return wqupcRoot(arr, arr[p]) == wqupcRoot(arr, arr[q]);
}

void wqupcUnion(int *arr, int *size, int p, int q) {
    int pRoot = wqupcRoot(arr, p);
    int qRoot = wqupcRoot(arr, q);

    if (qRoot == pRoot)
        return;

    if (size[pRoot] < size[qRoot]) {
        arr[pRoot] = qRoot;
        size[qRoot] += size[pRoot];
        return;
    }

    if (size[pRoot] >= size[qRoot]) {
        arr[qRoot] = pRoot;
        size[pRoot] += qRoot;
    }
}