/*
Create Employee structure with nested Date structure for joining date and print details.
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

struct Date {
    int day, month, year;
};

struct Employee {
    char name[128];
    int id;
    struct Date joining_date;
};

int main(void) {
    struct Employee employee;
    if (scanf("%127s %d %d %d %d", employee.name, &employee.id,
              &employee.joining_date.day, &employee.joining_date.month,
              &employee.joining_date.year) != 5 ||
        employee.id < 0 || employee.joining_date.day < 1 ||
        employee.joining_date.day > 31 || employee.joining_date.month < 1 ||
        employee.joining_date.month > 12 || employee.joining_date.year < 1) {
        fprintf(stderr, "Invalid employee or joining-date data.\n");
        return 1;
    }
    printf("Name: %s | ID: %d | Joining Date: %02d/%02d/%04d\n",
           employee.name, employee.id, employee.joining_date.day,
           employee.joining_date.month, employee.joining_date.year);
    return 0;
}
