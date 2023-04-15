/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 21:47:28 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/15 04:55:05 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

//-----------------------*** PhoneBook Class member functions ***-----------------------//

void	PhoneBook::entry_display()
{
		std::cout << "\e[36;1m---------------- WELCOME TO THE 80'S CRAPPY PHONEBOOK ----------------\e[0m" << std::endl;
		// sleep(1);
		std::cout << "\e[90;1;3;4mAVAILABLE COMMANDS ARE:\e[0m" << std::endl;
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

void	PhoneBook::PhoneTable(void)
{
	int	i;

	i = 0;
	while (PhoneBook::contacts[i].get_FirstName().empty() == false)
	{
			std::cout << "|" << std::right << std::setw(10) << PhoneBook::contacts[i].get_Index() << "|";
			std::cout << std::right << std::setw(10) << PhoneBook::contacts[i].get_FirstName() << "|";
			std::cout << std::right << std::setw(10) << PhoneBook::contacts[i].get_LastName() << "|";
			std::cout << std::right << std::setw(10) << PhoneBook::contacts[i].get_NickName() << "|" << std::endl;
		i++;
	}
}

int	PhoneBook::FindIndex(int index)
{
	int i = 0;

	while (PhoneBook::contacts[i].get_FirstName().empty() == false)
	{
		if (PhoneBook::contacts[i].get_Index() == index)
			return (1);
		i++;
	}
	return (0);
}

int	PhoneBook::IndexParser(std::string input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (!isdigit(input[i]))
		{
			std::cout << "\e[31;1mWRONG INPUT!\e[0m \e[90;1mTRY AGAIN.\e[0m" << std::endl;
			return (-1);
		}
		i++;
	}
	i = stoi(input);
	if (stoi(input) < 0 || PhoneBook::FindIndex(i) == 0)
	{
		std::cout << "\e[31;1mINPUT IS OUT RANGE!\e[0m \e[90;1mTRY AGAIN.\e[0m" << std::endl;
		return (-1);
	}
	return (stoi(input));
}

void	PhoneBook::Prompt(void)
{
	std::string	input;
	
	std::cout << "\e[90;1mINSERT INDEX OF CONTACT:\e[0m ";
	std::getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cout << "\n\e[31;1mNO FIELDS SHOULD BE EMPTY! RELAUNCH THE PHONEBOOK.\e[0m" << std::endl;
		exit (1);
	}
	int i = 0;
	while (1)
	{
		if (IndexParser(input) > -1)
		{
			while (PhoneBook::contacts[i].get_FirstName().empty() == false)
			{
				if (PhoneBook::contacts[i].get_Index() == stoi(input))
				{
					std::cout << std::endl;
					std::cout << "|--**CONTACT  INFO**--|" << std::endl;
					std::cout << "|---------------------|" << std::endl;
					std::cout << "|" << std::right << std::setw(10) << "Index" << "|";
					std::cout << std::right << std::setw(10) << PhoneBook::contacts[i].get_Index() << "|" << std::endl;
					std::cout << "|" << std::right << std::setw(10) << "First Name"  << "|";
					std::cout << std::right << std::setw(10) << PhoneBook::contacts[i].get_FirstName() << "|" << std::endl;
					std::cout << "|" << std::right << std::setw(10) << "Last Name"  << "|";
					std::cout << std::right << std::setw(10) << PhoneBook::contacts[i].get_LastName() << "|" << std::endl;
					std::cout << "|" << std::right << std::setw(10) << "Nickname"  << "|";
					std::cout << std::right << std::setw(10) << PhoneBook::contacts[i].get_NickName() << "|" << std::endl;
					std::cout << "|---------------------|" << std::endl;
					std::cout << std::endl;
					return ;
				}
				i++;
			}
		}
		else
		{
			std::cout << "\e[90;1mINSERT INDEX OF CONTACT:\e[0m ";
			std::cin >> input;
		}
	}
}

int	s_digit(std::string input)
{
	int i = 0;

	while (input[i])
	{
		if (!isdigit(input[i]))
			return (0);
		i++;
	}
	return (1);
}

void	PhoneBook::TextTraiter(void)
{
	int i;

	i = 0;
	while (PhoneBook::contacts[i].get_FirstName().empty() == false)
	{
		if (PhoneBook::contacts[i].get_FirstName().length() > 10)
		{
			std::string temp = PhoneBook::contacts[i].get_FirstName();
			temp = temp.substr(0, 10);
			temp[9] = '.';
			PhoneBook::contacts[i].set_FirstName(temp);
		}
		if (PhoneBook::contacts[i].get_LastName().length() > 10)
		{
			std::string temp = PhoneBook::contacts[i].get_LastName();
			temp = temp.substr(0, 10);
			temp[9] = '.';
			PhoneBook::contacts[i].set_LastName(temp);
		}
		if (PhoneBook::contacts[i].get_NickName().length() > 10)
		{
			std::string temp = PhoneBook::contacts[i].get_NickName();
			temp = temp.substr(0, 10);
			temp[9] = '.';
			PhoneBook::contacts[i].set_NickName(temp);
		}
		i++;
	}
}

void	PhoneBook::Search(void)
{
	PhoneBook::TextTraiter();
	PhoneBook::PhoneBookList();
}

void	PhoneBook::PhoneBookList(void)
{
	if (PhoneBook::contacts[0].get_FirstName().empty() == false)
	{
		std::cout  << "|-----------*** CONTACT LIST ***------------|" << std::endl;
		std::cout << "|" << std::right << std::setw(10) << "Index" << "|";
		std::cout << std::right << std::setw(10) << "First Name"  << "|";
		std::cout << std::right << std::setw(10) << "Last Name"  << "|";
		std::cout << std::right << std::setw(10) << "Nickname"  << "|" << std:: endl;
		PhoneBook::PhoneTable();
		std::cout << "|-------------------------------------------|" << std::endl;
		PhoneBook::Prompt();
	}
	else
		std::cout << "\e[31;1mNO CONTACTS ARE ADDED YET!\e[0m \e[90;1mTRY THE\e[0m \e[32;1m'ADD'\e[0m \e[90;1mCOMMAND.\e[0m" << std::endl;
}

void	PhoneBook::set_Contact(int index)
{
	std::string input;
	
	PhoneBook::contacts[index].set_Index(index);
	PhoneBook::contacts[index].set_FirstName("");
	std::cout << "First Name : ";
	std::cin >> input;
	if (std::cin.eof())
	{
		std::cout << "\n\e[31;1mNO FIELDS SHOULD BE EMPTY! RELAUNCH THE PHONEBOOK.\e[0m" << std::endl;
		exit (1);
	}
	PhoneBook::contacts[index].set_FirstName(input);
	std::cout << "Last Name : ";
	std::cin >> input;
	if (std::cin.eof())
	{
		std::cout << "\n\e[31;1mNO FIELDS SHOULD BE EMPTY! RELAUNCH THE PHONEBOOK.\e[0m" << std::endl;
		exit (1);
	}
	PhoneBook::contacts[index].set_LastName(input);
	std::cout << "NickName : ";
	std::cin >> input;
	if (std::cin.eof())
	{
		std::cout << "\n\e[31;1mNO FIELDS SHOULD BE EMPTY! RELAUNCH THE PHONEBOOK.\e[0m" << std::endl;
		exit (1);
	}
	PhoneBook::contacts[index].set_NickName(input);
	std::cout << "Phone Number : ";
	std::cin >> input;
	if (std::cin.eof())
	{
		std::cout << "\n\e[31;1mNO FIELDS SHOULD BE EMPTY! RELAUNCH THE PHONEBOOK.\e[0m" << std::endl;
		exit (1);
	}
	while (!s_digit(input))
	{
		std::cout << "\e[31;1mPHONE NUMBER MUST BE A DIGIT!\e[0m" << std::endl;
		std::cout << "Phone Number : ";
		std::cin >> input;
	}
	PhoneBook::contacts[index].set_PhoneNumber(input);
	std::cout << "Darkest Secret : ";
	std::cin >> input;
	if (std::cin.eof())
	{
		std::cout << "\n\e[31;1mNO FIELDS SHOULD BE EMPTY! RELAUNCH THE PHONEBOOK.\e[0m" << std::endl;
		exit (1);
	}
	PhoneBook::contacts[index].set_DarkestSecret(input);
	system("CLEAR");
}