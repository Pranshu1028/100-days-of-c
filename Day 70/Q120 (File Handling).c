/*
Write a program to take a string input. Change it to sentence case.
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
    int start_of_word = 1;
    for (size_t i = 0; text[i] != '\0'; ++i) {
        if (isalpha((unsigned char)text[i])) {
            text[i] = (char)(start_of_word
                                 ? toupper((unsigned char)text[i])
                                 : tolower((unsigned char)text[i]));
            start_of_word = 0;
        } else {
            if (text[i] == '\n') text[i] = '\0';
            start_of_word = isspace((unsigned char)text[i]) != 0;
        }
    }
    puts(text);
    return 0;
}
