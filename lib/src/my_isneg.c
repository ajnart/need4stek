/*
** EPITECH PROJECT, 2019
** my_isneg
** File description:
** Function that displays N if negative, P if positive or null.
*/

#include "my.h"

int my_isneg(int n)
{
    if (n >= 0) {
        my_putchar(80);
    } else {
        my_putchar(78);
    }
    return (0);
}
