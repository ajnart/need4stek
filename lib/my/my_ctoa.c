/*
** EPITECH PROJECT, 2019
** my ctoa
** File description:
** Char to array
*/

#include "my.h"

char *my_ctoa(char car)
{
    char *result;

    result = malloc((sizeof(char)) * 2);
    result[0] = car;
    result[1] = '\0';
    return (result);
}