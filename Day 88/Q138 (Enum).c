/*
Print all enum names and integer values using a loop.
*/

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    enum Color { RED, YELLOW, GREEN };
    static const char *names[] = {"RED", "YELLOW", "GREEN"};
    for (enum Color color = RED; color <= GREEN;
         color = (enum Color)(color + 1))
        printf("%s=%d\n", names[color], color);
    return 0;
}
