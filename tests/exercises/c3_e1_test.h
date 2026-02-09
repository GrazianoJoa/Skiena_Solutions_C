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
