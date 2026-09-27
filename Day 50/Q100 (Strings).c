/*
Print all sub-strings of a string.
*/

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char text[1024];
    size_t length;
    int first = 1;
    if (fgets(text, sizeof(text), stdin) == NULL) return 1;
    length = strcspn(text, "\r\n");
    for (size_t start = 0; start < length; ++start) {
        for (size_t end = start + 1; end <= length; ++end) {
            printf("%s%.*s", first ? "" : ",", (int)(end - start), text + start);
            first = 0;
        }
    }
    putchar('\n');
    return 0;
}
