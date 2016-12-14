# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 11:49:34 by oslutsky          #+#    #+#              #
#    Updated: 2016/11/16 14:41:30 by oslutsky         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
SRC = help_funcs.c input.c main.c map_creating.c map_processing.c
OBJ = $(SRC:.c=.o)
CFLAGS = -c -Wall -Wextra -Werror
OFLAGS = -o
CC = gcc 

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(OFLAGS) $(NAME)
.c.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -f $(OBJ)
fclean:
	make clean
	rm -f $(NAME)
re:
	make fclean
	make all
