/*
Print the initials of a name.
*/

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char name[4096];
    int in_word = 0;
    if (fgets(name, sizeof(name), stdin) == NULL) return 1;
    for (size_t i = 0; name[i] != '\0' && name[i] != '\n'; ++i) {
        if (isspace((unsigned char)name[i])) in_word = 0;
        else if (!in_word) {
            printf("%c.", name[i]);
            in_word = 1;
        }
    }
    putchar('\n');
    return 0;
}
