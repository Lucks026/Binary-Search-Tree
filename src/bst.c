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
    // duplicates ignored
    return root;
}
