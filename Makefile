# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/03 01:34:47 by knzeng-e          #+#    #+#              #
#    Updated: 2016/04/17 01:12:15 by knzeng-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC_PATH = ./srcs/
SRC_NAME = $(shell ls $(SRC_PATH) | grep .c)
INC_PATH = ./includes/
OBJ_PATH = ./obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
	SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
	OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
#SRCS = ./srcs/*

#HEAD = ./includes
#CC = gcc

FLAGS = -Wall -Werror -Wextra

#OBJ = *.o

all : $(NAME)

#$(NAME) :
#	$(CC) $(FLAGS) $(SRCS) -I$(HEAD)
#	$(CC) $(OBJ) $(LIB) -o $(NAME)

$(NAME) : $(OBJ)
	@echo "Compile all .c files"
	@echo "Linking all .o files and obtain fillit binary"
	@$(CC) $(FLAGS) -I $(INC_PATH) $(OBJ) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || echo '' > /dev/null
	@gcc $(FLAGS) -I $(INC_PATH) -o $@ -c $<

clean :
	@echo "Remove all .o files"
	@rm $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo '' > /dev/null

fclean : clean
	rm $(NAME)

norme :
	norminette $(INC_PATH) $(SRC_PATH)

re : fclean all

.PHONY : all clean fclean norme re
