/*
Count characters in a string without using built-in length functions.
*/

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char text[4096];
    if (fgets(text, sizeof(text), stdin) == NULL) {
        fprintf(stderr, "Expected a line of text.\n");
        return 1;
    }
    size_t length = 0;
    while (text[length] != '\0' && text[length] != '\n') ++length;
    printf("%zu\n", length);
    return 0;
}
