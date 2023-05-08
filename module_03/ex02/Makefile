# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 16:12:58 by aechafii          #+#    #+#              #
#    Updated: 2023/05/08 15:05:02 by aechafii         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = App

SRC =   main.cpp \
		ClapTrap.cpp  \
		ScavTrap.cpp \
		FragTrap.cpp
		
HEADER = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp
		
OBJ = $(SRC:.cpp=.o)

CC = c++

CFLAGS = -Wall -Werror -Wextra

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