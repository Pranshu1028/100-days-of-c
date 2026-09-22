/*
Toggle case of each character in a string.
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
        if (islower((unsigned char)text[i])) text[i] = (char)toupper((unsigned char)text[i]);
        else if (isupper((unsigned char)text[i])) text[i] = (char)tolower((unsigned char)text[i]);
    }
    puts(text);
    return 0;
}
