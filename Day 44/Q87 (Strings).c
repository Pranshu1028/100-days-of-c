/*
Count spaces, digits, and special characters in a string.
*/

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char text[4096];
    int spaces = 0, digits = 0, special = 0;
    if (fgets(text, sizeof(text), stdin) == NULL) return 1;
    for (size_t i = 0; text[i] != '\0' && text[i] != '\n'; ++i) {
        if (text[i] == ' ') ++spaces;
        else if (isdigit((unsigned char)text[i])) ++digits;
        else if (!isalpha((unsigned char)text[i])) ++special;
    }
    printf("Spaces=%d, Digits=%d, Special=%d\n", spaces, digits, special);
    return 0;
}
