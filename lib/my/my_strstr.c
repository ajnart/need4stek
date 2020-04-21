/*
** EPITECH PROJECT, 2019
** my_strstr
** File description:
** Return a pointer ton a str in a str
*/

#include <stddef.h>

int compare_str(int i, char *str, char const *to_find);

char *my_strstr(char *str, char const *to_find)
{
    int start = 0;
    int i = 0;

    if (str == NULL || to_find == NULL)
        return (NULL);
    while (str[i] != '\0') {
        if (str[i] == to_find[0])
            start = i;
        if (compare_str(i, str, to_find) == 1) {
            return (&str[start]);
        }
        i++;
    }
    return (NULL);
}

int compare_str(int i, char *str, char const *to_find)
{
    int j = 0;

    while (str[i] == to_find[j] && str[i] != '\0' && to_find[j] != '\0') {
        i++;
        j++;
    }
    if (to_find[j] == '\0') {
        return (1);
    }
    return (0);
}
