## EPITECH PROJECT, 2023
## raytracer
## File description:
## Makefile
##

LIB_DIR = ../../libs
LIB_NAME = libsphere.so

CPPFLAGS = -W -Wall -Wextra -lconfig++ -fPIC

CC = g++ -g

SRC = Sphere.cpp
UTILITIES_SRC = $(wildcard ../../Utilities/*.cpp)

all: $(LIB_DIR)/$(LIB_NAME)

$(LIB_DIR)/$(LIB_NAME): $(SRC) $(UTILITIES_SRC)
	$(CC) -shared -o $@ $^ $(CPPFLAGS)

clean:
	rm -f $(LIB_DIR)/$(LIB_NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
