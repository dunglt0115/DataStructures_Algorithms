#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
char S[MAX_STACK_SIZE];
int top = -1;

bool isEmpty() { return top == -1; }

char getTop() { return S[top]; }

void push(char c) {
    if (top == MAX_STACK_SIZE - 1) {
        puts("Stack is full. Can not push.");
        return;
    }
    S[++top] = c;
}

void pop() {
    if (isEmpty()) {
        puts("Can not pop. Stack is empty");
        return;
    }
    top--;
}

void reverse(char *newS) {
    if (isEmpty()) {
        puts("Can not reverse. Stack is empty");
        return;
    }

    int currentSize = top;

    for (int i = 0; i <= currentSize; i++) {
        newS[i] = getTop();
        pop();
    }
}

bool isPairOfBrackets(char openParenthesis, char closeParenthesis) {
    switch (openParenthesis) {
    case '(':
        if (closeParenthesis == ')')
            return true;
        return false;
        break;

    case '[':
        if (closeParenthesis == ']')
            return true;
        return false;
        break;

    default:
        if (closeParenthesis == '}')
            return true;
        return false;
        break;
    }
}

bool isBalancedParentheses(char *str, int strLen) {
    for (int i = 0; i < strLen; i++) {
        if (str[i] == '{' || str[i] == '[' || str[i] == '(') {
            push(str[i]);
            continue;
        }

        if (str[i] == '}' || str[i] == ']' || str[i] == ')') {
            if (isEmpty() || !isPairOfBrackets(getTop(), str[i])) {
                return false;
            }
            pop();
        }
    }

    if (!isEmpty()) {
        return false;
    }

    return true;
}

int evaluatePrefixExpression(char *expr) {}