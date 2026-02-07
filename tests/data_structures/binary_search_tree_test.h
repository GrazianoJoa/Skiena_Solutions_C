#pragma once

#include "test.h"
#include "data_structures/binary_search_tree.h"
#include "data_structures/comparators.h"

TEST(t_binary_search_tree_create_destroy) {
  BinarySearchTree* bst = binary_search_tree_create(sizeof(int), NULL, NULL, compare_int);
  ASSERT_TRUE(bst != NULL);

  binary_search_tree_destroy(&bst);
  ASSERT_TRUE(bst == NULL);
}
