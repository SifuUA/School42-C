# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 11:49:34 by oslutsky          #+#    #+#              #
#    Updated: 2016/12/16 14:29:30 by oslutsky         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = main.c ft_arr_putstr.c get_figure_from_string.c
OBJ = $(SRC:.c=.o)
CFLAGS = -c -Wall -Wextra -Werror 
OFLAGS = -L"./" -lft -o $(NAME)
CC = gcc 

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(OFLAGS)
.c.o:
	$(CC) $(CFLAGS) $<
clean:
	rm -f $(OBJ)
fclean:
	make clean
	rm -f $(NAME)
re:
	make fclean
	make all
