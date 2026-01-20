#include "test.h"
#include "linked_list_test.c" 

TestContext test_ctx = {0, 0, 0, 0};

void t_linked_list_create_destroy(void);
void t_linked_list_odt_behavior(void);

int main() {
   RUN_TEST(t_linked_list_create_destroy);
   RUN_TEST(t_linked_list_odt_behavior);
   test_report();
}
