/*
** EPITECH PROJECT, 2019
** my_show_word_array
** File description:
** Display the content of an array of words.
*/

#include <stddef.h>
#include "my.h"

int my_show_word_array(char * const *tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        my_putstr(tab[i]);
        my_putchar('\n');
        i += 1;
    }
    return (0);
}
