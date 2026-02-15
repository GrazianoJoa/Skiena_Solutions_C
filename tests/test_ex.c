#include "test.h"
#include "exercises/c3_e1_test.h"

int main() {
  RUN_TEST(t_balanced_parens);
  RUN_TEST(t_longest_balanced_parens);
  RUN_TEST(t_minstack_create_destroy);
  RUN_TEST(t_minstack_all_in_one);
  test_report();
}


