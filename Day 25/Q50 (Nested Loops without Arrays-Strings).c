/*
Write a program to print the following pattern:
*****
 ****
  ***
   **
    *
*/

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    for (int row = 0; row < 5; ++row) {
        for (int space = 0; space < row; ++space) putchar(' ');
        for (int star = row; star < 5; ++star) putchar('*');
        putchar('\n');
    }
    return 0;
}
