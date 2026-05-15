#include <stdio.h>
#include <assert.h>
#include "bst.h"

static int passed = 0;
static int failed = 0;

#define CHECK(cond, msg) do { \
    if (cond) { printf("  [PASS] %s\n", msg); passed++; } \
    else       { printf("  [FAIL] %s\n", msg); failed++; } \
} while (0)

static void test_insert_search(void) {
    printf("--- insert / search ---\n");
    Node *root = NULL;
    root = bst_insert(root, 50);
    root = bst_insert(root, 30);
    root = bst_insert(root, 70);
    root = bst_insert(root, 50);

    CHECK(bst_contains(root, 50), "contains 50");
    CHECK(bst_contains(root, 30), "contains 30");
    CHECK(bst_contains(root, 70), "contains 70");
    CHECK(!bst_contains(root, 99), "not contains 99");
    CHECK(bst_count(root) == 3, "no duplicate inserted");

    bst_free(root);
}

static void test_remove(void) {
    printf("--- remove ---\n");
    Node *root = NULL;
    int vals[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++)
        root = bst_insert(root, vals[i]);

    root = bst_remove(root, 20);
    CHECK(!bst_contains(root, 20), "leaf 20 removed");

    root = bst_remove(root, 30);
    CHECK(!bst_contains(root, 30), "one-child 30 removed");
    CHECK(bst_contains(root, 40),  "child 40 still present");

    root = bst_remove(root, 70);
    CHECK(!bst_contains(root, 70), "two-children 70 removed");
    CHECK(bst_contains(root, 60),  "60 still present");
    CHECK(bst_contains(root, 80),  "80 still present");

    int before = bst_count(root);
    root = bst_remove(root, 999);
    CHECK(bst_count(root) == before, "remove nonexistent keeps count");

    bst_free(root);
}

int main(void) {
    printf("=== BST test suite ===\n\n");
    test_insert_search();
    test_remove();
    printf("\n%d passed, %d failed\n", passed, failed);
    return failed > 0 ? 1 : 0;
}
