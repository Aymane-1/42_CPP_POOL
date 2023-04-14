/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 22:02:33 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/13 03:02:56 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook 	Book;
	int			index;
	int			Flag;
	// int			ContactIndex;
	std::string Input;

	index = 0;
	Flag = 0;
	// ContactIndex = 0;
	Book.entry_display();
	while (1)
	{
		std::cout << "\e[90;1mENTER A COMMAND :\e[0m" << std::endl;
		std::cin >> Input;
		Flag = Book.check_input(Input);
		if (Flag)
		{
			if (index > 7)
				index = 0;
			if (Flag == 1)
			{
				system("CLEAR");
				index++;
				Book.set_Contact(index);
			}
			if (Flag == 2)
			{
				system("CLEAR");
				Book.Search(index);
			}
			if (Flag == 3)
				exit(1);
		}
		else
			std::cout << "\e[94;1mTRY ONE OF THE AVAILABLE COMMANDS!\n\e[32;1m    [ADD]  \e[0m \e[36;1m[SEARCH]  \e[0m \e[31;1m[EXIT]\e[0m\e[0m" << std::endl;
	}
}