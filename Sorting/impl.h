#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void swap(int *arr, int a, int b);
bool less(int a, int b);

// Elementary sort
void selectionSort(int *arr, int size);
void bubbleSort(int *arr, int size);
void insertionSort(int *arr, int size);
void shellSort(int *arr, int size);

// Shuffle sort
void KnuthShuffle(int *arr, int size);

// Merge sort
void merge(int *A, int *L, int *R, int nL, int nR);
void mergeSort(int *A, int size);

// Quick sort
int partition(int *A, int start, int end);
int randomizePartition(int *A, int start, int end);
void quickSort(int *A, int start, int end);