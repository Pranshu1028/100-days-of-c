/*
Write a program to print all the prime numbers from 1 to n.
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
    int n, first = 1;
    unsigned char *prime;
    if (scanf("%d", &n) != 1 || n < 0 || n > 1000000) {
        fprintf(stderr, "Enter n from 0 to 1000000.\n");
        return 1;
    }
    prime = calloc((size_t)n + 1U, sizeof *prime);
    if (prime == NULL) {
        fprintf(stderr, "Could not allocate the sieve.\n");
        return 1;
    }
    memset(prime, 1, (size_t)n + 1U);
    prime[0] = 0;
    if (n >= 1) prime[1] = 0;
    for (int value = 2; value <= n / value; ++value) {
        if (prime[value]) {
            for (int multiple = value * value; multiple <= n; multiple += value)
                prime[multiple] = 0;
        }
    }
    for (int value = 2; value <= n; ++value)
        if (prime[value]) {
            printf("%s%d", first ? "" : " ", value);
            first = 0;
        }
    free(prime);
    putchar('\n');
    return 0;
}
