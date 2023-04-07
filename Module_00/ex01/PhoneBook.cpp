/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 22:02:33 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/07 01:24:36 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AwesomePhoneBook.hpp"

int main()
{
	Contact 	NewContact[8];
	PhoneBook 	Book;
	int			Flag;
	int			ContactIndex;
	std::string Input;

	Flag = 0;
	ContactIndex = 0;
	Book.entry_display();
	while (1)
	{
		std::cout << "ENTER A COMMAND :" << std::endl;
		std::cin >> Input;
		Flag = Book.check_input(Input);
		if (Flag)
		{
			if (Flag == 1)
				Book.Add(NewContact[0]);
			if (Flag == 2)
				Book.Search(Book);
			if (Flag == 3)
				Book.Exit();
		}
	}
}