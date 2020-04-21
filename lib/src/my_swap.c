/*
** EPITECH PROJECT, 2019
** my_swap
** File description:
** Swap the content of two integers.
*/

#include <stdio.h>

void my_putchar(char);

void my_swap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}
