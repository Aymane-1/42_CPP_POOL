# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/19 00:46:48 by aechafii          #+#    #+#              #
#    Updated: 2023/04/19 00:55:41 by aechafii         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Harl

SRC =   main.cpp \
		Harl.cpp \
		
HEADER = Harl.hpp
		
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