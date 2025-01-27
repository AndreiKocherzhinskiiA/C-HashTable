##
## EPITECH PROJECT, 2025
## B-CPE-110-BAR-1-1-secured-mark.charadnik
## File description:
## Makefile
##

NAME = libhashtable

SRC = src/create.c \
      src/delete_entry.c \
	  src/delete.c \
	  src/hash.c \
	  src/insert.c \
	  src/search.c \
	  src/utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
