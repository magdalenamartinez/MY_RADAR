##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## funcion which
##

NAME	=	my_radar

LIB1 =	-L lib/my/ -lmy

LIB	=	-lcsfml-audio -lcsfml-system -lcsfml-window -lcsfml-graphics

INCLUDE	=	-I ./include/

SRC	= 	src/main.c	\
		src/bucle.c	\
		src/complete_toweravion.c	\
		src/eventos.c	\
		src/pantalla.c	\
		src/create_struct.c	\
		src/complete_avion.c	\
		src/dibujar.c 	\
		src/dibujar_avion.c	\
		src/int_to_str.c	\
		src/dibujar_timer.c	\
		src/conflicto.c	\
		src/sector.c	\

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): 	$(OBJ)
		gcc -g $(OBJ) -o $(NAME) $(INCLUDE) $(LIB1) $(LIB)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f ./src/*.o

re: fclean all

exec:	re
	./$(NAME)

.PHONY: all clean fclean re exec
