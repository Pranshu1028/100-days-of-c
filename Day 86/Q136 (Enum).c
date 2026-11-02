/*
Use enum to represent menu choices (ADD, SUBTRACT, MULTIPLY) and perform operations using switch.
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

static int checked_multiply(long long a, long long b, long long *result) {
    if (a > 0) {
        if ((b > 0 && a > LLONG_MAX / b) ||
            (b < 0 && b < LLONG_MIN / a)) return 0;
    } else if (a < 0) {
        if ((b > 0 && a < LLONG_MIN / b) ||
            (b < 0 && a < LLONG_MAX / b)) return 0;
    }
    *result = a * b;
    return 1;
}

int main(void) {
    enum Operation { ADD, SUBTRACT, MULTIPLY };
    char input[32];
    long long a, b, result;
    enum Operation operation;
    if (scanf("%31s %lld %lld", input, &a, &b) != 3) return 1;
    if (strcmp(input, "ADD") == 0) operation = ADD;
    else if (strcmp(input, "SUBTRACT") == 0) operation = SUBTRACT;
    else if (strcmp(input, "MULTIPLY") == 0) operation = MULTIPLY;
    else { fprintf(stderr, "Unknown operation.\n"); return 1; }
    switch (operation) {
        case ADD:
            if ((b > 0 && a > LLONG_MAX - b) ||
                (b < 0 && a < LLONG_MIN - b)) {
                fprintf(stderr, "Result is outside the supported range.\n");
                return 1;
            }
            result = a + b;
            break;
        case SUBTRACT:
            if ((b < 0 && a > LLONG_MAX + b) ||
                (b > 0 && a < LLONG_MIN + b)) {
                fprintf(stderr, "Result is outside the supported range.\n");
                return 1;
            }
            result = a - b;
            break;
        case MULTIPLY:
            if (!checked_multiply(a, b, &result)) {
                fprintf(stderr, "Result is outside the supported range.\n");
                return 1;
            }
            break;
        default: return 1;
    }
    printf("%lld\n", result);
    return 0;
}
