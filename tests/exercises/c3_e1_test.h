#include "data_structures/stack.h"
#include "test.h"
#include "exercises/c3_e1.h"

TEST(t_balanced_parens) {
  ASSERT_TRUE(check_balanced_parens("(())", NULL) == 1);
  ASSERT_TRUE(check_balanced_parens("(()", NULL) == 0);
  ASSERT_TRUE(check_balanced_parens("", NULL) == 1);
  
  size_t err;
  ASSERT_TRUE(check_balanced_parens("(()", &err) == 0);
  ASSERT_TRUE(err == 0);
}

TEST(t_longest_balanced_parens) {
  ASSERT_TRUE(longest_balanced_parens("") == 0);
  ASSERT_TRUE(longest_balanced_parens(")(") == 0);
  ASSERT_TRUE(longest_balanced_parens("()") == 2);
  ASSERT_TRUE(longest_balanced_parens("(())") == 4);
  ASSERT_TRUE(longest_balanced_parens(")()(())()()))())))(") == 12);
}

TEST(t_minstack_create_destroy) {
  MinStack* ms = minstack_create(10);
  ASSERT_TRUE(ms != NULL);

  minstack_destroy(&ms);
  ASSERT_TRUE(ms == NULL);
}

TEST(t_minstack_all_in_one) {
  MinStack* ms = minstack_create(10); // stack [] , min []
  int v = 13;
  minstack_push(ms, &v); // stack [13] , min [13]
  v = 14;
  minstack_push(ms, &v); // stack [13, 14] , min [13, 13]

  ASSERT_TRUE(stack_g_size(ms->stack) == 2);
  ASSERT_TRUE(stack_g_size(ms->min) == 2); 

  int tmp;
  minstack_peek(ms, &tmp);
  ASSERT_TRUE(tmp == 14);
  minstack_findmin(ms, &tmp);
  ASSERT_TRUE(tmp == 13);

  minstack_pop(ms, &tmp);
  ASSERT_TRUE(tmp == 14);
  ASSERT_TRUE(stack_g_size(ms->stack) == 1);
  ASSERT_TRUE(stack_g_size(ms->min) == 1);
}
