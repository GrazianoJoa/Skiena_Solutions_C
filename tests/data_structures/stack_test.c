#include "test.h"
#include "stack.h"

TEST(stack_test) {
   Stack* s1 = stack_create(sizeof(int), 2);
   int x = 4;
   stack_push(s1, &x);
   stack_peek(s1, &x);
   ASSERT_TRUE(x == 4);
   stack_destroy(&s1);
}
