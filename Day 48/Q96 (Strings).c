/*
Reverse each word in a sentence without changing the word order.
*/

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char sentence[4096];
    if (fgets(sentence, sizeof(sentence), stdin) == NULL) return 1;
    size_t start = 0, end = 0;
    while (sentence[end] != '\0') {
        if (sentence[end] == ' ' || sentence[end] == '\n') {
            for (size_t i = end; i > start; --i) putchar(sentence[i - 1]);
            putchar(sentence[end]);
            start = end + 1;
        }
        ++end;
    }
    if (end > start) {
        for (size_t i = end; i > start; --i) putchar(sentence[i - 1]);
        putchar('\n');
    }
    return 0;
}
