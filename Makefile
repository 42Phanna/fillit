# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phanna <phanna@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/02 18:09:27 by jcoutare          #+#    #+#              #
#    Updated: 2017/07/21 15:39:22 by phanna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIB = libft

SRC =	fillit.c \
		fillit_reader.c \
		tetri_tools.c \
		flt_check.c \
		new_tetri.c \
		solve.c \
		move_tetri.c \
		solve_tools.c \

OBJ = $(SRC:.c=.o)

CC = gcc

LIBPATH = libft/libft.a

CFLAGS = -Wall -Wextra 

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB)
	@gcc -o $(NAME) $(OBJ) $(LIBPATH)

clean:
	@make fclean -C $(LIB)
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)


re: fclean all
