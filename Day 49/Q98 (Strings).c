/*
Print initials of a name with the surname displayed in full.
*/

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char name[4096], *words[256];
    int count = 0;
    if (fgets(name, sizeof(name), stdin) == NULL) return 1;
    char *word = strtok(name, " \t\r\n");
    while (word != NULL && count < 256) {
        words[count++] = word;
        word = strtok(NULL, " \t\r\n");
    }
    if (count == 0) {
        fprintf(stderr, "Name must not be empty.\n");
        return 1;
    }
    for (int i = 0; i < count - 1; ++i) printf("%c.", words[i][0]);
    puts(words[count - 1]);
    return 0;
}
