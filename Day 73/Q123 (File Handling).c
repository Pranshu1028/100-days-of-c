/*
Read a text file and count the total number of characters, words, and lines. A word is defined as a sequence of non-space characters separated by spaces or newlines.
*/

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE *file = fopen("sample.txt", "r");
    int ch, previous = '\n', in_word = 0;
    unsigned long long characters = 0, words = 0, lines = 0;
    if (file == NULL) {
        perror("sample.txt");
        return 1;
    }
    while ((ch = fgetc(file)) != EOF) {
        ++characters;
        if (ch == '\n') ++lines;
        if (isspace((unsigned char)ch)) in_word = 0;
        else if (!in_word) { ++words; in_word = 1; }
        previous = ch;
    }
    if (ferror(file)) {
        perror("Reading sample.txt");
        fclose(file);
        return 1;
    }
    if (characters > 0 && previous != '\n') ++lines;
    if (fclose(file) != 0) return 1;
    printf("Characters: %llu\nWords: %llu\nLines: %llu\n",
           characters, words, lines);
    return 0;
}
