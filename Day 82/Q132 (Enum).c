/*
Define an enum for traffic lights (RED, YELLOW, GREEN) and print 'Stop', 'Wait', or 'Go' based on its value.
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
    enum TrafficLight { RED, YELLOW, GREEN };
    char input[32];
    enum TrafficLight light;
    if (scanf("%31s", input) != 1) return 1;
    if (strcmp(input, "RED") == 0) light = RED;
    else if (strcmp(input, "YELLOW") == 0) light = YELLOW;
    else if (strcmp(input, "GREEN") == 0) light = GREEN;
    else { fprintf(stderr, "Unknown traffic light.\n"); return 1; }
    switch (light) {
        case RED: puts("Stop"); break;
        case YELLOW: puts("Wait"); break;
        case GREEN: puts("Go"); break;
    }
    return 0;
}
