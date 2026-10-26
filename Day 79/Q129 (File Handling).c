/*
A file numbers.txt contains a list of integers separated by spaces. Read all integers, compute their sum and average, and print both.
*/

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdarg.h>

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
    FILE *file = fopen("numbers.txt", "r");
    long long value, sum = 0;
    unsigned long long count = 0;
    int scan_result;
    if (file == NULL) { perror("numbers.txt"); return 1; }
    while ((scan_result = fscanf(file, "%lld", &value)) == 1) {
        if ((value > 0 && sum > LLONG_MAX - value) ||
            (value < 0 && sum < LLONG_MIN - value)) {
            fprintf(stderr, "Sum is outside the supported range.\n");
            fclose(file);
            return 1;
        }
        sum += value;
        ++count;
    }
    int read_error = ferror(file);
    if (fclose(file) != 0) read_error = 1;
    if (read_error || scan_result != EOF) {
        fprintf(stderr, "Invalid data while reading numbers.txt.\n");
        return 1;
    }
    if (count == 0) {
        fprintf(stderr, "numbers.txt contains no integers.\n");
        return 1;
    }
    printf("Sum = %lld\nAverage = %.2f\n", sum, (double)sum / (double)count);
    return 0;
}
