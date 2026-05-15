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

void bst_inorder(Node *root) {
    if (root == NULL) return;
    bst_inorder(root->left);
    printf("%d ", root->data);
    bst_inorder(root->right);
}

void bst_preorder(Node *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    bst_preorder(root->left);
    bst_preorder(root->right);
}

void bst_postorder(Node *root) {
    if (root == NULL) return;
    bst_postorder(root->left);
    bst_postorder(root->right);
    printf("%d ", root->data);
}

Node *bst_remove(Node *root, int value) {
    if (root == NULL) return NULL;
    if (value < root->data) {
        root->left = bst_remove(root->left, value);
    } else if (value > root->data) {
        root->right = bst_remove(root->right, value);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        if (root->left == NULL) {
            Node *tmp = root->right;
            free(root);
            return tmp;
        }
        if (root->right == NULL) {
            Node *tmp = root->left;
            free(root);
            return tmp;
        }
        // substitui pelo menor da subárvore direita
        Node *successor = bst_min(root->right);
        root->data  = successor->data;
        root->right = bst_remove(root->right, successor->data);
    }
    return root;
}

int bst_height(Node *root) {
    if (root == NULL) return -1;
    int l = bst_height(root->left);
    int r = bst_height(root->right);
    return 1 + (l > r ? l : r);
}

int bst_count(Node *root) {
    if (root == NULL) return 0;
    return 1 + bst_count(root->left) + bst_count(root->right);
}

void bst_print_tree(Node *root, int level) {
    if (root == NULL) return;
    bst_print_tree(root->right, level + 1);
    for (int i = 0; i < level; i++) printf("    ");
    printf("%d\n", root->data);
    bst_print_tree(root->left, level + 1);
}

void bst_free(Node *root) {
    if (root == NULL) return;
    bst_free(root->left);
    bst_free(root->right);
    free(root);
}

int bst_is_leaf(Node *node) {
    return node != NULL && node->left == NULL && node->right == NULL;
}
