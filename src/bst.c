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
