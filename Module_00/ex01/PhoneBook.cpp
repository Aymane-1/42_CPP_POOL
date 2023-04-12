/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 22:02:33 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/12 21:43:59 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook 	Book;
	int			i;
	int			Flag;
	int			ContactIndex;
	std::string Input;

	i = 0;
	Flag = 0;
	ContactIndex = 0;
	Book.entry_display();
	while (1)
	{
		// system("CLEAR");
		std::cout << "ENTER A COMMAND :" << std::endl;
		std::cin >> Input;
		Flag = Book.check_input(Input);
		if (Flag)
		{
			if (i > 7)
				i = 0;
			if (Flag == 1)
			{
				Book.set_Contact(i);
				i++;
			}
			if (Flag == 2)
				Book.Search();
			if (Flag == 3)
				Book.Exit();
		}
	}
}