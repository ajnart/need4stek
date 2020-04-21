/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** Allocate memory and copy the string given as argument.
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    char *str;
    int i = 0;
    int lenght = my_strlen(src) + 1;

    str = malloc(sizeof(char) * lenght);
    while (src[i] != '\0') {
        str[i] = src[i];
        i += 1;
    }
    str[i] = '\0';
    return (str);
}
