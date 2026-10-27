/*
Store multiple student records (name, roll number, marks) into a file using fprintf(). Then read them using fscanf() and display each record.
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

static int c11_fscanf(FILE *stream, const char *format, ...)
    __attribute__((format(gnu_scanf, 2, 3)));

static int c11_fscanf(FILE *stream, const char *format, ...) {
    va_list arguments;
    int result;
    va_start(arguments, format);
    result = vfscanf(stream, format, arguments);
    va_end(arguments);
    return result;
}

#define fscanf c11_fscanf

int main(void) {
    int n;
    char names[100][128];
    int rolls[100], marks[100];
    FILE *file;
    if (scanf("%d", &n) != 1 || n < 1 || n > 100) {
        fprintf(stderr, "Student count must be from 1 to 100.\n");
        return 1;
    }
    file = fopen("students.txt", "w");
    if (file == NULL) { perror("students.txt"); return 1; }
    for (int i = 0; i < n; ++i) {
        if (scanf("%127s %d %d", names[i], &rolls[i], &marks[i]) != 3 ||
            marks[i] < 0 || marks[i] > 100 ||
            fprintf(file, "%s %d %d\n", names[i], rolls[i], marks[i]) < 0) {
            fprintf(stderr, "Invalid student record.\n");
            fclose(file);
            return 1;
        }
    }
    if (fclose(file) != 0) return 1;
    file = fopen("students.txt", "r");
    if (file == NULL) { perror("students.txt"); return 1; }
    for (int i = 0; i < n; ++i) {
        if (fscanf(file, "%127s %d %d", names[i], &rolls[i], &marks[i]) != 3) {
            fprintf(stderr, "Could not read student record.\n");
            fclose(file);
            return 1;
        }
        printf("Name: %s | Roll: %d | Marks: %d\n",
               names[i], rolls[i], marks[i]);
    }
    return fclose(file) == 0 ? 0 : 1;
}
