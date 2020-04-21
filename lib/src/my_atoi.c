/*
** EPITECH PROJECT, 2019
** my_atoi_functions
** File description:
** Array to Int
*/

#include "my.h"

int my_sign(char const *car)
{
    int i = 0;

    while (car[i] != '+' && car[i] != '-' && car[i] != '\0') {
        i = i + 1;
    }
    if ((car[i] == '+' || car[i] == '\0') && (car[i + 1] != '-'))
        return (1);
    else
        return (-1);
    return (1);
}

int my_atoi(char const *car)
{
    int result = 0;
    int ntime = 1;
    int longueur = my_strlen(car) - 1;

    while (longueur >= 0 && car[longueur] >= '0' && car[longueur] <= '9') {
        result = result + ((car[longueur] - 48) * ntime);
        longueur = longueur - 1;
        ntime = ntime * 10;
    }
    result = result * my_sign(car);
    return (result);
}