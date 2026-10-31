/*
Define an enum with SUCCESS, FAILURE, and TIMEOUT, and print messages accordingly.
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
    enum Result { SUCCESS, FAILURE, TIMEOUT };
    char input[32];
    enum Result result;
    if (scanf("%31s", input) != 1) return 1;
    if (strcmp(input, "SUCCESS") == 0) result = SUCCESS;
    else if (strcmp(input, "FAILURE") == 0) result = FAILURE;
    else if (strcmp(input, "TIMEOUT") == 0) result = TIMEOUT;
    else { fprintf(stderr, "Unknown result.\n"); return 1; }
    switch (result) {
        case SUCCESS: puts("Operation succeeded"); break;
        case FAILURE: puts("Operation failed"); break;
        case TIMEOUT: puts("Operation timed out"); break;
    }
    return 0;
}
