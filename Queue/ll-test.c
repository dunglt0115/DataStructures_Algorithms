#include "ll-impl.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void printQueue(node *head) {
    puts("Printing queue...");

    if (isEmptyQueue(head)) {
        puts("Queue is empty.");
        puts("Stop printing.");
        return;
    }

    node *temp = head;

    while (temp != NULL) {
        printf("%d ", *(int *)temp->data);
        temp = temp->next;
    }
    puts("\nStop printing.");
}

void printHead(node *head) {
    int *data = (int *)front(head);

    if (data == NULL) {
        return;
    }

    printf("Head node data is: %d\n", *data);
}

void printTail(node *tail) {
    int *data = (int *)rear(tail);

    if (data == NULL) {
        return;
    }

    printf("Tail node data is: %d\n", *data);
}

int main() {
    node *head = NULL;
    node *tail = NULL;

    int a = 11, b = 12, c = 13, d = 14, e = 15;

    enqueue(&head, &tail, &a, sizeof(int));
    // enqueue(&head, &tail, &b, sizeof(int));
    // enqueue(&head, &tail, &c, sizeof(int));
    // enqueue(&head, &tail, &d, sizeof(int));
    // enqueue(&head, &tail, &e, sizeof(int));

    printQueue(head);
    printHead(head);
    printTail(tail);

    // dequeue(head, &tail);
    // dequeue(head, &tail);

    // printQueue(head);
    // printHead(head);
    // printTail(tail);
}