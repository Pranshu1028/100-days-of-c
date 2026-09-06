/*
Find the maximum and minimum element in an array.
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
    int n, value, minimum, maximum;
    if (scanf("%d", &n) != 1 || n < 1 || n > 1000 ||
        scanf("%d", &value) != 1) {
        fprintf(stderr, "Invalid array size or missing element.\n");
        return 1;
    }
    minimum = maximum = value;
    for (int i = 1; i < n; ++i) {
        if (scanf("%d", &value) != 1) {
            fprintf(stderr, "Missing array element.\n");
            return 1;
        }
        if (value < minimum) minimum = value;
        if (value > maximum) maximum = value;
    }
    printf("Max=%d, Min=%d\n", maximum, minimum);
    return 0;
}
