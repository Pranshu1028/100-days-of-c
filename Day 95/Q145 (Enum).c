/*
Return a structure containing top student's details from a function.
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

static struct Student top_student(const struct Student students[], int n) {
    int top = 0;
    for (int i = 1; i < n; ++i)
        if (students[i].marks > students[top].marks) top = i;
    return students[top];
}

int main(void) {
    struct Student students[100], top;
    int n;
    if (scanf("%d", &n) != 1 || n < 1 || n > 100) return 1;
    for (int i = 0; i < n; ++i) {
        if (scanf("%127s %d %lf", students[i].name,
                  &students[i].roll_no, &students[i].marks) != 3 ||
            students[i].roll_no < 0 || students[i].marks < 0.0 ||
            students[i].marks > 100.0) return 1;
    }
    top = top_student(students, n);
    printf("Top Student: %s | Roll: %d | Marks: %.2f\n",
           top.name, top.roll_no, top.marks);
    return 0;
}
