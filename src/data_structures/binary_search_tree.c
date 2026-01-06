#include "binary_search_tree.h"

typedef int (*BSTCompare)(const void*, const void*);

struct BSTNode {
   void* elem;
   struct BSTNode* left;
   struct BSTNode* right;
};

struct BinarySearchTree {
   BSTNode* root;
   size_t elem_size;
   BSTCompare cmp;
};
