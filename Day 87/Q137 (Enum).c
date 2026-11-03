/*
Create an enum for user roles (ADMIN, USER, GUEST) and display messages based on role.
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
    enum Role { ADMIN, USER, GUEST };
    char input[32];
    enum Role role;
    if (scanf("%31s", input) != 1) return 1;
    if (strcmp(input, "ADMIN") == 0) role = ADMIN;
    else if (strcmp(input, "USER") == 0) role = USER;
    else if (strcmp(input, "GUEST") == 0) role = GUEST;
    else { fprintf(stderr, "Unknown role.\n"); return 1; }
    switch (role) {
        case ADMIN: puts("Welcome Admin!"); break;
        case USER: puts("Welcome User!"); break;
        case GUEST: puts("Welcome Guest!"); break;
    }
    return 0;
}
