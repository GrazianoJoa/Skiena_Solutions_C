#include "utils.h"

int cmp_int(const void* a, const void* b) {
    int* x = (int*)a;
    int* y = (int*)b;
    return (*x > *y) - (*x < *y);
}
