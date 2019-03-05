##
## EPITECH PROJECT, 2018
## makefile
## File description:
## lib
##

SRC	=	src/main.c	\
		src/error.c	\
		src/square.c	\
		src/manage_map.c	\
		src/init.c

NAME	=	bsq

OBJ	=	$(SRC:.c=.o)

COMPIL	=	-lmy -Llib/my

CFLAGS	=	-W -Wall -Wextra -I include/

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my
		gcc -o $(NAME) $(OBJ) $(COMPIL) $(CFLAGS)

clean:	
		rm -f $(OBJ)
		rm -rf *~
		rm -rf src/*~

fclean:		clean
		make fclean -C lib/my
		rm -f $(NAME)

re:		fclean all
