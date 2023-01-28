##
## NAVY PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC =	main.c					\
	src/open_read_and_parse.c 	\
	src/print_map.c 			\
	src/print_map2.c			\
	src/print_boat_defense.c 	\
	src/print_boat_attack.c 	\
	src/parsing_error_handling.c\
	src/connect_terminals.c 	\
	lib/my_putchar.c			\
	lib/my_putstr.c				\
	lib/my_strlen.c             \
	lib/my_put_nbr.c 			\
	lib/my_getnbr.c 			\
	lib/my_strcat.c 			\
	lib/my_strcpy.c 			\
	lib/word_array_delimit.c 	\
	lib/word_array_non_alpha.c  \
	lib/word_array_two_points.c \

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
