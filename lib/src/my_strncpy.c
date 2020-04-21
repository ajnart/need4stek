/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** Copy n character from a string into another.
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    char i = 0;

    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i += 1;
    }
    if (i < n)
        dest[i] = '\0';
    return (dest);
}
