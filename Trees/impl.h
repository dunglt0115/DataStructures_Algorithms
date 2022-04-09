#include "queue.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BinarySearchTree {
    int data;
    struct BinarySearchTree *left;
    struct BinarySearchTree *right;
} bstNode;

bstNode *createNode(int data) {
    bstNode *node = (bstNode *)malloc(sizeof(bstNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

bool isEmptyTree(bstNode *root) { return root == NULL; }

bstNode *insert(bstNode *root, int data) {
    if (isEmptyTree(root)) {
        root = createNode(data);
    } else if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}

bstNode *getNode(bstNode *root, int data) {
    if (root == NULL || data == root->data) {
        return root;
    }
    if (data < root->data) {
        return getNode(root->left, data);
    }
    return getNode(root->right, data);
}

bstNode *getMin(bstNode *root) {
    if (isEmptyTree(root) || root->left == NULL) {
        return root;
    }
    return getMin(root->left);
}

bstNode *getMax(bstNode *root) {
    if (isEmptyTree(root) || root->right == NULL) {
        return root;
    }
    return getMax(root->right);
}

int heightOfTree(bstNode *root) {
    if (isEmptyTree(root)) {
        return -1;
    }

    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

void levelorderTraversal(bstNode *root) {
    if (isEmptyTree(root)) {
        puts("Can not traverse the tree, since tree is empty.");
        return;
    }

    qNode *head = NULL;
    qNode *tail = NULL;
    enqueue(&head, &tail, root, sizeof(bstNode));

    puts("Level-order traversing...");

    while (!isEmptyQueue(head)) {
        bstNode *current = (bstNode *)rear(tail);
        printf("%d ", current->data);

        if (current->left != NULL) {
            enqueue(&head, &tail, current->left, sizeof(bstNode));
        }

        if (current->right != NULL) {
            enqueue(&head, &tail, current->right, sizeof(bstNode));
        }

        dequeue(head, &tail);
    }
}

void preorderTraversal(bstNode *root) {
    if (isEmptyTree(root)) {
        return;
    }
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(bstNode *root) {
    if (isEmptyTree(root)) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void postorderTraversal(bstNode *root) {
    if (isEmptyTree(root)) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

bool bstUtil(bstNode *root, int min, int max) {
    if (isEmptyTree(root)) {
        return true;
    }
    if (root->data > min && root->data < max &&
        bstUtil(root->left, min, root->data) &&
        bstUtil(root->right, root->data, max)) {
        return true;
    }
    return false;
}

bool isBinarySeachTree(bstNode *root) {
    return bstUtil(root, INT_MIN, INT_MAX);
}

void bstUtil2(bstNode *root, qNode **head, qNode **tail) {
    if (isEmptyTree(root)) {
        return;
    }
    bstUtil2(root->left, &*head, &*tail);
    enqueue(&*head, &*tail, root, sizeof(bstNode));
    bstUtil2(root->right, &*head, &*tail);
}

bool isBinarySearchTree2(bstNode *root) {
    qNode *head = NULL;
    qNode *tail = NULL;
    bstUtil2(root, &head, &tail);
    bool res;

    qNode *current = head;

    while (current->next != NULL) {
        bstNode *node1 = (bstNode *)current->data;
        bstNode *node2 = (bstNode *)current->next->data;

        if (node1->data >= node2->data) {
            res = true;
        } else {
            res = false;
            break;
        }

        current = current->next;
    }

    return res;
}

bstNode *deleteNode(bstNode *root, int data) {
    if (isEmptyTree(root)) {
        return root;
    } else if (data < root->data) { // Finding node from left subtree
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) { // Finding node from right subtree
        root->right = deleteNode(root->right, data);
    } else { // Found, start to delete
        if (root->left == NULL &&
            root->right == NULL) { // Case 1: Node has no child
            free(root);
            root = NULL;
        } else if (root->left ==
                   NULL) { // Case 2: Node has one child to the right
            bstNode *temp = root;
            root = root->right;
            free(temp);
        } else if (root->right ==
                   NULL) { // Case 2: Node has one child to the left
            bstNode *temp = root;
            root = root->left;
            free(temp);
        } else { // Case 3: Node has 2 children
            bstNode *temp = getMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

bstNode *findInorderSuccessor(bstNode *root, int data) {
    bstNode *current = getNode(root, data);
    if (current == NULL)
        return NULL;

    // Node has right subtree
    if (current->right != NULL) {
        return getMin(current->right);
    }

    // Node has no right subtree
    bstNode *successor, *ancestor = root;

    while (ancestor != current) {
        if (current->data <= ancestor->data) {
            successor = ancestor;
            ancestor = ancestor->left;
            continue;
        }
        ancestor = ancestor->right;
    }

    return successor;
}