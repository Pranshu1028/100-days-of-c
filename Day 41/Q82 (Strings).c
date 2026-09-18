/*
Print each character of a string on a new line.
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
    for (size_t i = 0; text[i] != '\0' && text[i] != '\n'; ++i)
        printf("%c\n", text[i]);
    return 0;
}
