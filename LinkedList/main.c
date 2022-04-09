#include "implement.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printList(node *head) {
    node *temp = head;
    puts("List is: ");
    while (temp != NULL) {
        printf("%d ", *(int *)temp->data);
        temp = temp->next;
    }
    puts("\n");
}

void printOddNodes(node *head, bool isOdd) {
    if (isOdd) {
        printf("%d ", *(int *)head->data);
    }

    if (head == NULL) {
        return;
    }

    printOddNodes(head->next, !isOdd);
}

int main() {
    node *head = NULL;

    int a = 101;
    int b = 102;
    int c = 103;
    int d = 104;

    push(&head, &a, sizeof(int));
    push(&head, &b, sizeof(int));
    push(&head, &c, sizeof(int));
    push(&head, &d, sizeof(int));
    printf("Address is: %d\n", head);
    printf("After 4 push, size is: %d\n", sizeOfList(head));
    printOddNodes(head, true);

    return 0;
}
