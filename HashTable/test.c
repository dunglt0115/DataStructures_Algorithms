#include "linearProbing.c"

int main() {
    Table *table = initTable(8);

    table = add(table, "test", "Hello");
    table = add(table, "tset", "world");
    table = add(table, "estt", "war");
    table = add(table, "basd", "friend");
    table = add(table, "rthrh", "kitchen");
    table = add(table, "tynr", "chicken");

    for (int i = 0; i < table->m; i++) {
        if (table->arr[i] == NULL) {
            printf("At index %d: %s\n", i, "Null");
            continue;
        }

        if (table->arr[i] == DELETED) {
            printf("At index %d: %s\n", i, "Deleted");
            continue;
        }

        printf("At index %d, key: %s, value: %s\n", i, table->arr[i]->key,
               table->arr[i]->value);
    }
}