# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 00:25:13 by aechafii          #+#    #+#              #
#    Updated: 2023/05/31 00:27:04 by aechafii         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Convert

SRC =   main.cpp \
		Base.cpp \
		A.cpp    \
		B.cpp    \
		C.cpp    \

		
		
HEADER = Base.hpp A.hpp B.hpp C.hpp
		
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