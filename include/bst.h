#ifndef BST_H
#define BST_H

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *bst_insert(Node *root, int value);
Node *bst_search(Node *root, int value);
int   bst_contains(Node *root, int value);
Node *bst_min(Node *root);
Node *bst_max(Node *root);
Node *bst_remove(Node *root, int value);
int   bst_height(Node *root);
int   bst_count(Node *root);
int   bst_is_leaf(Node *node);
void  bst_inorder(Node *root);
void  bst_preorder(Node *root);
void  bst_postorder(Node *root);
void  bst_print_tree(Node *root, int level);
void  bst_free(Node *root);

#endif
