#include <string.h>
#include "roman.h"

typedef struct {
    int arabic;
    char * roman;
} Numeral; 

Numeral numerals[] = {
    { 1000, "M" },
    { 900, "CM" },
    { 500, "D" },
    { 400, "CD" },
    { 100, "C" },
    { 90, "XC" },
    { 50, "L" },
    { 40, "XL" },
    { 10, "X" },
    { 9, "IX" },
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

void to_roman(int const arabic, char *roman)
{
    int remaining = arabic;
    while (remaining > 0) {
        strcat(roman, next_highest_digit(&remaining));
    }
}

int convert_digit(char const *digit)
{
    int i;
    for (i = 0; numerals[i].arabic != 0; i++) {
        if (strcmp(digit, numerals[i].roman) == 0) {
            return numerals[i].arabic;
        }
    }
    return -1;
}

int to_arabic(char const *roman)
{
    if (strlen(roman) == 1) {
        return convert_digit(roman);    
    } 

    return -1;
}
