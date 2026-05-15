#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

static void flush_stdin(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
    Node *root = NULL;
    int seed[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++)
        root = bst_insert(root, seed[i]);

    int choice, value;
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
                scanf("%d", &value);
                root = bst_insert(root, value);
                break;
            case 2:
                printf("Value: ");
                scanf("%d", &value);
                printf(bst_contains(root, value) ? "Found\n" : "Not found\n");
                break;
            case 3:
                printf("Value: ");
                scanf("%d", &value);
                root = bst_remove(root, value);
                break;
            case 4: bst_inorder(root);   printf("\n"); break;
            case 5: bst_preorder(root);  printf("\n"); break;
            case 6: bst_postorder(root); printf("\n"); break;
            case 7: bst_print_tree(root, 0); break;
            case 8:
                printf("Nodes : %d\n", bst_count(root));
                printf("Height: %d\n", bst_height(root));
                if (bst_min(root)) printf("Min   : %d\n", bst_min(root)->data);
                if (bst_max(root)) printf("Max   : %d\n", bst_max(root)->data);
                break;
            case 0: break;
            default: printf("Invalid option\n");
        }
    } while (choice != 0);

    bst_free(root);
    return 0;
}
