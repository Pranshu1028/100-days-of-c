/*
Read a text file and count how many vowels and consonants are in the file. Ignore digits and special characters.
*/

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE *file = fopen("text.txt", "r");
    int ch, vowels = 0, consonants = 0;
    if (file == NULL) { perror("text.txt"); return 1; }
    while ((ch = fgetc(file)) != EOF) {
        if (isalpha((unsigned char)ch)) {
            ch = tolower((unsigned char)ch);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                ++vowels;
            else ++consonants;
        }
    }
    if (ferror(file) || fclose(file) != 0) return 1;
    printf("Vowels: %d\nConsonants: %d\n", vowels, consonants);
    return 0;
}
