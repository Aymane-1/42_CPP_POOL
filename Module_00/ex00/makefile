# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 03:59:27 by aechafii          #+#    #+#              #
#    Updated: 2023/04/04 00:44:34 by aechafii         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

SRC =  megaphone.cpp

OBJ = $(SRC:.c=.o)

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

all:$(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)
		
%.o:%.c 
	$(CC) $(CFLAGS) -c $< -o $@

fclean:
	rm -rf $(NAME) 

re: fclean all