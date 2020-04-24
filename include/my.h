/*
** EPITECH PROJECT, 2019
** my
** File description:
** prototypes of functions
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <criterion/criterion.h>

#define UNUSED(x) (void)(x)

void my_putchar(char);
char *my_ctoa(char);
int my_atoi(char const *);
char *my_strcat_bien(char *, char *);
int my_str_abs_cmp(char *, char *);
int my_str_nbcmp(char *, char *);
char *my_strdup(char const *);
int my_isneg(int);
int my_put_nbr(int);
void my_swap(int *, int *);
int my_putstr(char const *);
int my_strlen(char const *);
int my_getnbr(char const *);
void my_sort_int_array(int *, int);
int my_compute_power_rec(int, int);
int my_compute_square_root(int);
int my_is_prime(int);
int my_find_prime_sup(int);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);
char *my_revstr(char *);
char *my_strstr(char *, char const *);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);
char *my_strupcase(char *);
char *my_strlowcase(char *);
char *my_strcapitalize(char *);
int my_str_isalpha(char const *);
int my_str_isnum(char const *);
int my_str_islower(char const *);
int my_str_isupper(char const *);
int my_str_isprintable(char const *);
int my_showstr(char const *);
int my_showmem(char const *, int);
char *my_strcat(char *, char const *);
char *my_strncat(char *, char const *, int);
int my_print_alpha(void);
int  my_print_comb2(void);
int my_print_comb(void);
int my_print_digits(void);
int my_print_revalpha(void);
char *test_first_letter(char *, int);
int shownbr_base(int nbr, int length, char const *base);
int my_putnbr_base(int nbr, char const *base);
int my_putnbr_base_unsigned(unsigned long nbr, char const *base);
int shownbr_base_unsigned(unsigned long nbr, int length, char const *base);
void my_sprintf(char *buf, char const *ap, ...);
char **my_str_to_wordtab(char *str, char g);
char *get_next_line(int fd);
int my_printf(const char *str, ...);
#endif /* MY_H_ */
