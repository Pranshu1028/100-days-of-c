/*
Take two filenames from the user – a source file and a destination file. Copy all the content from the source file to the destination file using fgetc() and fputc().
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
    char source[256], destination[256];
    int ch;
    FILE *input, *output;
    if (scanf("%255s %255s", source, destination) != 2) return 1;
    if (strcmp(source, destination) == 0) {
        fprintf(stderr, "Source and destination must be different files.\n");
        return 1;
    }
    input = fopen(source, "rb");
    if (input == NULL) { perror(source); return 1; }
    output = fopen(destination, "wb");
    if (output == NULL) {
        perror(destination);
        fclose(input);
        return 1;
    }
    while ((ch = fgetc(input)) != EOF) {
        if (fputc(ch, output) == EOF) {
            perror("Writing destination");
            fclose(input);
            fclose(output);
            return 1;
        }
    }
    if (ferror(input) || fclose(input) != 0 || fclose(output) != 0) {
        perror("Copying file");
        return 1;
    }
    printf("File copied successfully to %s\n", destination);
    return 0;
}
