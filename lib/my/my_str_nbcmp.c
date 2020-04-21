/*
** EPITECH PROJECT, 2019
** my_str_nbcmp
** File description:
** Compare two strings of char composed of num
*/

#include "my.h"

int my_is_sup(char *, char *);

int my_cmplen(char *, char *);

int my_str_nbcmp(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    int sup = my_is_sup(s1, s2);
    int len = 0;

    if (sup != 0)
        return (sup);
    if (s1[0] == '-')
        i += 1;
    if (s2[0] == '-')
        j += 1;
    len = my_cmplen(&s1[i], &s2[j]);
    if (len != 0)
        return (len);
    while (s1[i] == s2[j] && s1[i] != '\0' && s2[j] != '\0') {
        i += 1;
        j += 1;
        return (s1[i - 1] - s2[j - 1]);
    }
    return (s1[i] - s2[j]);
}

int my_is_sup(char *s1, char *s2)
{
    if (s1[0] == '-' && (s2[0] != '-' || s2[1] != '-'))
        return (-1);
    else if (s1[0] != '-' && (s2[0] == '-' || s2[1] == '-'))
        return (1);
    else
        return (0);
}

int my_cmplen(char *s1, char *s2)
{
    int a = my_strlen(s1);
    int b = my_strlen(s2);

    if (a > b)
        return (1);
    else if (b > a)
        return (-1);
    else
        return (0);
}
