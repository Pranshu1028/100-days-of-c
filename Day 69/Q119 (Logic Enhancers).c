/*
Write a program to take an integer array as input. Only one element will be repeated. Print the repeated element. Try to find the result in one single iteration.
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
    int n, value, repeated = 0, found = 0;
    unsigned char seen[1001] = {0};
    if (scanf("%d", &n) != 1 || n < 2 || n > 1000) return 1;
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &value) != 1 || value < 0 || value > 1000) {
            fprintf(stderr, "Values must be from 0 to 1000.\n");
            return 1;
        }
        if (seen[value]) {
            repeated = value;
            found = 1;
        }
        seen[value] = 1;
    }
    if (!found) {
        fprintf(stderr, "No repeated element was provided.\n");
        return 1;
    }
    printf("%d\n", repeated);
    return 0;
}
