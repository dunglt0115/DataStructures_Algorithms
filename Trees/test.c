#include "impl.h"
#include <stdio.h>
#include <string.h>

int main() {
    bstNode *root = NULL;

    /*
             8
         /      \
        3       10
      /  \      /
     1    6    9
         /
        4
    */
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 4);
    root = insert(root, 9);

    // inorderTraversal(root);
    // printf("\n");

    bstNode *node = findInorderSuccessor(root, 3);
    // printf("%d\n", node->data);
    printf("%d", node->data);

    // root = deleteNode(root, 4);
    // inorderTraversal(root);

    // root = deleteNode(root, 3);
    // inorderTraversal(root);

    // root = deleteNode(root, 9);
    // inorderTraversal(root);

    // root = deleteNode(root, 8);
    // inorderTraversal(root);
}