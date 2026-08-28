/*
Write a program to find the 1’s complement of a binary number and print it.
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
    char bits[10001];
    size_t length;
    if (scanf("%10000s", bits) != 1) {
        fprintf(stderr, "Expected a binary string.\n");
        return 1;
    }
    length = strlen(bits);
    for (size_t i = 0; i < length; ++i) {
        if (bits[i] != '0' && bits[i] != '1') {
            fprintf(stderr, "Input contains a non-binary digit.\n");
            return 1;
        }
        bits[i] = bits[i] == '0' ? '1' : '0';
    }
    puts(bits);
    return 0;
}
