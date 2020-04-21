/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** Reverse a string.
*/

#include "my.h"

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int i = 0;
    int lenght = my_strlen(str);
    char letter;

    while (i <= lenght / 2) {
        letter = str[i];
        str[i] = str[lenght - i];
        str[lenght - i] = letter;
        i += 1;
    }
    return (str);
}
