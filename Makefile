##
## EPITECH PROJECT, 2023
## raytracer
## File description:
## Makefile
##

SRCDIR = src
SRC_ALL = $(wildcard $(SRCDIR)/*.cpp) $(wildcard $(SRCDIR)/Utilities/*.cpp) $(wildcard $(SRCDIR)/core/*.cpp)
SRC_OBJ = $(SRC_ALL:.cpp=.o)

SfmlS = -lsfml-graphics -lsfml-window -lsfml-system

CPPFLAGS = -W -Wall -Wextra -Iinclude -lconfig++

CC = g++ -g

NAME = raytracer

all: $(NAME)

$(NAME): $(SRC_OBJ)
	$(CC) -o $@ $^ $(CPPFLAGS) $(SfmlS)
	$(MAKE) -C $(SRCDIR)/Primitives/Sphere

clean:
	rm -f $(SRC_OBJ)
	$(MAKE) -C $(SRCDIR)/Primitives/Sphere clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(SRCDIR)/Primitives/Sphere fclean

re: fclean all

.PHONY: all clean fclean re

