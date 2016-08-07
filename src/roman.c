#include <string.h>
#include "roman.h"

typedef struct {
    int arabic;
    char * roman;
} Numeral; 

Numeral numerals[] = {
    { 5, "V" },
    { 4, "IV" },
    { 1, "I" },
    { 0, "?" }
};

char * next_highest_digit(int *number)
{
    int i;
    for (i = 0; numerals[i].arabic != 0; i++) {
        if (*number >= numerals[i].arabic) {
            *number -= numerals[i].arabic;
            return numerals[i].roman;
        }
    }
    return "?";
}

void arabic_to_roman(int const arabic, char *roman)
{
    int remaining = arabic;
    while (remaining > 0) {
        strcat(roman, next_highest_digit(&remaining));
    }
}