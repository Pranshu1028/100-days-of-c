/*
Write a program to calculate electricity bill based on units consumed with these rates: 
First 100 units at ₹5/unit 
Next 100 units at ₹7/unit 
Next 100 units at ₹10/unit 
Above at ₹12/unit
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
    long long units, bill;
    if (scanf("%lld", &units) != 1 || units < 0) {
        fprintf(stderr, "Units must be non-negative.\n");
        return 1;
    }
    if (units > (LLONG_MAX - 2200) / 12 + 300) {
        fprintf(stderr, "Bill is outside the supported range.\n");
        return 1;
    }
    if (units <= 100) bill = units * 5;
    else if (units <= 200) bill = 500 + (units - 100) * 7;
    else if (units <= 300) bill = 1200 + (units - 200) * 10;
    else bill = 2200 + (units - 300) * 12;
    printf("Bill: Rs %lld\n", bill);
    return 0;
}
