/*
Count frequency of a given character in a string.
*/

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char text[4096], line[32], target;
    int count = 0;
    if (fgets(text, sizeof(text), stdin) == NULL ||
        fgets(line, sizeof(line), stdin) == NULL) return 1;
    if (sscanf(line, " %c", &target) != 1) {
        fprintf(stderr, "Expected a character to count.\n");
        return 1;
    }
    for (size_t i = 0; text[i] != '\0' && text[i] != '\n'; ++i)
        if (text[i] == target) ++count;
    printf("%d\n", count);
    return 0;
}
