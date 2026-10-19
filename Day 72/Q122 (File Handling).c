/*
Write a C program that opens an existing file (e.g., info.txt) and reads its contents using fgets(). The program should print all the lines to the console until EOF (end of file) is reached.
*/

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char line[1024];
    FILE *file = fopen("info.txt", "r");
    if (file == NULL) {
        perror("info.txt");
        return 1;
    }
    while (fgets(line, sizeof(line), file) != NULL) fputs(line, stdout);
    if (ferror(file)) {
        perror("Reading info.txt");
        fclose(file);
        return 1;
    }
    return fclose(file) == 0 ? 0 : 1;
}
