#include <stdio.h>
#include "exercises/c3_e1.h"
#include "data_structures/linked_list.h"

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
