/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** Compare two strings
*/

int total_array(char const *str);

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int n = 0;

    while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
        i++;
    n = s1[i] - s2[i];
    return (n);
}
