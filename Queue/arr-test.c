#include "arr-impl.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void printQueue(int *queue) {
    puts("Printing queue...");

    if (isEmptyQueue()) {
        puts("Queue is empty.");
        puts("Stop printing.");
        return;
    }

    int counter = front;
    while (counter <= rear) {
        printf("Node at index %d is %d\n", counter, queue[counter]);
        counter = (counter + 1) % MAX_SIZE;
    }
    puts("Stop printing.");
}

int main() {
    int Q[MAX_SIZE];

    enqueue(Q, 11);
    enqueue(Q, 12);
    enqueue(Q, 13);
    enqueue(Q, 14);
    enqueue(Q, 15);

    printQueue(Q);

    dequeue();
    dequeue();

    printQueue(Q);
}