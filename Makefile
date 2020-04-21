##
## EPITECH PROJECT, 2018
## My_Makefile
## File description:
## Makefile
##

MAIN	=	src/main.c  \

SRC		=

TEST	=	./tests/test_*.c

FBONUS	=	bonus/*.c

OBJ	=	$(SRC:.c=.o) $(MAIN:.c=.o)

NAME	=	ai

LIB	=	-L ./lib -lmy

CFLAGS	=	-W -Werror -Wall -Wextra

CPPFLAGS	=	-I ./include

CSFMLFLAGS	=	-l csfml-graphics -l csfml-window -l csfml-system -l csfml-audio

all:	dolib $(NAME)

$(NAME): $(OBJ)
	make -C ./lib/my/
	gcc -o $(NAME) $(CFLAGS) $(CPPFLAGS) $(SRC) $(LIB) $(MAIN)

dolib:
	make -C ./lib/my

tests_run:
	dolib
	gcc -o test $(CFLAGS) $(TEST) $(SRC) $(LIB) --coverage -lcriterion
	./test
	gcovr --exclude tests/
	rm test

clean:
	rm -f $(OBJ)
	make -C ./lib/my/ clean
	touch test.gcno
	rm *.gc*

fclean:	clean
	rm -f $(NAME)
	make -C ./lib/my/ fclean

re: fclean all

bonus:

.PHONY: all clean fclean re bonus tests_run
