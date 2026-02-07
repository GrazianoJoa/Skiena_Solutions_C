#include <stdio.h>
#include "exercises/c3_e1.h"

int check_balanced_parens(const char* s, size_t* err_pos) {
  int depth = 0;
  size_t i = 0;

  while (s[i] != '\0') {
    if (s[i] == '(') {
      depth++;
    } else if (s[i] == ')') {
      if (depth > 0) { 
        depth--;
      } else {
        if (err_pos) {
          *err_pos = i;
        }
        return 0;
      }
    }
    i++;
  }

  if (depth != 0) {
    if (err_pos) *err_pos = i;
    return 0;
  }

  return 1;
}
