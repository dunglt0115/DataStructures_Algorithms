#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int ARRAY_SIZE = 101;

void initArrayValue(int *arr);
void initSizeValue(int *size);

// Quick-find
bool qfFind(int *arr, int p, int q);
void qfUnion(int *arr, int p, int q);

// Quick-union
int quRoot(int *arr, int i);
bool quFind(int *arr, int p, int q);
void quUnion(int *arr, int p, int q);

// Weighted Quick-union with Path Compression
int wqupcRoot(int *arr, int i);
bool wqupcFind(int *arr, int p, int q);
void wqupcUnion(int *arr, int *size, int p, int q);