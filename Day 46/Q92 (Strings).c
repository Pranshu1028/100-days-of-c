/*
Find the first repeating lowercase alphabet in a string.
*/

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char text[4096];
    int found = 0;
    if (fgets(text, sizeof(text), stdin) == NULL) return 1;
    for (size_t i = 0; text[i] != '\0' && text[i] != '\n'; ++i) {
        if (text[i] < 'a' || text[i] > 'z') continue;
        for (size_t j = i + 1; text[j] != '\0' && text[j] != '\n'; ++j) {
            if (text[i] == text[j]) {
                printf("%c\n", text[i]);
                found = 1;
                break;
            }
        }
        if (found) break;
    }
    if (!found) puts("No repeating lowercase alphabet");
    return 0;
}
