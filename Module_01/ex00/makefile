# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/16 02:30:30 by aechafii          #+#    #+#              #
#    Updated: 2023/04/16 23:01:41 by aechafii         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Braiiiinnnzzz

SRC =   main.cpp \
		Zombie.cpp \
		newZombie.cpp \
		randomChump.cpp
		
HEADER = Zombie.hpp

OBJ = $(SRC:.c=.o)

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

all:$(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)
	
%.o:%.c 
	$(CC) $(CFLAGS) -c $< -o $@

fclean:
	rm -rf $(NAME) 

re: fclean all 