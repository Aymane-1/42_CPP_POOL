/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tools.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 22:06:56 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/12 22:08:39 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

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

void	PhoneBook::set_Contact(int index)
{
	std::string input;
	
	std::cout << "First Name : ";
	std::cin >> input;
	PhoneBook::contacts[index].set_FirstName(input);
	std::cout << "Last Name : ";
	std::cin >> input;
	PhoneBook::contacts[index].set_LastName(input);
	std::cout << "NickName : ";
	std::cin >> input;
	PhoneBook::contacts[index].set_NickName(input);
	std::cout << "Phone Number : ";
	std::cin >> input;
	PhoneBook::contacts[index].set_PhoneNumber(input);
	std::cout << "Darkest Secret : ";
	std::cin >> input;
	PhoneBook::contacts[index].set_DarkestSecret(input);
}

void	PhoneBook::prompt(void)
{
	std::cout << "|" << std::right << std::setw(10) << "0" << "|";
	std::cout << std::right << std::setw(10) << PhoneBook::contacts[0].get_FirstName() << "|";
	std::cout << std::right << std::setw(10) << PhoneBook::contacts[0].get_LastName() << "|";
	std::cout << std::right << std::setw(10) << PhoneBook::contacts[0].get_NickName() << "|" << std::endl;
}

void	PhoneBook::PhoneBookList(void)
{ 
	std::cout  << "|-----------*** CONTACT LIST ***------------|" << std::endl;
	std::cout << "|" << std::right << std::setw(10) << "Index" << "|";
	std::cout << std::right << std::setw(10) << "First Name"  << "|";
	std::cout << std::right << std::setw(10) << "Last Name"  << "|";
	std::cout << std::right << std::setw(10) << "Nickname"  << "|" << std:: endl;
	PhoneBook::prompt();
	std::cout << "|-------------------------------------------|" << std::endl;	
}


void	PhoneBook::TextTraiter(void)
{
	if (PhoneBook::contacts[0].get_FirstName().length() > 10)
	{
		std::string temp = PhoneBook::contacts[0].get_FirstName();
		temp = temp.substr(0, 10);
		temp[9] = '.';
		std::cout << temp << std::endl;
		PhoneBook::contacts[0].set_FirstName(temp);
	}
}

void	PhoneBook::Search(void)
{
	PhoneBook::TextTraiter();
	PhoneBook::PhoneBookList();
}

void	PhoneBook::Exit(void)
{
	exit(0);
}