#include <stdio.h>
#include "exercises/c3_e1.h"
#include "data_structures/linked_list.h"
#include "data_structures/stack.h"

// 3.1
int check_balanced_parens(const char* s, size_t* err_pos) {
  int depth = 0;
  size_t i = 0;
  size_t first_unmatch = (size_t)-1; // Wraps around

  while (s[i] != '\0') {
    if (s[i] == '(') {
      if (depth == 0) {
        first_unmatch = i;
      }
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
    if (err_pos) *err_pos = first_unmatch;
    return 0;
  }

  return 1;
}

// 3.2
int longest_balanced_parens(const char* s) {
  size_t i = 0;
  size_t depth = 0;
  size_t max = 0;
  
  while (s[i] != '\0') {
    if (s[i] == '(') {
      depth++;
    } else if (s[i] == ')') {
      if (depth > 0) {
        depth--;
        max += 2;
      }
    }
    i++;
  }

  return max;
} 

// 3.3
LinkedListStatus reverse_linked_list(LinkedList** list) {
  if (!list || !*list) return LINKED_LIST_ERR_NULL;
  
  ListNode* prev = NULL;
  ListNode* curr = linked_list_g_head(*list);

  while (curr) {
    ListNode* next = list_node_g_next(curr);
    list_node_s_next(curr, prev);
    prev = curr;
    curr = next;
  }

  linked_list_s_head(*list, prev);

  return LINKED_LIST_OK;
}

// 3.4

// CAUTION: THERES NO ERROR HANDLING OR NOT NULL CHECKING IN THE IMPLEMENTATION.

MinStack* minstack_create(size_t capacity) {
  MinStack* ms = malloc(sizeof(MinStack));
  if (!ms) return NULL;
  
  ms->stack = stack_create(sizeof(int), capacity, NULL, NULL);
  ms->min = stack_create(sizeof(int), capacity, NULL, NULL);
  if (!ms->min || !ms->stack) {
    stack_destroy(&ms->stack);
    stack_destroy(&ms->min);
    return NULL;
  }
  
  ms->capacity = capacity;
  return ms;
}

void minstack_destroy(MinStack** ms) {
  if (!ms || !(*ms)) return;

  stack_destroy(&(*ms)->stack);
  stack_destroy(&(*ms)->min);

  free(*ms);
  *ms = NULL;
}

int minstack_push(MinStack* ms, int* value) {
  stack_push(ms->stack, value);

  if (stack_is_empty(ms->min)) {
    stack_push(ms->min, value);
  } else {
    int min;
    stack_peek(ms->min, &min);
    int new_min = (*value < min) ? *value : min;
    stack_push(ms->min, &new_min);
  }

  return 0;
}

int minstack_pop(MinStack* ms, int* pop) {
  if (stack_is_empty(ms->stack)) return 1;

  stack_pop(ms->stack, pop);
  stack_pop(ms->min, NULL);

  return 0;
}

int minstack_peek(MinStack* ms, int* peek) {
  if (stack_is_empty(ms->stack)) return 1;

  stack_peek(ms->stack, peek);
  return 0;
}

int minstack_findmin(MinStack* ms, int* min) {
  if (stack_is_empty(ms->min)) return 1;

  stack_peek(ms->min, min);

  return 0;
}

// 3.5

// TODO: IMPLEMENT A DYNAMIC ARRAY IN DATA STRUCTURES FOLDER AND EXTEND IN THIS IMPLEMENTATION

typedef struct ShrinkArray {
  int* data;
  size_t capacity;
  size_t size;
} ShrinkArray;

// 3.7

