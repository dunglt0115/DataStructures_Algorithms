#include <math.h>
#include <stdio.h>

int binarySearchVer1(int *arr, int arrSize, int n) {
  int min = 0;
  int max = arrSize - 1;
  float index;
  int i;

  while (arr[i] != n) {
    index = (min + max) / 2;
    i = lround(index);

    if (arr[i] > n) {
      max = i - 1;
      continue;
    }

    if (arr[i] < n) {
      min = i + 1;
      continue;
    }
  }

  return i;
}

int binarySearchVer2(int *arr, int firstIndex, int lastIndex, int n, int i) {
  if (arr[i] == n) {
    return i;
  }

  if (arr[i] > n) {
    lastIndex = i - 1;
  } else if (arr[i] < n) {
    firstIndex = i + 1;
  }

  return binarySearchVer2(arr, firstIndex, lastIndex, n,
                          lround((firstIndex + lastIndex) / 2));
}

int main() {
  int A[] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
             43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

  printf("Number %d is at index %d", 19,
         binarySearchVer2(A, 0, (sizeof(A) / sizeof(int)) - 1, 19,
                          lround(((sizeof(A) / sizeof(int)) - 1) / 2)));

  return 0;
}