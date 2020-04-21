/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** return a number sent to the function as a string.
*/

int is_str_nbr(char const *, int *, int *);

int my_getnbr(char const *str)
{
    int i = 0;
    int nbr = 0;
    int debut = 0;

    while (str[i] < '0' || str[i] > '9')
        i += 1;
    debut = i;
    while (str[i] != '\0') {
        is_str_nbr(str, &i, &nbr);
        if ((i - debut) > 10)
            return (0);
    }
    nbr /= 10;
    if (debut >= 1 && str[debut - 1] == '-')
        return (-1 * nbr);
    else
        return (1 * nbr);
}

int is_str_nbr(char const *str, int *i, int *nbr)
{
    if (str[*i] < '0' || str[*i] > '9')
        return (0);
    else {
        *nbr += str[*i] - 48;
        *nbr *= 10;
        *i += 1;
        return (0);
    }
}
