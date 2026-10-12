/*
Write a program to take two strings s and t as inputs (assume all characters are lowercase). The task is to determine if s and t are valid anagrams, meaning they contain the same characters with the same frequencies. Print "Anagram" if they are, otherwise "Not Anagram".
*/

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char first[4096], second[4096];
    int counts[26] = {0}, valid = 1;
    if (fgets(first, sizeof(first), stdin) == NULL ||
        fgets(second, sizeof(second), stdin) == NULL) return 1;
    first[strcspn(first, "\r\n")] = '\0';
    second[strcspn(second, "\r\n")] = '\0';
    for (size_t i = 0; first[i] != '\0'; ++i) {
        if (first[i] < 'a' || first[i] > 'z') valid = 0;
        else ++counts[first[i] - 'a'];
    }
    for (size_t i = 0; second[i] != '\0'; ++i) {
        if (second[i] < 'a' || second[i] > 'z') valid = 0;
        else --counts[second[i] - 'a'];
    }
    for (int i = 0; i < 26; ++i) if (counts[i] != 0) valid = 0;
    puts(valid ? "Anagram" : "Not Anagram");
    return 0;
}
