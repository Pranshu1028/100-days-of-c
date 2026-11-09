/*
Find and print the student with the highest marks.
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
    struct Student students[100];
    int n, top = 0;
    if (scanf("%d", &n) != 1 || n < 1 || n > 100) return 1;
    for (int i = 0; i < n; ++i) {
        if (scanf("%127s %d %lf", students[i].name,
                  &students[i].roll_no, &students[i].marks) != 3 ||
            students[i].roll_no < 0 || students[i].marks < 0.0 ||
            students[i].marks > 100.0) return 1;
        if (students[i].marks > students[top].marks) top = i;
    }
    printf("Topper: %s (Marks: %.2f)\n",
           students[top].name, students[top].marks);
    return 0;
}
