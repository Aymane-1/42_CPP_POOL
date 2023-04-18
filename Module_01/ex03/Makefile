# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 00:33:00 by aechafii          #+#    #+#              #
#    Updated: 2023/04/18 02:08:56 by aechafii         ###   ########.fr        #
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
		
OBJ = $(SRC:.cpp=.o)

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

all:$(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)
	
%.o:%.cpp $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) 

re: fclean all 