#include <stdio.h>
#include <string.h>

/**
 * @brief Given a string calculate length of the string using recursion.
 * Examples:
 * - Input: "abcd"
 * - Output: 4
 * @return int
 */
int lengthOfStr(char *str) {
    if (*str == '\0') {
        return 0;
    }
    return 1 + lengthOfStr(str + 1);
}

/**
 * @brief Given a string find its first uppercase letter.
 * Examples:
 * - Input: "geeksforgeeKs"
 * - Output: K
 * @return char
 */
char firstUppercaseOfStr(char *str) {
    if (*str == '\0') {
        return 0;
    }
    if (*str >= 65 && *str <= 90) {
        return *str;
    }
    return firstUppercaseOfStr(str + 1);
}

/**
 * @brief Given a string find its first uppercase letter.
 * Examples:
 * - Input: s1 "hello" s2 "world"
 * - Output: s1 "world"
 */
void copyStr(char *str1, char *str2) {
    *str1 = *str2;
    if (*str2 == '\0') {
        return;
    }
    copyStr(str1 + 1, str2 + 1);
}

/**
 * @brief Given an array, write functions to find the minimum and maximum
 * elements in it.
 * @return int
 */
int minOf(int *A, int size, int res) {
    if (res > *A) {
        res = *A;
    }

    if (size == 1) {
        return res;
    }

    return minOf(A + 1, size - 1, res);
}

int main() {
    int a[5] = {13, 225, 3, 34, 5};

    printf("Result is: %d", minOf(a, sizeof(a) / sizeof(int), a[0]));
}