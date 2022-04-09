#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BinaryMaxHeap {
    int *arr;
    int capacity;
    int size;
} MaxHeap;

MaxHeap *initHeap(int capacity);

// Utilities
void printHeap(MaxHeap *heap);
void swapArrIntegers(int *a, int *b);

// Method to find node in heap
int parent(int i);
int left(int i);
int right(int i);
int lastNonLeafIndex(int size);

/*
    Fix one violation in the heap, assuming all the sub tree
    of fixing node are max heaps

    siftUp and siftDown are also known as "heapify"
*/
void siftUp(int *arr, int nodeIndex);
void siftDown(int *arr, int size, int nodeIndex);
void insert(MaxHeap *heap, int node);
int getMax(MaxHeap *heap);

// Swap root with last leaf node and delete that node, then sift down root
int extractMax(MaxHeap *heap);

// Change priority of node using siftUp and siftDown
void changePriority(MaxHeap *heap, int index, int value);

// Change priority of deleting node to infinity, then extract max
void removeNode(MaxHeap *heap, int index);

// Heap sort
void buildMaxHeap(MaxHeap *heap);
void heapSort(MaxHeap *heap);