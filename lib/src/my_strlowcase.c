/*
** EPITECH PROJECT, 2019
** my_strlowcase
** File description:
** Lowcase characters in a string
*/

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] > 64 && str[i] < 91)
            str[i] += 32;
        i++;
    }
    return (str);
}
