/*
Write a C program that creates a text file named info.txt in write mode. The program should take the user’s name and age as input, and write them to the file using fprintf(). After writing, display a message confirming that the data was successfully saved.
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
    char name[128];
    int age;
    FILE *file;
    if (scanf("%127s %d", name, &age) != 2 || age < 0) {
        fprintf(stderr, "Expected a name and a non-negative age.\n");
        return 1;
    }
    file = fopen("info.txt", "w");
    if (file == NULL) {
        perror("info.txt");
        return 1;
    }
    if (fprintf(file, "Name: %s\nAge: %d\n", name, age) < 0 ||
        fclose(file) != 0) {
        perror("Writing info.txt");
        return 1;
    }
    puts("File created successfully! Data written to info.txt");
    return 0;
}
