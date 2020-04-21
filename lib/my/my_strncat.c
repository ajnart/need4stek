/*
** EPITECH PROJECT, 2019
** my_strncat
** File description:
** Concatenate n bytes of two strings
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0')
        i += 1;
    while (src[j] != '\0' && j < nb) {
        dest[i] = src[j];
        i += 1;
        j += 1;
    }
    dest[i] = '\0';
    return (dest);
}
