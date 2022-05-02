#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELETED ((void *)(1))

typedef struct KeyValuePair {
    char *key;
    char *value;
} Obj;

typedef struct HashTable {
    int m;
    int n;
    Obj **arr;
} Table;

Table *initTable(int m);

int getASCIIValueFromKey(char *key);

int hash(char *key, int m);

int hashOfKey(Table *table, char *key);

bool exists(Table *table, char *key);

Table *add(Table *table, char *key, char *value);

Obj *get(Table *table, char *key);

void removeKey(Table *table, char *key);

Table *rehash(Table *table);