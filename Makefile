##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

NAME	=	my_hunter

SRC		=	my_hunter.c \
			duck/display_duck.c \
			flag_h.c \
			handle_music.c \
			heart.c \
			crosshair_bg_go.c \
			destroy.c

FLAGS	=	-lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

all:	$(NAME)

$(NAME):	$(SRC)
	gcc -g3 -o $(NAME) $(SRC) $(FLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
