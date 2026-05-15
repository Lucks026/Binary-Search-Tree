#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

static void flush_stdin(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

static void print_stats(Node *root) {
    if (root == NULL) {
        printf("(empty tree)\n");
        return;
    }
    Node *mn = bst_min(root);
    Node *mx = bst_max(root);
    printf("Nodes : %d\n", bst_count(root));
    printf("Height: %d\n", bst_height(root));
    if (mn) printf("Min   : %d\n", mn->data);
    if (mx) printf("Max   : %d\n", mx->data);
}

int main(void) {
    Node *root = NULL;
    int seed[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++)
        root = bst_insert(root, seed[i]);

    int choice = -1, value = 0;
    do {
        printf("\n--- BST ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Remove\n");
        printf("4. Inorder\n");
        printf("5. Preorder\n");
        printf("6. Postorder\n");
        printf("7. Print tree\n");
        printf("8. Stats\n");
        printf("0. Exit\n");
        printf("> ");

        if (scanf("%d", &choice) != 1) {
            flush_stdin();
            continue;
        }

        switch (choice) {
            case 1:
                printf("Value: ");
                if (scanf("%d", &value) != 1) { flush_stdin(); break; }
                root = bst_insert(root, value);
                break;
            case 2:
                printf("Value: ");
                if (scanf("%d", &value) != 1) { flush_stdin(); break; }
                printf(bst_contains(root, value) ? "Found\n" : "Not found\n");
                break;
            case 3:
                printf("Value: ");
                if (scanf("%d", &value) != 1) { flush_stdin(); break; }
                root = bst_remove(root, value);
                break;
            case 4: bst_inorder(root);   printf("\n"); break;
            case 5: bst_preorder(root);  printf("\n"); break;
            case 6: bst_postorder(root); printf("\n"); break;
            case 7: bst_print_tree(root, 0); break;
            case 8: print_stats(root); break;
            case 0: break;
            default: printf("Invalid option\n");
        }
    } while (choice != 0);

    bst_free(root);
    return 0;
}
