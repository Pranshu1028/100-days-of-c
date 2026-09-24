/*
Check if two strings are anagrams of each other.
*/

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char first[4096], second[4096];
    int counts[256] = {0}, anagrams = 1;
    if (fgets(first, sizeof(first), stdin) == NULL ||
        fgets(second, sizeof(second), stdin) == NULL) return 1;
    for (size_t i = 0; first[i] != '\0' && first[i] != '\n'; ++i)
        ++counts[(unsigned char)first[i]];
    for (size_t i = 0; second[i] != '\0' && second[i] != '\n'; ++i)
        --counts[(unsigned char)second[i]];
    for (int i = 0; i < 256; ++i) if (counts[i] != 0) anagrams = 0;
    puts(anagrams ? "Anagrams" : "Not anagrams");
    return 0;
}
