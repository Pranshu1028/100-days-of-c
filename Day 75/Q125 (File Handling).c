/*
Open an existing file in append mode and allow the user to enter a new line of text. Append the text at the end without overwriting existing content.
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
    char filename[256], text[4096];
    FILE *file;
    if (scanf("%255s", filename) != 1) return 1;
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) { }
    if (fgets(text, sizeof(text), stdin) == NULL) {
        fprintf(stderr, "Expected a line to append.\n");
        return 1;
    }
    file = fopen(filename, "a");
    if (file == NULL) { perror(filename); return 1; }
    if (fprintf(file, "%s%s", text[0] == '\n' ? "" : "\n", text) < 0 ||
        fclose(file) != 0) {
        perror("Appending file");
        return 1;
    }
    puts("File updated successfully with appended text.");
    return 0;
}
