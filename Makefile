# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/03 01:34:47 by knzeng-e          #+#    #+#              #
#    Updated: 2016/04/03 01:49:10 by knzeng-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = ./srcs/*

HEAD = ./includes

CC = gcc

FLAGS = -c -Wall -Werror -Wextra

OBJ = *.o

all:
	$(CC) $(FLAGS) $(SRCS) -I$(HEAD)
	$(CC) $(OBJ) -o $(NAME)

clean: all
	rm $(OBJ)

fclean : clean
	rm $(NAME)

re: fclean
	make all
