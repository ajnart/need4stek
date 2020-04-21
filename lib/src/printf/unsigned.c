/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** functs_3.c
*/

#include <stdlib.h>
#include <stdarg.h>
#include "../my.h"
#include "my_printf.h"

void funct_unsign_int(va_list arg)
{
    my_put_nbr_unsigned(va_arg(arg, unsigned int));
}

void disp_nbr_unsigned(unsigned int nb)
{
    char n;

    if (nb > 0) {
        n = nb % 10 + '0';
        disp_nbr_unsigned(nb / 10);
        my_putchar(n);
    }
}

int my_put_nbr_unsigned(unsigned int nb)
{
    char n;

    if (nb == 0) {
        my_putchar('0');
        return (1);
    } else {
        n = nb % 10 + '0';
        disp_nbr_unsigned(nb / 10);
        my_putchar(n);
    }
    return (0);
}