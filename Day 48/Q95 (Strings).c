/*
Check if one string is a rotation of another.
*/

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char first[2048], second[2048], doubled[4096];
    if (fgets(first, sizeof(first), stdin) == NULL ||
        fgets(second, sizeof(second), stdin) == NULL) return 1;
    first[strcspn(first, "\r\n")] = '\0';
    second[strcspn(second, "\r\n")] = '\0';
    size_t length = strlen(first);
    if (length != strlen(second)) {
        puts("Not rotation");
        return 0;
    }
    if (length >= sizeof(doubled) / 2) return 1;
    memcpy(doubled, first, length);
    memcpy(doubled + length, first, length + 1);
    puts(strstr(doubled, second) != NULL ? "Rotation" : "Not rotation");
    return 0;
}
