##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Navy
##

CC	=	gcc -o

RM	=	rm -f

MAIN	=	main.c

SRC	=	get_order.c	\
		send_order.c	\
		sycrom.c	\
		player_a.c	\
		map.c		\
		map_two.c	\
		player_one.c

OBJ	=	$(SRC:.c=.o) $(MAIN:.c=.o)

CFLAGS	=       -I../include/

LIB	=	-L../lib/my -lmy -L../lib/gnl -lgnl

NAME	=	../navy

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(NAME) $(OBJ) $(LIB)

%.o:	%.c
	gcc -c -o $@ $< $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all
