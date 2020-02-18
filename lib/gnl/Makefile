##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	get_next_line.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libgnl.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
