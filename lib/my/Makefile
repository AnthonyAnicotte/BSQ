##
## EPITECH PROJECT, 2018
## makefile
## File description:
## task1
##

SRC	=	my_getnbr.c	\
		my_putstr.c

OBJ 	=	$(SRC:.c=.o)

NAME 	=	libmy.a

all:	$(NAME) clean

$(NAME):	$(OBJ)
	ar  rc	$(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
