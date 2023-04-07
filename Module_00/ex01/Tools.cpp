/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 22:06:56 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/07 02:19:09 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AwesomePhoneBook.hpp"

void	PhoneBook::entry_display()
{
		std::cout << "---------------- WELCOME TO THE 80'S CRAPPY PHONEBOOK ----------------" << std::endl;
		sleep(1);
		std::cout << "AVAILABLE COMMANDS ARE :" << std::endl;
		sleep(1);
		std::cout << "--> \e[32;1mADD\e[0m" << std::endl;
		sleep(1);
		std::cout << "--> \e[36;1mSEARCH\e[0m" << std::endl;
		sleep(1);
		std::cout << "--> \e[31;1mEXIT\e[0m" << std::endl;
		sleep(1);
}

int	PhoneBook::check_input(std::string input)
{
	if (input == "ADD")
		return (1);
	if (input == "SEARCH")
		return (2);
	if (input == "EXIT")
		return (3);
	return (0);
	
}

void	PhoneBook::Add(Contact &NewContact)
{
	std::string input;
	
	std::cout << "First Name : ";
	std::cin >> input;
	NewContact.set_FirstName(input);
	std::cout << "Last Name : ";
	std::cin >> input;
	NewContact.set_LastName(input);
	std::cout << "NickName : ";
	std::cin >> input;
	NewContact.set_NickName(input);
	std::cout << "Phone Number : ";
	std::cin >> input;
	NewContact.set_PhoneNumber(input);
	std::cout << "Darkest Secret : ";
	std::cin >> input;
	NewContact.set_DarkestSecret(input);
}

void	PhoneBook::PhoneBookList(Contact Cntct)
{
	std::cout << std::setw(10) << "|-----------*** CONTACT LIST ***------------|" << std::endl;
	std::cout << "|" << std::right << std::setw(10) << "Index" << "|";
	std::cout << std::right << std::setw(10) << "First Name"  << "|";
	std::cout << std::right << std::setw(10) << "Last Name"  << "|";
	std::cout << std::right << std::setw(10) << "Nickname"  << "|" << std:: endl;
	std::cout << std::setw(10) << "|-------------------------------------------|" << std::endl;
	// if (.size)
		
}

void	PhoneBook::Search(PhoneBook &Book)
{
	Book.PhoneBookList();
}

void	PhoneBook::Exit(void)
{
	exit(0);
}