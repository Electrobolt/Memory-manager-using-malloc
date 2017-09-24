#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: banthony <banthony@students.42.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 16:22:07 by banthony          #+#    #+#              #
#    Updated: 2017/09/24 15:34:20 by banthony         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME1 = libft_malloc_$(HOSTTYPE).so

NAME2 = libft_malloc.so

PATH_SRC = ./src/

PATH_LIBFT = ~/libft/

PATH_HEAD = ./include/

HEADER_FILE = malloc.h	\

SRC_FILE = 	malloc.c	main.c\

SRC = $(SRC_FILE:%c=$(PATH_SRC)%c)

INCLUDE = $(HEADER_FILE:%h=$(PATH_HEAD)%h)

OBJ = $(SRC_FILE:.c=.o)

OBJ2 = $(OBJ:%.o=$(PATH_SRC)%.o)

HEAD_DIR = -I ./include -I $(PATH_LIBFT)

LIB = -L $(PATH_LIBFT)  -lft

FLAGS = -Wall -Wextra -Werror -g3 #-Weverything #-fsanitize=address

all: $(NAME2)

$(NAME2): $(SRC) $(INCLUDE)
	make -C $(PATH_LIBFT) debug
	gcc $(FLAGS) $(HEAD_DIR) -c $(SRC)
	mv $(OBJ) $(PATH_SRC)
	gcc -o $(NAME1) -shared $(OBJ2) $(HEAD_DIR) $(LIB) $(FLAGS)
	ln -s $(NAME1) $(NAME2)

test: $(NAME2) $(SRC)
	gcc $(FLAGS) $(NAME2) $(HEAD_DIR) $(LIB) ./src/main.c

real: $(SRC) $(INCLUDE)
	make -C $(PATH_LIBFT) debug
	gcc $(FLAGS) $(HEAD_DIR) -c $(SRC)
	mv $(OBJ) $(PATH_SRC)
	gcc -o real_malloc $(OBJ2) $(HEAD_DIR) $(LIB) $(FLAGS)

clean:
	make clean -C $(PATH_LIBFT)
	rm -f $(OBJ2)
	rm -rf ./a.out a.out.dSYM ./real_malloc ./real_malloc.dSYM

fclean: clean
	rm -f $(NAME2) $(NAME1)
	make fclean -C $(PATH_LIBFT)

re: fclean all