#include "test.h"
#include "exercises/c3_e1.h"

TEST(t_balanced_parens) {
  ASSERT_TRUE(check_balanced_parens("(())", NULL) == 1);
  ASSERT_TRUE(check_balanced_parens("(()", NULL) == 0);
}
