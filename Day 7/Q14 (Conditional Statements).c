/*
Write a program to input a character and check whether it is a vowel or consonant using if–else.
*/

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdarg.h>

static int c11_scanf(const char *format, ...)
    __attribute__((format(gnu_scanf, 1, 2)));

static int c11_scanf(const char *format, ...) {
    va_list arguments;
    int result;
    va_start(arguments, format);
    result = vscanf(format, arguments);
    va_end(arguments);
    return result;
}

#define scanf c11_scanf

int main(void) {
    char ch;
    if (scanf(" %c", &ch) != 1) {
        fprintf(stderr, "Expected a character.\n");
        return 1;
    }
    if (!isalpha((unsigned char)ch)) {
        fprintf(stderr, "Input must be an alphabetic character.\n");
        return 1;
    }
    ch = (char)tolower((unsigned char)ch);
    puts(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'
             ? "Vowel" : "Consonant");
    return 0;
}
