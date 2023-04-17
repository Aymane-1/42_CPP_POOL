# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 00:33:00 by aechafii          #+#    #+#              #
#    Updated: 2023/04/17 02:56:13 by aechafii         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = App

SRC =   main.cpp \
		HumanA.cpp \
		HumanB.cpp \
		Weapon.cpp

HEADER = Weapon.hpp \
		 HumanA.hpp \
		 HumanB.hpp
		
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