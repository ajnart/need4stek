/*
** EPITECH PROJECT, 2019
** AIA_n4s_2019
** File description:
** printf.h
*/

#ifndef __MY_PRINTF__
#define __MY_PRINTF__
#include <stdarg.h>

/* bases.c */
void funct_per(va_list arg);
void funct_bin(va_list arg);
void funct_hexa(va_list arg);
void funct_hexa_maj(va_list arg);
void funct_ptr(va_list arg);
/* my_printf.c */
int check_flag(char c);
int my_printf(const char *str, ...);
/* strings.c */
void funct_int(va_list arg);
void funct_cha(va_list arg);
void funct_str(va_list arg);
void funct_octa(va_list arg);
void funct_str_maj(va_list arg);
/* unsigned.c */
void funct_unsign_int(va_list arg);
void disp_nbr_unsigned(unsigned int nb);
int my_put_nbr_unsigned(unsigned int nb);

#endif