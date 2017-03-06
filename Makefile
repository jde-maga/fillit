# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nterrier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/16 14:03:45 by nterrier          #+#    #+#              #
#    Updated: 2016/01/27 18:50:35 by nterrier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FUNCT = main.c traitement.c lst.c chr.c

OBJ = $(FUNCT:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -c $(FUNCT)
	$(CC) -o $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)
