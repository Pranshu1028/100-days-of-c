/*
Write a function that accepts a structure as parameter and prints its members.
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

static void print_student(struct Student student) {
    printf("Name: %s | Roll: %d | Marks: %.2f\n",
           student.name, student.roll_no, student.marks);
}

int main(void) {
    struct Student student;
    if (scanf("%127s %d %lf", student.name, &student.roll_no,
              &student.marks) != 3 || student.roll_no < 0 ||
        student.marks < 0.0 || student.marks > 100.0) return 1;
    print_student(student);
    return 0;
}
