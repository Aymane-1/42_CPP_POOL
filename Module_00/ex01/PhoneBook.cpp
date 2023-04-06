/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 22:02:33 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/06 02:34:47 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void  Contact::constructor()
{
	std::cout << "Constructor called" << std::endl;
}

void	Contact::getter()
{
	std::cout << Contact::FirstName << std::endl;
}

void	Contact::setter(std::string field, std::string s, Contact contacts)
{
	if (field == "First Name")
	contacts.FirstName = s;
	std::cout << Contact::FirstName << std::endl;
}

Contact::~Contact()
{
	std::cout << "Destructor called" << std::endl;
}

// ----------------------------------------------------------------

void	PhoneBook::constructor()
{
	std::cout << "Constructor called pb" << std::endl;
}

// std::string	PhoneBook::getter()
// {
// 	// return PhoneBook::contacts[0].FirstName;
// }

// void	PhoneBook::setter(std::string s, Contact contacts)
// {
// 	contacts.FirstName = "1st contact";
// }

PhoneBook::~PhoneBook()
{
	std::cout << "Destructor called pb" << std::endl;
}

int	check_input(std::string input)
{
	if (input == "ADD")
		return (1);
	if (input == "SEARCH")
		return (2);
	if (input == "EXIT")
		return (3);
	return (0);
	
}

void	Add(Contact NewContact)
{
	std::string input;
	
	std::cout << "First Name : ";
	std::cin >> input;
	NewContact.setter("First Name", input, NewContact);
	std::cout << "Last Name : ";
	std::cin >> input;
	NewContact.setter("Last", input, NewContact);
	std::cout << "NickName : ";
	std::cin >> input;
	NewContact.setter("NickName", input, NewContact);
	std::cout << "Phone Number : ";
	std::cin >> input;
	NewContact.setter("Phone Number", input, NewContact);
	std::cout << "Darkest Secret : ";
	std::cin >> input;
	NewContact.setter("Darkest Secret", input, NewContact);
}

void	Search()
{
	std::cout << "search!" << std::endl;
}

void	Exit()
{
	exit(0);
}

int main()
{
	Contact 	p;
	PhoneBook 	book;
	int			flag;
	std::string input;

	input.clear();
	flag = 0;
	while (1)
	{
		std::cin >> input;
		flag = check_input(input);
		if (flag)
		{
			system("CLEAR");
			if (flag == 1)
			{
				Add(p);
				p.getter();
			}
			if (flag == 2)
				Search();
			if (flag == 3)
				Exit();
		}
		system("CLEAR");
	}
}