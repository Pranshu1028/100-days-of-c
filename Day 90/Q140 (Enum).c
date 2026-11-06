/*
Define a struct with enum Gender and print person's gender.
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
    enum Gender { MALE, FEMALE, OTHER };
    struct Person { enum Gender gender; } person;
    char input[16];
    if (scanf("%15s", input) != 1) return 1;
    if (strcmp(input, "MALE") == 0) person.gender = MALE;
    else if (strcmp(input, "FEMALE") == 0) person.gender = FEMALE;
    else if (strcmp(input, "OTHER") == 0) person.gender = OTHER;
    else { fprintf(stderr, "Unknown gender.\n"); return 1; }
    if (person.gender == MALE) puts("Male");
    else if (person.gender == FEMALE) puts("Female");
    else puts("Other");
    return 0;
}
