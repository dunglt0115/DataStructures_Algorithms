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
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 4);
    root = insert(root, 9);

    inorderTraversal(root);
    printf("\n");

    root = deleteNode(root, 10);
    inorderTraversal(root);

    // root = deleteNode(root, 9);
    // inorderTraversal(root);

    // root = deleteNode(root, 8);
    // inorderTraversal(root);
}