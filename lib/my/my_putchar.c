/*
** EPITECH PROJECT, 2019
** my_putchar
** File description:
** display a character on the screen
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
