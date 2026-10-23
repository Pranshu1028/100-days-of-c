/*
Ask the user for a filename. Check if it exists by trying to open it in read mode. If the file pointer is NULL, print an error message; otherwise, read and display its content.
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
    char filename[256], line[1024];
    FILE *file;
    if (scanf("%255s", filename) != 1) return 1;
    file = fopen(filename, "r");
    if (file == NULL) {
        puts("Error: File does not exist!");
        return 0;
    }
    puts("File opened successfully.");
    while (fgets(line, sizeof(line), file) != NULL) fputs(line, stdout);
    if (ferror(file)) {
        perror("Reading file");
        fclose(file);
        return 1;
    }
    return fclose(file) == 0 ? 0 : 1;
}
