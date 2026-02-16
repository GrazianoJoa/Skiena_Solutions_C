#include "exercises/c3_e2.h"
#include "stdlib.h"
#include "data_structures/hash_map.h"

// 3.8 I DONT CHECK VALID MOVES IN THIS ONE

TicTacToe* tic_tac_toe_create(size_t size) {
  
  TicTacToe* table = malloc(sizeof(TicTacToe));
  if (!table) return NULL;

  table->rows = calloc(size, sizeof(int));
  table->cols = calloc(size, sizeof(int));
  if (!table->rows || !table->cols) {
    free(table->rows);
    free(table->cols);
    free(table);
    return NULL;
  }

  table->size = size;
  table->diag = 0;
  table->rev_diag = 0;
  table->winner = 0;

  return table;
}

void tic_tac_toe_destroy(TicTacToe** table) {
  if (!table || !(*table)) return;

  free((*table)->rows);
  free((*table)->cols);
  free(*table);

  *table = NULL;
}

void tic_tac_toe_make_moves(TicTacToe* table, char* moves) {
  int player = 1; // ASSUME X MOVES FIRST
  size_t i = 0;
  while (moves[i] != '\0') {
    if (moves[i] == ' ') i++;
    int square = (size_t)moves[i] - '0';
    int col = (square-1) % table->size;
    int row = (square-1) / table->size;

    table->rows[row] += player;
    table->cols[col] += player;

    if (row == col) table->diag += player;
    if (row + col == (int)(table->size-1)) table->rev_diag += player;

    if (abs(table->rows[row]) == (int)table->size ||
        abs(table->cols[col]) == (int)table->size ||
        abs(table->diag) == (int)table->size ||
        abs(table->rev_diag) == (int)table->size) {
      table->winner = player;
      return;
    }

    player = -player;
    i++;
  }
}

int tic_tac_toe_check_state(TicTacToe* table) {
  return table->winner; 
}

// TODO: REFACTOR WHEN I IMPLEMENT A DYNAMIC ARRAY.

size_t find_all_combinations_number_pad(char* sequence, char** dictionary, size_t n) {
  HashMap* hp = hash_map_create(sizeof(char*), n, number_pad_hash, NULL, NULL);
  for (size_t i = 0; i < n; i++) {

  }
}  
