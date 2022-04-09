#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Vector {
    int size;
    int capacity;
    int sizeOfElement;
    void *items;
} vector;

// Vector features
void initVector(vector *v, int capacity, int sizeOfElement);
int sizeOfVector(vector *v);
int capacityOfVector(vector *v);
bool isEmpty(vector *v);
bool isFull(vector *v);
void resize(vector *v, int capacity);
vector *push(vector *v, void *element);
vector *pop(vector *v);
char *getItem(vector *v, int index);

int main() {
    vector *v = (vector *)malloc(sizeof(vector));
    int capacity = 4;
    int sizeOfElement = sizeof(int);

    // Test init
    initVector(v, capacity, sizeOfElement);
    printf("Vector address: %d\n", v);
    printf("Size after init: %d\n", sizeOfVector(v));
    printf("Capacity after init: %d\n", capacityOfVector(v));

    // Test get item after init
    void *item;
    item = getItem(v, 2);

    // Test push
    int sizeOfTestType = sizeof(int);

    int a = 101;
    v = push(v, &a);
    int b = 102;
    v = push(v, &b);

    if (isFull(v)) {
        puts("Vector is full\n");
    } else {
        printf("After 2 push - current size is: %d, current capacity is: %d\n",
               v->size, v->capacity);
    }

    int c = 103;
    v = push(v, &c);
    int d = 104;
    v = push(v, &d);

    for (int i = 0; i < v->size; i++) {
        printf("After 4 push - Item at index %d is %d\n", i,
               *(int *)getItem(v, i));
    }

    if (isFull(v)) {
        puts("After 4 push - Vector is full\n");
    }

    int e = 105;
    v = push(v, &e);

    printf("Test push after expand - Vector address is: %d\n", v);
    printf("Test push after expand - Size is: %d\n", v->size);
    printf("Test push after expand - Capacity is: %d\n", v->capacity);
    for (int i = 0; i < v->size; i++) {
        printf("Test push after expand - Item at index %d is %d\n", i,
               *(int *)getItem(v, i));
    }

    if (!isFull(v)) {
        printf("After 5 push - current size is: %d, current capacity is: %d\n",
               v->size, v->capacity);
    }

    // Test get item after push
    item = getItem(v, -1);
    item = getItem(v, 10);
    item = getItem(v, 2);

    if (item != NULL) {
        printf("Get item at index 2, item is: %d\n", *(int *)item);
    }

    // Test pop
    v = pop(v);
    v = pop(v);
    v = pop(v);
    v = pop(v);

    printf("After 4 pop - current size is: %d, current capacity is: %d\n",
           v->size, v->capacity);

    return 0;
}

void initVector(vector *v, int capacity, int sizeOfElement) {
    v->size = 0;
    v->capacity = capacity;
    v->sizeOfElement = sizeOfElement;
    v->items = calloc(capacity, sizeOfElement);
}

bool isEmpty(vector *v) { return v->size == 0; }

bool isFull(vector *v) { return v->size == v->capacity; }

int sizeOfVector(vector *v) { return v->size; }

int capacityOfVector(vector *v) { return v->capacity; }

void resize(vector *v, int capacity) {
    v->capacity = capacity;
    void *oldArr = v->items;
    void *newArr = calloc(v->capacity, v->sizeOfElement);

    for (int i = 0; i < v->size; i++) {
        char *destination = (char *)newArr + (v->sizeOfElement * i);
        char *source = (char *)oldArr + (v->sizeOfElement * i);
        memmove(destination, source, v->sizeOfElement);
    }

    v->items = newArr;
    free(oldArr);
}

vector *push(vector *v, void *element) {
    if (isFull(v)) {
        resize(v, (v->capacity) * 2);
    }
    memmove((char *)v->items + (v->sizeOfElement * v->size), element,
            v->sizeOfElement);
    v->size++;
    return v;
}

vector *pop(vector *v) {
    int defaultValue = 0;
    if (((v->size) - 1) <= ((v->capacity) / 4)) {
        resize(v, (v->capacity) / 4);
    }
    memmove((char *)v->items + (v->sizeOfElement * v->size), &defaultValue,
            v->sizeOfElement);
    v->size--;
    return v;
}

char *getItem(vector *v, int index) {
    if (isEmpty(v)) {
        puts("Can't get item, since vector is empty\n");
        return NULL;
    }

    if (index < 0) {
        printf("Index %d is out of bounds\n", index);
        return NULL;
    }

    if (index >= (v->capacity)) {
        printf("Index %d is out of bounds\n", index);
        return NULL;
    }

    return (char *)v->items + (v->sizeOfElement * index);
}
