#include "linearProbing.h"

Table *initTable(int m) {
    Table *table = (Table *)malloc(sizeof(Table));
    table->m = m;
    table->n = 0;
    table->arr = malloc(m * sizeof(Obj));

    for (int i = 0; i < m; i++) {
        table->arr[i] = NULL;
    }

    return table;
}

int getASCIIValueFromKey(char *key) {
    int asciiOfKey = 0;
    for (int i = 0; i < strlen(key); i++) {
        asciiOfKey += key[i];
    }
    return asciiOfKey;
}

int hash(char *key, int size) { return abs(getASCIIValueFromKey(key) % size); }

int hashOfKey(Table *table, char *key) {
    int hashCode = hash(key, table->m);

    int i = 1;

    while (table->arr[hashCode] != NULL) {
        if (table->arr[hashCode] == DELETED ||
            strcmp(table->arr[hashCode]->key, key) != 0) {
            hashCode = (hash(key, table->m) + i) % table->m;
            i++;
            continue;
        }

        if (strcmp(table->arr[hashCode]->key, key) == 0) {
            break;
        }
    }

    return hashCode;
}

bool exists(Table *table, char *key) {
    int hashCode = hashOfKey(table, key);

    if (table->arr[hashCode] == NULL) {
        return false;
    }

    return true;
}

Table *add(Table *table, char *key, char *value) {
    // Symbol tables does not accept null value by convention
    if (value == NULL) {
        return table;
    }

    // Rehash if load factor > 0.5
    if ((float)table->n / (float)table->m > 0.5) {
        table = rehash(table);
    }

    int hashCode = hash(key, table->m);

    // Overwrite existing key
    if (table->arr[hashCode] != NULL && table->arr[hashCode] != DELETED &&
        strcmp(table->arr[hashCode]->key, key) == 0) {
        free(table->arr[hashCode]->value);
        table->arr[hashCode]->value = (char *)malloc(sizeof(value));
        strcpy(table->arr[hashCode]->value, value);
        return table;
    }

    // Add new key and value
    int i = 1;

    while (table->arr[hashCode] != NULL && table->arr[hashCode] != DELETED) {
        hashCode = (hash(key, table->m) + i) % table->m;
        i++;
    }

    table->arr[hashCode] = (Obj *)malloc(sizeof(Obj));

    table->arr[hashCode]->key = (char *)malloc(sizeof(key));
    strcpy(table->arr[hashCode]->key, key);

    table->arr[hashCode]->value = (char *)malloc(sizeof(value));
    strcpy(table->arr[hashCode]->value, value);

    table->n++;

    return table;
}

Obj *get(Table *table, char *key) {
    int hashCode = hashOfKey(table, key);

    if (table->arr[hashCode] == NULL) {
        puts("Can not get key. Key does not exists.");
        return NULL;
    }

    return table->arr[hashCode];
}

void removeKey(Table *table, char *key) {
    int hashCode = hashOfKey(table, key);

    if (table->arr[hashCode] == NULL) {
        puts("Can not remove key. Key does not exists.");
        return;
    }

    free(table->arr[hashCode]->key);
    free(table->arr[hashCode]->value);
    free(table->arr[hashCode]);
    table->arr[hashCode] = DELETED;
    table->n--;
}

Table *rehash(Table *table) {
    Table *newTable = initTable(table->m * 2);

    for (int i = 0; i < table->m; i++) {
        if (table->arr[i] != NULL && table->arr[i] != DELETED) {
            newTable = add(newTable, table->arr[i]->key, table->arr[i]->value);
            free(table->arr[i]->key);
            free(table->arr[i]->value);
            free(table->arr[i]);
        }
    }
    free(table->arr);
    Table *temp = table;
    free(temp);

    return newTable;
}