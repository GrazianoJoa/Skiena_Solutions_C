#ifndef C3_E2_H
#define C3_E2_H

#include "stdio.h"

// X = +1 and O = -1
typedef struct TicTacToe {
  int* rows;
  int* cols;
  int diag;
  int rev_diag;
  size_t size;

  int winner;
} TicTacToe;

TicTacToe* tic_tac_toe_create(size_t size);
void tic_tac_toe_destroy(TicTacToe** table);
// NOTE: I ASSUME THAT THE INPUT CONTAINS VALID MOVES (FOR NOW)
// int tic_tac_toe_valid_input(TicTacToe* table, char* moves);
void tic_tac_toe_make_moves(TicTacToe* table, char* moves);
int tic_tac_toe_check_state(TicTacToe* table);

#endif
