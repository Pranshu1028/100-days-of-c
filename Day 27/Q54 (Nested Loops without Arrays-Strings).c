/*
Write a program to print the following pattern:

   *
  ***
 *****
*******
 *****
  ***
   *

*/

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    for (int row = 0; row < 4; ++row) {
        for (int space = 0; space < 3 - row; ++space) putchar(' ');
        for (int star = 0; star < 2 * row + 1; ++star) putchar('*');
        putchar('\n');
    }
    for (int row = 2; row >= 0; --row) {
        for (int space = 0; space < 3 - row; ++space) putchar(' ');
        for (int star = 0; star < 2 * row + 1; ++star) putchar('*');
        putchar('\n');
    }
    return 0;
}
