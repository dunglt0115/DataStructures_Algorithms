#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue {
    void *data;
    struct Queue *next;
} node;

bool isEmptyQueue(node *head) { return head == NULL; }

node *createNode(void *data, int dataSize) {
    node *temp = (node *)malloc(sizeof(node));
    temp->data = malloc(dataSize);
    memmove((char *)temp->data, (char *)data, dataSize);
    temp->next = NULL;
    return temp;
}

// Push in from head
void enqueue(node **head, node **tail, void *data, int dataSize) {
    node *temp = createNode(data, dataSize);
    if (isEmptyQueue(*head)) {
        *head = *tail = temp;
        return;
    }
    temp->next = *head;
    *head = temp;
}

// Pop out from tail
void dequeue(node *head, node **tail) {
    if (isEmptyQueue(head)) {
        puts("Can not dequeue, since queue is empty.");
        return;
    }
    node *current, *next = head;
    while (next->next != NULL) {
        current = next;
        next = next->next;
    }
    current->next = NULL;
    *tail = current;
    free(next);
}

void *front(node *head) {
    if (isEmptyQueue(head)) {
        puts("Can not get data from head node, since queue is empty.");
        return NULL;
    }
    return head->data;
}

void *rear(node *tail) {
    if (isEmptyQueue(tail)) {
        puts("Can not get data from tail node, since queue is empty.");
        return NULL;
    }
    return tail->data;
}
