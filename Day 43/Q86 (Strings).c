/*
Check if a string is a palindrome.
*/

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char text[4096];
    size_t length = 0;
    if (fgets(text, sizeof(text), stdin) == NULL) return 1;
    while (text[length] != '\0' && text[length] != '\n') ++length;
    int palindrome = 1;
    for (size_t i = 0; i < length / 2; ++i)
        if (text[i] != text[length - i - 1]) palindrome = 0;
    puts(palindrome ? "Palindrome" : "Not palindrome");
    return 0;
}
