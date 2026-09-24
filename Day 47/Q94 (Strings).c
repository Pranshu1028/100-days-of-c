/*
Find the longest word in a sentence.
*/

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char sentence[4096], longest[4096] = "";
    size_t best = 0;
    if (fgets(sentence, sizeof(sentence), stdin) == NULL) return 1;
    char *word = strtok(sentence, " \t\r\n");
    while (word != NULL) {
        size_t length = strlen(word);
        if (length > best) {
            best = length;
            memcpy(longest, word, length + 1);
        }
        word = strtok(NULL, " \t\r\n");
    }
    puts(longest);
    return 0;
}
