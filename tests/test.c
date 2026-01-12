#include "test.h"

TestContext test_ctx = {0, 0, 0, 0};

void stack_test(void);

TEST(my_test) {
   ASSERT_TRUE(4 == 4);
   ASSERT_TRUE(4 > 4);
}

int main() {
   RUN_TEST(my_test);
   RUN_TEST(stack_test);
   test_report();
}
