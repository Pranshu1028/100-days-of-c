/*
Write a program that reads text from input.txt, converts all lowercase letters to uppercase, and writes the result to output.txt.
*/

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE *input = fopen("input.txt", "r");
    FILE *output;
    int ch;
    if (input == NULL) { perror("input.txt"); return 1; }
    output = fopen("output.txt", "w");
    if (output == NULL) { perror("output.txt"); fclose(input); return 1; }
    while ((ch = fgetc(input)) != EOF) {
        if (fputc(toupper((unsigned char)ch), output) == EOF) {
            perror("Writing output.txt");
            fclose(input);
            fclose(output);
            return 1;
        }
    }
    if (ferror(input) || fclose(input) != 0 || fclose(output) != 0) return 1;
    return 0;
}
