##
## EPITECH PROJECT, 2019
## REPO_Needings
## File description:
## Makefile
##

MAIN	=	src/main.c

SRC		=

OBJ		=	$(SRC:.c=.o) $(MAIN:.c=.o)

NAME	=	unnamed

LIB		=	-L ./lib -lmy

CFLAGS	=	-W -Werror -Wall -Wextra

CPPFLAGS	=	-I ./include

CSFMLFLAGS	=	-l csfml-graphics -l csfml-window -l csfml-system -l csfml-audio

all:	dolib $(NAME)

$(NAME): 	$(OBJ)
	dolib
	gcc -o $(NAME) $(CFLAGS) $(CPPFLAGS) $(OBJ) $(LIB)

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

fclean:	clean
	rm -f $(NAME)
	make -C ./lib/my/ fclean

re: fclean all

bonus:

.PHONY: all clean fclean tests_run dolib res