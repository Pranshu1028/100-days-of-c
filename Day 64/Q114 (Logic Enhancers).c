/*
Write a program to take a string s as input. The task is to find the length of the longest substring without repeating characters. Print the length as output.
*/

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    unsigned char text[4096];
    int last_seen[256], start = 0, longest = 0;
    if (fgets((char *)text, sizeof(text), stdin) == NULL) return 1;
    for (int i = 0; i < 256; ++i) last_seen[i] = -1;
    for (int i = 0; text[i] != '\0' && text[i] != '\n'; ++i) {
        if (last_seen[text[i]] >= start) start = last_seen[text[i]] + 1;
        last_seen[text[i]] = i;
        if (i - start + 1 > longest) longest = i - start + 1;
    }
    printf("%d\n", longest);
    return 0;
}
