/*
Assign explicit values starting from 10 and print them.
*/

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    enum Letter { A = 10, B, C };
    printf("A=%d\nB=%d\nC=%d\n", A, B, C);
    return 0;
}
