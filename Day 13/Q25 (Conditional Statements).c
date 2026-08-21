/*
Write a program to implement a basic calculator using switch-case for +, -, *, /, %.
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
    long long a, b, result;
    char op;
    if (scanf("%lld %lld %c", &a, &b, &op) != 3) {
        fprintf(stderr, "Expected two integers and an operator.\n");
        return 1;
    }
    switch (op) {
        case '+':
            if ((b > 0 && a > LLONG_MAX - b) ||
                (b < 0 && a < LLONG_MIN - b)) {
                fprintf(stderr, "Result is outside the supported range.\n");
                return 1;
            }
            printf("%lld\n", a + b);
            break;
        case '-':
            if ((b < 0 && a > LLONG_MAX + b) ||
                (b > 0 && a < LLONG_MIN + b)) {
                fprintf(stderr, "Result is outside the supported range.\n");
                return 1;
            }
            printf("%lld\n", a - b);
            break;
        case '*':
            if (!checked_multiply(a, b, &result)) {
                fprintf(stderr, "Result is outside the supported range.\n");
                return 1;
            }
            printf("%lld\n", result);
            break;
        case '/':
            if (b == 0) { fprintf(stderr, "Division by zero.\n"); return 1; }
            printf("%lld\n", a / b); break;
        case '%':
            if (b == 0) { fprintf(stderr, "Division by zero.\n"); return 1; }
            printf("%lld\n", a % b); break;
        default: fprintf(stderr, "Unsupported operator.\n"); return 1;
    }
    return 0;
}
