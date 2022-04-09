#include <stdbool.h>

typedef struct SinglyLinkedList {
    void *data;
    struct Node *next;
} node;

void push(node **head, void *data, int sizeOfData);
void pop(node **head);
void insert(node **head, void *data, int sizeOfData, int index);
void deleteNode(node **head, int index);
void deleteNodeRecursive(node **head, int index, int counter);
bool isEmpty(node *head);
int sizeOfList(node *head);
void *get(node *head, int index);
void recursiveReverse(node **head, node **newHead);
void iterativeReverse(node **head);
void deleteList(node **head);