/*
Write a program that accepts a percentage (0-100) and assigns a grade based on the following criteria: 
90-100: Grade A 
80-89: Grade B 
70-79: Grade C 
60-69: Grade D 
below 60: Grade F.
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
    int percentage;
    if (scanf("%d", &percentage) != 1 || percentage < 0 ||
        percentage > 100) {
        fprintf(stderr, "Percentage must be from 0 to 100.\n");
        return 1;
    }
    if (percentage >= 90) puts("Grade A");
    else if (percentage >= 80) puts("Grade B");
    else if (percentage >= 70) puts("Grade C");
    else if (percentage >= 60) puts("Grade D");
    else puts("Grade F");
    return 0;
}
