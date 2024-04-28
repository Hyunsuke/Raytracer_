##
## EPITECH PROJECT, 2023
## raytracer
## File description:
## Makefile
##

SRC_ALL = src/main.cpp 				\
		  src/core/raytracer.cpp 		\
		  src/core/check_and_parse.cpp 	\

SfmlS = -lsfml-graphics -lsfml-window -lsfml-system

CPPFLAGS = -W -Wall -Wextra -Iinclude -lconfig++

CC = g++ -g

NAME = raytracer

OBJ = $(SRC_ALL:.cpp=.o)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS) $(SfmlS)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
