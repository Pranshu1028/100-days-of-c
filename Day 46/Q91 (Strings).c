/*
Remove all vowels from a string.
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
    for (size_t i = 0; text[i] != '\0' && text[i] != '\n'; ++i) {
        int ch = tolower((unsigned char)text[i]);
        if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u')
            putchar(text[i]);
    }
    putchar('\n');
    return 0;
}
