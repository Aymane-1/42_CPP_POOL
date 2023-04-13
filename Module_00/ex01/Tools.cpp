/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tools.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 22:06:56 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/13 02:45:01 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::entry_display()
{
		std::cout << "---------------- WELCOME TO THE 80'S CRAPPY PHONEBOOK ----------------" << std::endl;
		// sleep(1);
		std::cout << "AVAILABLE COMMANDS ARE :" << std::endl;
		// sleep(1);
		std::cout << "--> \e[32;1mADD\e[0m" << std::endl;
		// sleep(1);
		std::cout << "--> \e[36;1mSEARCH\e[0m" << std::endl;
		// sleep(1);
		std::cout << "--> \e[31;1mEXIT\e[0m" << std::endl;
		// sleep(1);
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
	system("CLEAR");
}

int	IndexParser(std::string input, int index)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (!isdigit(input[i]))
		{
			std::cout << "\e[31;1mWRONG INPUT!\e[0m \e[90;1mTRY AGAIN.\e[0m" << std::endl;
			return (1);
		}
		i++;
	}
	if (stoi(input) > index || stoi(input) < 1)
	{
		std::cout << "\e[31;1mINPUT IS OUT RANGE!\e[0m \e[90;1mTRY AGAIN.\e[0m" << std::endl;
		return (1);
	}
	return (0);
}

void	PhoneBook::PhoneTable(int index)
{
	int	i;

	i = 1;
	while (i <= index)
	{
		if (PhoneBook::contacts[index].get_FirstName() != "")
		{	
			std::cout << "|" << std::right << std::setw(10) << i << "|";
			std::cout << std::right << std::setw(10) << PhoneBook::contacts[i].get_FirstName() << "|";
			std::cout << std::right << std::setw(10) << PhoneBook::contacts[i].get_LastName() << "|";
			std::cout << std::right << std::setw(10) << PhoneBook::contacts[i].get_NickName() << "|" << std::endl;
		}
		i++;
	}
}

void	PhoneBook::Prompt(int index)
{
	std::string	input;
	
	input = "";
	std::cout << "\e[90;1mINSERT INDEX OF CONTACT:\e[0m" << std::endl;
	std::cin >> input;
	while (1)
	{
		if (!IndexParser(input, index))
		{
			if (PhoneBook::contacts[index].get_FirstName() != "")
			{
				std::cout  << "|--**CONTACT  INFO**--|" << std::endl;
				std::cout << "|---------------------|" << std::endl;
				std::cout << "|" << std::right << std::setw(10) << "Index" << "|";
				std::cout << std::right << std::setw(10) << index << "|" << std::endl;
				std::cout << "|" << std::right << std::setw(10) << "First Name"  << "|";
				std::cout << std::right << std::setw(10) << PhoneBook::contacts[index].get_FirstName() << "|" << std::endl;
				std::cout << "|" << std::right << std::setw(10) << "Last Name"  << "|";
				std::cout << std::right << std::setw(10) << PhoneBook::contacts[index].get_LastName() << "|" << std::endl;
				std::cout << "|" << std::right << std::setw(10) << "Nickname"  << "|";
				std::cout << std::right << std::setw(10) << PhoneBook::contacts[index].get_NickName() << "|" << std::endl;
				std::cout << "|---------------------|" << std::endl;
				std::cout << std::endl;
				return ;
			}
		}
		else
		{
			std::cout << "\e[90;1mINSERT INDEX OF CONTACT:\e[0m" << std::endl;
			std::cin >> input;
		}
	}
}

void	PhoneBook::PhoneBookList(int index)
{
	if (PhoneBook::contacts[index].get_FirstName() != "")
	{
		std::cout  << "|-----------*** CONTACT LIST ***------------|" << std::endl;
		std::cout << "|" << std::right << std::setw(10) << "Index" << "|";
		std::cout << std::right << std::setw(10) << "First Name"  << "|";
		std::cout << std::right << std::setw(10) << "Last Name"  << "|";
		std::cout << std::right << std::setw(10) << "Nickname"  << "|" << std:: endl;
		PhoneBook::PhoneTable(index);
		std::cout << "|-------------------------------------------|" << std::endl;
		sleep(3);
		system("CLEAR");
		PhoneBook::Prompt(index);
	}
	else
		std::cout << "\e[31;1mNO CONTACTS ARE ADDED YET!\e[0m \e[90;1mTRY THE\e[0m \e[32;1m'ADD'\e[0m \e[90;1mCOMMAND.\e[0m" << std::endl;
}


void	PhoneBook::TextTraiter(int index)
{
	int i;

	i = 1;
	while (i <= index)
	{
		if (PhoneBook::contacts[i].get_FirstName().length() > 10)
		{
			std::string temp = PhoneBook::contacts[i].get_FirstName();
			temp = temp.substr(0, 10);
			temp[9] = '.';
			PhoneBook::contacts[i].set_FirstName(temp);
		}
		i++;
	}
}

void	PhoneBook::Search(int index)
{
	PhoneBook::TextTraiter(index);
	PhoneBook::PhoneBookList(index);
}

void	PhoneBook::Exit(void)
{
	exit(0);
}