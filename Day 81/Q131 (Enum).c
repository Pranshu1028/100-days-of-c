/*
Create an enumeration for days (SUNDAY to SATURDAY) and print each day with its integer value.
*/

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    enum Day { SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY };
    static const char *names[] = {
        "SUNDAY", "MONDAY", "TUESDAY", "WEDNESDAY",
        "THURSDAY", "FRIDAY", "SATURDAY"
    };
    for (enum Day day = SUNDAY; day <= SATURDAY; day = (enum Day)(day + 1))
        printf("%s = %d\n", names[day], day);
    return 0;
}
