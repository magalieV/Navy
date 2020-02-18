##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	my_showmem.c			\
		my_str_isprintable.c		\
		my_compute_power_rec.c		\
		my_showstr.c			\
		my_str_isupper.c		\
		my_compute_square_root.c	\
		my_show_word_array.c		\
		my_strlen.c			\
		my_find_prime_sup.c		\
		my_sort_int_array.c		\
		my_strlowcase.c			\
		my_getnbr.c			\
		my_strcapitalize.c		\
		my_strncat.c			\
		my_strcat.c			\
		my_strncmp.c			\
		my_isneg.c			\
		my_strcmp.c			\
		my_strncpy.c			\
		my_is_prime.c			\
		my_strcpy.c			\
		my_strstr.c			\
		my_putchar.c			\
		my_strdup.c			\
		my_str_to_word_array.c		\
		my_put_nbr.c			\
		my_put_nbr_base.c		\
		my_put_nbr_basebis.c		\
		my_str_isalpha.c		\
		my_strupcase.c			\
		my_putstr.c			\
		my_str_islower.c		\
		my_swap.c			\
		my_revstr.c			\
		my_str_isnum.c			\
		my_returnstr.c			\
		my_str_isinlexicode.c		\
		my_printf.c			\
		my_rprintf.c			\
		my_fprintf.c			\
		my_frprintf.c			\
		my_get_putchar.c		\
		my_get_put_nbr_base.c		\
		my_get_put_nbr_basebis.c	\
		my_get_put_color.c		\
		my_get_put_emoji.c		\
		my_get_stroctal.c		\
		my_get_putstrmax.c		\
		my_get_to_line.c		\
		number.c			\
		char_append.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
