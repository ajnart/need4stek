/*
** EPITECH PROJECT, 2019
** my_strcapitalize
** File description:
** Capitalize the first letter of each word.
*/

char *my_strlow(char *str);

char *test_first_letter(char *str, int i);

char *test_if_number_before(char *str, int i);

char *my_strcapitalize(char *str)
{
    int i = 0;

    str = my_strlow(str);
    while (str[i] != '\0') {
        if (str[i] > 96 && str[i] < 123) {
            test_first_letter(str, i);
        }
        i++;
    }
    return (str);
}

char *my_strlow(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] > 64 && str[i] < 91)
            str[i] += 32;
        i++;
    }
    return (str);
}

char *test_first_letter(char *str, int i)
{
    if (str[i - 1] < 65 || str[i - 1] > 90) {
        if (str[i - 1] < 97 || str[i - 1] > 122)
            test_if_number_before(str, i);
    }
    return (str);
}

char *test_if_number_before(char *str, int i)
{
    if (str[i - 1] < 48 || str[i - 1] > 57)
        str[i] -= 32;
    return (str);
}
