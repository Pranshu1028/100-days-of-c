/*
Write a program to print numbers from 1 to n.
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
    int n;
    if (scanf("%d", &n) != 1 || n < 1 || n > 1000000) {
        fprintf(stderr, "Enter n from 1 to 1000000.\n");
        return 1;
    }
    for (int i = 1; i <= n; ++i) printf("%s%d", i == 1 ? "" : " ", i);
    putchar('\n');
    return 0;
}
