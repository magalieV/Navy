##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Navi
##

CC	=	gcc -o

RM	=	rm -f

SRC	=	src/get_order.c		\
		src/send_order.c	\
		src/sycrom.c		\
		src/player_a.c		\
		src/map.c		\
		src/map_two.c		\
		src/player_one.c

SRC_T	=	tests/test_navy.c	\
		tests/test_navy_two.c

OBJ	=	$(SRC:.c=.o) $(SRC_T:.c=.o)

CFLAGS	+=	-I./tests/ --coverage

LIB	=	-L./lib/my -lmy			\
		-L./lib/gnl/ -lgnl -lcriterion

NAME	=	unit_tests

all:	$(NAME)

$(NAME):	libc
	make -C ./src/ all

%.o:	%.c
	gcc -c -o $@ $< $(CFLAGS)

clean:
	make -C ./src/ clean
	make -C ./lib/my/ clean
	make -C ./lib/gnl/ clean

fclean:
	make -C ./src/ fclean
	make -C ./lib/my/ fclean
	make -C ./lib/gnl/ fclean

re:	fclean all

tests_run:	fclean libc $(OBJ)
	$(CC) $(NAME) $(OBJ) $(LIB) $(CFLAGS)
	./$(NAME)
	make fclean

wre:
	make -C ./src/ re

libc:
	make -C ./lib/my/ all
	make -C ./lib/gnl/ all
