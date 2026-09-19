/*
Convert a lowercase string to uppercase without using built-in functions.
*/

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char text[4096];
    if (fgets(text, sizeof(text), stdin) == NULL) return 1;
    for (size_t i = 0; text[i] != '\0'; ++i) {
        if (text[i] >= 'a' && text[i] <= 'z') text[i] -= 'a' - 'A';
        if (text[i] == '\n') text[i] = '\0';
    }
    puts(text);
    return 0;
}
