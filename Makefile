##
## EPITECH PROJECT, 2023
## raytracer
## File description:
## Makefile
##

SRCDIR = src
SRCDIRS = $(SRCDIR) $(SRCDIR)/Utilities $(SRCDIR)/core $(SRCDIR)/core/lib
SRC_ALL = $(foreach dir,$(SRCDIRS),$(wildcard $(dir)/*.cpp))
SRC_OBJ = $(SRC_ALL:.cpp=.o)

SfmlS = -lsfml-graphics -lsfml-window -lsfml-system

CPPFLAGS = -W -Wall -Wextra -Iinclude -lconfig++

CC = g++ -g

NAME = raytracer

all: $(NAME)

$(NAME): $(SRC_OBJ)
	$(CC) -o $@ $^ $(CPPFLAGS) $(SfmlS)
	$(MAKE) -C $(SRCDIR)/Primitives/Sphere
	$(MAKE) -C $(SRCDIR)/Primitives/Cylinder
	$(MAKE) -C $(SRCDIR)/Primitives/Plane

clean:
	rm -f $(SRC_OBJ)
	$(MAKE) -C $(SRCDIR)/Primitives/Sphere clean
	$(MAKE) -C $(SRCDIR)/Primitives/Cylinder clean
	$(MAKE) -C $(SRCDIR)/Primitives/Plane clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(SRCDIR)/Primitives/Sphere fclean
	$(MAKE) -C $(SRCDIR)/Primitives/Cylinder fclean
	$(MAKE) -C $(SRCDIR)/Primitives/Plane fclean

re: fclean all

.PHONY: all clean fclean re

