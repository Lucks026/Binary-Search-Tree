#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

Node *bst_insert(Node *root, int value) {
    if (root == NULL) {
        Node *node = malloc(sizeof(Node));
        if (!node) return NULL;
        node->data  = value;
        node->left  = NULL;
        node->right = NULL;
        return node;
    }
    if (value < root->data)
        root->left = bst_insert(root->left, value);
    else if (value > root->data)
        root->right = bst_insert(root->right, value);
    return root;
}

Node *bst_search(Node *root, int value) {
    if (root == NULL || root->data == value)
        return root;
    if (value < root->data)
        return bst_search(root->left, value);
    return bst_search(root->right, value);
}

int bst_contains(Node *root, int value) {
    return bst_search(root, value) != NULL;
}

Node *bst_min(Node *root) {
    if (root == NULL) return NULL;
    while (root->left)
        root = root->left;
    return root;
}

Node *bst_max(Node *root) {
    if (root == NULL) return NULL;
    while (root->right)
        root = root->right;
    return root;
}
