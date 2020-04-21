##
## EPITECH PROJECT, 2019
## tests Makefile
## File description:
## Makefile
##

SRC		=

TEST	=	test_function.c

CRITERION	=	--coverage -lcritertion

LIB		=	-L ./lib -lmy

all:
	dolib
	tests

dolib:
	make -C ../lib/my/

tests:
	$(CC) -o test $(CFLAGS) $(TEST) $(SRC) --coverage
	./test
	gcovr --exclude tests/
	rm -fv test
	mkdir -p gc
	mv *.gcda gc/
	mv *.gcdo gc/

clean:
	rm -f /gc/*

fclean:	clean

re : fclean all

.PHONY: all clean fclean re bonus tests