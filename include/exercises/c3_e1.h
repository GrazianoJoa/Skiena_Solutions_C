#ifndef C3_E1_H
#define C3_E1_H
#include <stddef.h>
#include <stdio.h>
#include "data_structures/linked_list.h"
#include "data_structures/stack.h"

int check_balanced_parens(const char *s, size_t *err_pos);
int longest_balanced_parens(const char* s); 
LinkedListStatus reverse_linked_list(LinkedList** list);

typedef struct MinStack {
  Stack* min;
  Stack* stack;
  size_t capacity;
} MinStack;

MinStack* minstack_create(size_t capacity);
void minstack_destroy(MinStack** ms);
int minstack_push(MinStack* ms, int* value);
int minstack_peek(MinStack* ms, int* peek);
int minstack_pop(MinStack* ms, int* pop);
int minstack_findmin(MinStack* ms, int* min);

#endif
