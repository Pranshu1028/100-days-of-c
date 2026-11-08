/*
Store details of 5 students in an array of structures and print all.
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

struct Student {
    char name[128];
    int roll_no;
    double marks;
};

int main(void) {
    struct Student students[5];
    for (int i = 0; i < 5; ++i) {
        if (scanf("%127s %d %lf", students[i].name,
                  &students[i].roll_no, &students[i].marks) != 3 ||
            students[i].roll_no < 0 || students[i].marks < 0.0 ||
            students[i].marks > 100.0) {
            fprintf(stderr, "Invalid student record.\n");
            return 1;
        }
    }
    puts("Name | Roll | Marks");
    for (int i = 0; i < 5; ++i)
        printf("%s | %d | %.2f\n", students[i].name,
               students[i].roll_no, students[i].marks);
    return 0;
}
