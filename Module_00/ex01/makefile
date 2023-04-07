# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 21:59:56 by aechafii          #+#    #+#              #
#    Updated: 2023/04/06 22:46:14 by aechafii         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PhoneBook

SRC =   PhoneBook.cpp \
		ClassMemberFunc.cpp  \
		Tools.cpp

HEADER = AwesomePhoneBook.hpp

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