##
## NAVY PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC =	main.c					\
	lib/my_putchar.c			\
	lib/my_putstr.c				\
	lib/my_strlen.c             \
	lib/my_put_nbr.c 			\
	lib/my_getnbr.c 			\
	lib/my_strcat.c 			\
	lib/my_strcpy.c 			\
	lib/word_array_delimit.c 	\
	lib/word_array_non_alpha.c  \

OBJ =	$(SRC:.c=.o)

CPPFLAGS = -I include

NAME =	navy

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	$(RM) -f $(OBJ)
	$(RM) -f *~

fclean: clean
	rm -f $(NAME)

re: fclean all
