/*
Write a program to calculate library fine based on late days as follows: 
First 5 days late: ₹2/day 
Next 5 days late: ₹4/day 
Next 20 days days late: ₹6/day 
More than 30 days: Membership Cancelled.
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
    long long days, fine;
    if (scanf("%lld", &days) != 1 || days < 0) {
        fprintf(stderr, "Late days must be non-negative.\n");
        return 1;
    }
    if (days > 30) {
        puts("Membership Cancelled");
    } else {
        fine = (days < 5 ? days : 5) * 2;
        if (days > 5) fine += (days - 5 < 5 ? days - 5 : 5) * 4;
        if (days > 10) fine += (days - 10) * 6;
        printf("Fine Rs %lld\n", fine);
    }
    return 0;
}
