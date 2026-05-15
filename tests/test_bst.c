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
    root = bst_insert(root, 50);  // duplicado

    CHECK(bst_contains(root, 50), "contains 50");
    CHECK(bst_contains(root, 30), "contains 30");
    CHECK(bst_contains(root, 70), "contains 70");
    CHECK(!bst_contains(root, 99), "not contains 99");
    CHECK(bst_count(root) == 3, "no duplicate inserted");

    bst_free(root);
}

int main(void) {
    printf("=== BST test suite ===\n\n");
    test_insert_search();
    printf("\n%d passed, %d failed\n", passed, failed);
    return failed > 0 ? 1 : 0;
}
