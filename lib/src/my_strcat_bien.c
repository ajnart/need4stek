/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** Concatenate two strings
*/

#include "my.h"
#include <stdlib.h>

char *my_strcat_bien(char *dest, char *src)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char *result;

    result = malloc((sizeof(char)) * (my_strlen(dest) + my_strlen(src) + 1));
    while (dest[j] != '\0') {
        result[i] = dest[j];
        i += 1;
        j += 1;
    }
    while (src[k] != '\0') {
        result[i] = src[k];
        i = i + 1;
        k = k + 1;
    }
    result[i] = '\0';
    return (result);
}
