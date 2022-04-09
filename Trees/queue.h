#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue {
    void *data;
    struct Queue *next;
} qNode;

bool isEmptyQueue(qNode *head) { return head == NULL; }

int queueSize(qNode *head) {
    if (isEmptyQueue(head)) {
        return 0;
    }

    int counter = 1;

    qNode *temp = head;

    while (temp->next != NULL) {
        counter++;
        temp = temp->next;
    }

    return counter;
}

qNode *createQNode(void *data, int dataSize) {
    qNode *temp = (qNode *)malloc(sizeof(qNode));
    temp->data = malloc(dataSize);
    memmove((char *)temp->data, (char *)data, dataSize);
    temp->next = NULL;
    return temp;
}

void enqueue(qNode **head, qNode **tail, void *data, int dataSize) {
    qNode *temp = createQNode(data, dataSize);
    if (isEmptyQueue(*head)) {
        *head = *tail = temp;
        return;
    }
    temp->next = *head;
    *head = temp;
}

void dequeue(qNode *head, qNode **tail) {
    if (isEmptyQueue(head)) {
        puts("Can not dequeue, since queue is empty.");
        return;
    }
    qNode *current, *next = head;
    while (next->next != NULL) {
        current = next;
        next = next->next;
    }
    current->next = NULL;
    *tail = current;
    free(next);
}

void *front(qNode *head) {
    if (isEmptyQueue(head)) {
        puts("Can not get data from head node, since queue is empty.");
        return NULL;
    }
    return head->data;
}

void *rear(qNode *tail) {
    if (isEmptyQueue(tail)) {
        puts("Can not get data from tail node, since queue is empty.");
        return NULL;
    }
    return tail->data;
}
