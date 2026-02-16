#include "test.h"
#include "exercises/c3_e1_test.h"
#include "exercises/c3_e2_test.h"

int main() {
  RUN_TEST(t_balanced_parens);
  RUN_TEST(t_longest_balanced_parens);
  RUN_TEST(t_minstack_create_destroy);
  RUN_TEST(t_minstack_all_in_one);

  RUN_TEST(t_tic_tac_toe_create_destroy);
  RUN_TEST(t_tic_tac_toe_win_match);
  RUN_TEST(t_tic_tac_toe_incomplete_match);
  RUN_TEST(t_tic_tac_toe_draw);

  test_report();
}


