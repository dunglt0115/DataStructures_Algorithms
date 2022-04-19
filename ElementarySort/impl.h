#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void swap(int *arr, int a, int b);
bool less(int a, int b);

void selectionSort(int *arr, int size);
void insertionSort(int *arr, int size);
void shellSort(int *arr, int size);
void KnuthShuffle(int *arr, int size);