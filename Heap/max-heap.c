#include "max-heap.h"

MaxHeap *initHeap(int capacity) {
    MaxHeap *heap = (MaxHeap *)malloc(sizeof(MaxHeap));
    heap->arr = (int *)malloc(capacity * sizeof(int));
    heap->capacity = capacity;
    heap->size = 0;
    return heap;
}

void printHeap(MaxHeap *heap) {
    printf("Heap capacity is: %d\n", heap->capacity);
    printf("Heap size is: %d\n", heap->size);
    printf("Max heap array: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

void swapArrIntegers(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

int parent(int i) { return ceil((double)(i - 1) / 2); }

int left(int i) { return 2 * i + 1; }

int right(int i) { return 2 * i + 2; }

int lastNonLeafIndex(int size) { return floor(size / 2 - 1); }

void siftUp(int *arr, int nodeIndex) {
    int parentIndex = parent(nodeIndex);

    if (arr[parentIndex] >= arr[nodeIndex])
        return;

    swapArrIntegers(&arr[parentIndex], &arr[nodeIndex]);
    siftUp(arr, parentIndex);
}

void siftDown(int *arr, int size, int nodeIndex) {
    int i = nodeIndex;
    int l = left(i);
    int r = right(i);

    if (l < size && arr[l] > arr[i]) {
        i = l;
    }

    if (r < size && arr[r] > arr[i]) {
        i = r;
    }

    if (i != nodeIndex) {
        swapArrIntegers(&arr[nodeIndex], &arr[i]);
        siftDown(arr, size, i);
    }
}

void insert(MaxHeap *heap, int node) {
    if (heap->size == heap->capacity)
        return;
    heap->arr[heap->size] = node;
    siftUp(heap->arr, heap->size);
    heap->size++;
}

int getMax(MaxHeap *heap) { return heap->arr[0]; }

int extractMax(MaxHeap *heap) {
    int res = heap->arr[0];

    swapArrIntegers(&heap->arr[0], &heap->arr[--heap->size]);
    siftDown(heap->arr, heap->size, 0);

    return res;
}

void changePriority(MaxHeap *heap, int index, int value) {
    if (index >= heap->size)
        return;
    if (value > heap->arr[parent(index)]) {
        heap->arr[index] = value;
        siftUp(heap->arr, index);
        return;
    }
    if (value < heap->arr[left(index)] || value < heap->arr[right(index)]) {
        heap->arr[index] = value;
        siftDown(heap->arr, heap->size, index);
    }
}

void removeNode(MaxHeap *heap, int index) {
    if (index >= heap->size)
        return;
    changePriority(heap, index, INT_MAX);
    extractMax(heap);
}

void buildMaxHeap(MaxHeap *heap) {
    for (int i = lastNonLeafIndex(heap->size); i >= 0; i--) {
        siftDown(heap->arr, heap->size, i);
    }
}

void heapSort(MaxHeap *heap) {
    buildMaxHeap(heap);
    for (int i = heap->size - 1; i > 0; i--) {
        swapArrIntegers(&heap->arr[0], &heap->arr[i]);
        siftDown(heap->arr, i, 0);
    }
}
