/*
Write a program to input a character and check whether it is an uppercase alphabet, lowercase alphabet, digit, or special character.
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
    if (isupper((unsigned char)ch)) {
        puts("Uppercase alphabet");
    } else if (islower((unsigned char)ch)) {
        puts("Lowercase alphabet");
    } else if (isdigit((unsigned char)ch)) {
        puts("Digit");
    } else {
        puts("Special character");
    }
    return 0;
}
