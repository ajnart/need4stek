##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## compile all
##

SRC	=	my_show_word_array.c \
		my_sort_int_array.c \
		my_strcapitalize.c \
		my_strcat.c \
		my_strcmp.c \
		my_strcpy.c \
		my_strdup.c \
		my_getnbr.c \
		my_isneg.c \
		my_strlen.c \
		my_strlowcase.c \
		my_strncat.c \
		my_putchar.c \
		my_strncmp.c \
		my_put_nbr.c \
		my_strncpy.c \
		my_putstr.c \
		my_strstr.c \
		my_revstr.c \
		my_strupcase.c \
		my_showstr.c \
		my_swap.c \
		my_str_nbcmp.c	\
		my_strcat_bien.c	\
		my_compute_power_rec.c	\
		my_atoi.c	\
		my_ctoa.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
	cp my.h ../../include/my.h

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) ../$(NAME)

re:	fclean all
