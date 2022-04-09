#include "implement.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "[ab(c)b}a]";

    printf("%s", isBalancedParentheses(str, sizeof(str) / sizeof(char))
                     ? "true"
                     : "false");
}