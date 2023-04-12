/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tools.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 22:06:56 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/12 03:39:33 by aechafii         ###   ########.fr       */
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

void	PhoneBook::set_Contact(void)
{
	std::string input;
	
	std::cout << "First Name : ";
	std::cin >> input;
	PhoneBook::contacts[0].set_FirstName(input);
	std::cout << "Last Name : ";
	std::cin >> input;
	PhoneBook::contacts[0].set_LastName(input);
	std::cout << "NickName : ";
	std::cin >> input;
	PhoneBook::contacts[0].set_NickName(input);
	std::cout << "Phone Number : ";
	std::cin >> input;
	PhoneBook::contacts[0].set_PhoneNumber(input);
	std::cout << "Darkest Secret : ";
	std::cin >> input;
	PhoneBook::contacts[0].set_DarkestSecret(input);
}

void	PhoneBook::prompt(void)
{
	std::cout << "|" << std::right << std::setw(10) << "0" << "|";
	std::cout << std::right << std::setw(10) << PhoneBook::contacts[0].get_FirstName() << "|";
	std::cout << std::right << std::setw(10) << PhoneBook::contacts[0].get_LastName() << "|";
	std::cout << std::right << std::setw(10) << PhoneBook::contacts[0].get_NickName() << "|" << std::endl;
}

void	PhoneBook::PhoneBookList(void) /* Use getters to display the corresponding data */
{ 
	std::cout  << "|-----------*** CONTACT LIST ***------------|" << std::endl;
	std::cout << "|" << std::right << std::setw(10) << "Index" << "|";
	std::cout << std::right << std::setw(10) << "First Name"  << "|";
	std::cout << std::right << std::setw(10) << "Last Name"  << "|";
	std::cout << std::right << std::setw(10) << "Nickname"  << "|" << std:: endl;
	PhoneBook::prompt();
	std::cout << "|-------------------------------------------|" << std::endl;	
}


std::string	PhoneBook::TextTraiter(std::string s)
{
	if (s.length() > 10)
	{
		s.substr(0, 10);
		s[9] = '.';
		std::cout << s << std::endl;
	}
	return (s);
}

void	PhoneBook::Search(PhoneBook &Book)
{
	Book.PhoneBookList();
	Book.TextTraiter(Book.contacts->get_FirstName());
}

void	PhoneBook::Exit(void)
{
	exit(0);
}