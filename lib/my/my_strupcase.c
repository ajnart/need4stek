/*
** EPITECH PROJECT, 2019
** my_strupcase
** File description:
** Upcase characters in a string
*/

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] > 96 && str[i] < 123)
            str[i] -= 32;
        i++;
    }
    return (str);
}
