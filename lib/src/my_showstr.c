/*
** EPITECH PROJECT, 2019
** my_showstr
** File description:
** print a string with non printable characters hexadecimally
*/

#include "my.h"

void my_put_hexa(int dec);

int my_showstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] <= 31 || str[i] >= 127) {
            my_putchar('\\');
            my_put_hexa(str[i]);
        }
        else
            my_putchar(str[i]);
        i += 1;
    }
    return (0);
}

void my_put_hexa(int dec)
{
    if (dec / 16 < 10)
        my_put_nbr(dec / 16);
    else
        my_putchar(dec / 16 + 87);
    if (dec % 16 < 10)
        my_put_nbr(dec % 16);
    else
        my_putchar(dec % 16 + 87);
}
