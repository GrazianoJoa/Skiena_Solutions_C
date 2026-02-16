#ifndef C3_E2_TEST_H
#define C3_E2_TEST_H
#include "test.h"
#include "exercises/c3_e2.h"

TEST(t_tic_tac_toe_create_destroy) {
  TicTacToe* ttt = tic_tac_toe_create(10);
  ASSERT_TRUE(ttt != NULL);

  tic_tac_toe_destroy(&ttt);
  ASSERT_TRUE(ttt == NULL);
}

TEST(t_tic_tac_toe_win_match) {
  TicTacToe* ttt = tic_tac_toe_create(3);
  tic_tac_toe_make_moves(ttt, "1 9 2 8 3");
  ASSERT_TRUE(tic_tac_toe_check_state(ttt) == 1);

  tic_tac_toe_destroy(&ttt);
}

TEST(t_tic_tac_toe_incomplete_match) {
  TicTacToe* ttt = tic_tac_toe_create(3);
  tic_tac_toe_make_moves(ttt, "1 3");
  ASSERT_TRUE(tic_tac_toe_check_state(ttt) == 0);

  tic_tac_toe_destroy(&ttt);
}

TEST(t_tic_tac_toe_draw) {
  TicTacToe* ttt = tic_tac_toe_create(3);
  tic_tac_toe_make_moves(ttt, "5 1 2 3 4 6 9 8 7");
  ASSERT_TRUE(tic_tac_toe_check_state(ttt) == 0);

  tic_tac_toe_destroy(&ttt);
}

#endif
