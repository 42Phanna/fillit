#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/02 18:09:27 by jcoutare          #+#    #+#              #
#    Updated: 2017/05/12 15:50:51 by phanna           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

CC = gcc

INCLUDES += -I libft.h

CFLAGS += -Wall -Wextra -Werror $(INCLUDES)

SRC =	main.c \
		ft_read.c

OBJ = $(SRC:.c=.o)

all : 		$(NAME)

$(NAME) :	$(OBJ)
			$(CC) $(CFLAGS) -o $(NAME)

clean :
			rm -f $(OBJ)
fclean : 	clean
			rm -f fillit
re : 		fclean all
