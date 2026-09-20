/*
Reverse a string.
*/

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char text[4096];
    size_t length = 0;
    if (fgets(text, sizeof(text), stdin) == NULL) return 1;
    while (text[length] != '\0' && text[length] != '\n') ++length;
    for (size_t i = length; i > 0; --i) putchar(text[i - 1]);
    putchar('\n');
    return 0;
}
