#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_SIZE = 101;
int front = -1;
int rear = -1;

bool isEmptyQueue() { return front == -1 && rear == -1; }

bool isFull() { return (rear + 1) % MAX_SIZE == front; }

void enqueue(int *queue, int data) {
    if (isFull()) {
        puts("Can not enqueue, since queue is full.");
        return;
    }

    if (isEmptyQueue()) {
        front = rear = 0;
        queue[rear] = data;
        return;
    }

    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = data;
}

void dequeue() {
    if (isEmptyQueue()) {
        puts("Can not dequeue, since queue is empty.");
        return;
    }

    if (front == 0 && rear == 0) {
        front = rear = -1;
        return;
    }

    front = (front + 1) % MAX_SIZE;
}
