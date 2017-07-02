# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phanna <phanna@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/02 18:09:27 by jcoutare          #+#    #+#              #
#    Updated: 2017/07/03 00:04:08 by phanna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIB = libft

SRC =	fillit.c \
		ft_read.c \
		ft_usage.c \
		ft_get_map_size.c \
		ft_new_pos.c \
		ft_check.c \
		ft_move_tetri.c \

OBJ = $(SRC:.c=.o)

CC = gcc

LIBPATH = libft/libft.a

CFLAGS = -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB)
	gcc -o $(NAME) $(OBJ) $(LIBPATH)

clean:
	make fclean -C $(LIB)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
