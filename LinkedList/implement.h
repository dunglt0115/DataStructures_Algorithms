#include "base.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isEmpty(node *head) { return head == NULL; }

int sizeOfList(node *head) {
    if (isEmpty(head)) {
        return 0;
    }

    int counter = 1;

    node *temp = head;

    while (temp->next != NULL) {
        counter++;
        temp = temp->next;
    }

    return counter;
}

void push(node **head, void *data, int sizeOfData) {
    node *node1 = (node *)malloc(sizeof(node));
    node1->data = malloc(sizeOfData);
    memmove((char *)node1->data, (char *)data, sizeOfData);
    node1->next = NULL;

    if (isEmpty(*head)) {
        node1->next = *head;
        *head = node1;
        return;
    }

    node *node2 = *head;
    while (node2->next != NULL) {
        node2 = node2->next;
    }
    node2->next = node1;
}

void pop(node **head) {
    if (isEmpty(*head)) {
        puts("Can not pop since list is empty");
        return;
    }

    if (sizeOfList(*head) == 1) {
        free(*head);
        *head = NULL;
        return;
    }

    node *first, *middle, *next;
    middle = *head;

    while (middle->next != NULL) {
        next = middle->next;
        if (middle != next) {
            first = middle;
        }
        middle = next;
    }
    first->next = NULL;
    free(middle);
}

void insert(node **head, void *data, int sizeOfData, int index) {
    if (isEmpty(*head) && index != 1) {
        printf("Can not insert to node %d since list is empty", index);
        return;
    }

    if (index < 1) {
        puts("Index must be greater than or equal to 1");
        return;
    }

    if (sizeOfList(*head) < index - 1) {
        printf("Can not insert node at index %d. This index is out of bounds",
               index);
        return;
    }

    node *node1 = (node *)malloc(sizeof(node));
    node1->data = malloc(sizeOfData);
    memmove((char *)node1->data, (char *)data, sizeOfData);

    if (isEmpty(*head) && index == 1) {
        node1->next = *head;
        *head = node1;
        return;
    }

    if (!isEmpty(*head) && index == 1) {
        node1->next = *head;
        *head = node1;
        return;
    }

    node *node2 = *head;

    for (int i = 1; i < index - 1; i++) {
        node2 = node2->next;
    }

    node1->next = node2->next;
    node2->next = node1;
}

void deleteNode(node **head, int index) {
    if (isEmpty(*head)) {
        puts("Can not delete since list is empty");
        return;
    }

    if (index < 1) {
        puts("Index must be greater than or equal to 1");
        return;
    }

    if (sizeOfList(*head) < index) {
        printf("Can not delete node at index %d. This index is out of bounds",
               index);
        return;
    }

    node *current = *head;
    node *next;

    if (index == 1) {
        next = current->next;
        *head = next;
        free(current);
        return;
    }

    for (int i = 1; i < index - 1; i++) {
        current = current->next;
    }

    next = current->next;
    current->next = next->next;
    free(next);
}

void deleteNodeRecursive(node **head, int index, int counter) {
    node *current = *head;
    node *next;

    if (index == 1) {
        next = current->next;
        *head = next;
        free(current);
        return;
    }

    if (counter == index - 1) {
        next = current->next;
        current->next = next->next;
        free(next);
        return;
    }

    deleteNodeRecursive(&(*head)->next, index, ++counter);
}

void *get(node *head, int index) {
    if (isEmpty(head)) {
        puts("Can not get node data since list is empty");
        return NULL;
    }

    if (index < 1) {
        puts("Index must be greater than or equal to 1");
        return NULL;
    }

    if (sizeOfList(head) < index) {
        printf("Can not get node data at index %d. This index is out of bounds",
               index);
        return NULL;
    }

    node *node = head;

    for (int i = 1; i < index - 1; i++) {
        node = node->next;
    }

    return node->data;
}

void recursiveReverse(node **head, node **newHead) {
    // Exit condition for recursive call
    if ((*head)->next == NULL) {
        *newHead = *head;
        return;
    }

    recursiveReverse(&(*head)->next, &*newHead);

    node *temp = (*head)->next;
    temp->next = *head;
    (*head)->next = NULL;
}

void iterativeReverse(node **head) {
    node *current, *prev, *next;
    current = *head;
    prev = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

void deleteList(node **head) {
    if (isEmpty(*head)) {
        puts("Can not delete list since it is already been empty");
        return;
    }

    node *current = *head;

    if (sizeOfList(*head) == 1) {
        free(current);
        *head = NULL;
        return;
    }

    *head = current->next;
    free(current);

    deleteList(&(*head));
}