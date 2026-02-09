#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <stdlib.h>
#include "utils.h"

typedef struct TreeNode TreeNode;

typedef enum BinarySearchTreeStatus {
    BINARY_SEARCH_TREE_OK = 0,
    BINARY_SEARCH_TREE_ERR_NULL,
    BINARY_SEARCH_TREE_ERR
} BinarySearchTreeStatus;

typedef struct BinarySearchTree BinarySearchTree;

BinarySearchTree* binary_search_tree_create(size_t elem_size, copy_fn copy, destroy_fn destroy, compare_fn compare);
void binary_search_tree_destroy(BinarySearchTree** bst);
BinarySearchTreeStatus binary_search_tree_insert(BinarySearchTree* bst, void* elem);

#endif
