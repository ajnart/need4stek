/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** Function that displays the number given
*/

#include "my.h"

int my_put_nbr(int nb)
{
    int character;

    if (nb < 0) {
        my_putchar('-');
        nb = (nb * -1);
        my_put_nbr(nb);
    } else {
        if (nb >= 10) {
            character = (nb % 10);
            nb = (nb - character) / 10;
            my_put_nbr(nb);
            my_putchar(48 + character);
        } else {
            my_putchar(48 + nb);
            return (0);
        }
    }
    return (0);
}
