/*
Show that enums store integers by printing assigned values.
*/

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    enum Status { SUCCESS, FAILURE, TIMEOUT };
    printf("SUCCESS=%d, FAILURE=%d, TIMEOUT=%d\n",
           SUCCESS, FAILURE, TIMEOUT);
    return 0;
}
