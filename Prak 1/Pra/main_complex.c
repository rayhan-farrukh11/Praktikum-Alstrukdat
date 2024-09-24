#include "complex.c"
#include <stdio.h>

int main() {
    COMPLEX C1 = {1,2};
    COMPLEX C2 = {2,2};
    if (CEQ(C1, C2)) {
        printf("OK");
    } else if (CNEQ(C1,C2)) {
        printf("OK TOO");
    }
    return 0;
}