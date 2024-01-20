#*********************************************************#
#                                                         #
#                                                         #
#    Makefile                                             #
#                                                         #
#    By: banthony <banthony@students.42.fr>               #
#    Recoded by: Electrobolt <pharelledo06@gmail.com>     #
#                                                         #
#    Created: 2015/11/23 16:22:07 by banthony             #
#    Updated: 2023/11/22 19:25:20 by Electrobolt          #
#                                                         #
#*********************************************************# 

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME1 = libft_malloc_$(HOSTTYPE).so

NAME2 = libft_malloc.so

PATH_SRC = ./src/

PATH_TEST = ./maintest/

PATH_HEAD = ./include/

HEADER_FILE = malloc.h	\

SRC_FILE = 	malloc.c			realloc.c			show_alloc_mem_ex.c	free.c			\
			show_alloc_mem.c	ft_memset.c			ft_strncpy.c		ft_memcpy.c		\
			ft_putchar.c		ft_strlen.c			ft_putnbrendl.c		ft_putstr.c		\
			ft_putstrcol.c		ft_putchar_base.c	ft_print_memory.c	ft_print_ptr.c	\
			ft_putendl.c		ft_putnbr.c			\

MAIN_FILE =	test5.c	\

SRC = $(SRC_FILE:%c=$(PATH_SRC)%c)

MAIN = $(MAIN_FILE:%c=$(PATH_TEST)%c)

INCLUDE = $(HEADER_FILE:%h=$(PATH_HEAD)%h)

OBJ = $(SRC_FILE:.c=.o)

MAIN_O = $(MAIN_FILE:.c=.o)

OBJ2 = $(OBJ:%.o=$(PATH_SRC)%.o)

MAIN_O2 = $(MAIN_O:%.o=$(PATH_TEST)%.o)

HEAD_DIR = -I ./include

FLAGS = -Wall -Wextra -Werror -g3 -Weverything

all: $(NAME2)

$(NAME2): $(SRC) $(INCLUDE)
	gcc $(FLAGS) $(HEAD_DIR) -c $(SRC)
	mv $(OBJ) $(PATH_SRC)
	gcc -o $(NAME1) -shared $(OBJ2) $(HEAD_DIR) $(FLAGS)
	ln -s $(NAME1) $(NAME2)

clean:
	rm -f $(OBJ2)
	rm -f $(MAIN_O2)
	rm -rf ./a.out a.out.dSYM ./real_malloc ./real_malloc.dSYM

fclean: clean
	rm -f $(NAME2) $(NAME1)

re: fclean all