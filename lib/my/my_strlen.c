/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** Count and return the number of characters found in the string.
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i += 1;
    }
    return (i);
}
