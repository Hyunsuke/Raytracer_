##
## EPITECH PROJECT, 2023
## raytracer
## File description:
## Makefile
##

SRCDIR = src

SRC_ALL = $(wildcard $(SRCDIR)/*.cpp) $(wildcard $(SRCDIR)/*/*.cpp) $(wildcard $(SRCDIR)/*/*/*.cpp)
SRC_OBJ = $(SRC_ALL:.cpp=.o)

SfmlS = -lsfml-graphics -lsfml-window -lsfml-system

CPPFLAGS = -W -Wall -Wextra -Iinclude -lconfig++

CC = g++ -g

NAME = raytracer

$(NAME): $(SRC_OBJ)
	$(CC) -o $@ $^ $(CPPFLAGS) $(SfmlS)

all: $(NAME)

clean:
	rm -f $(SRC_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

