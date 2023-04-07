/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassMemberFunc.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 02:45:37 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/07 00:42:42 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AwesomePhoneBook.hpp"

//-----------------------*** Contact Class member functions ***-----------------------//

void	Contact::get_FirstName(void)
{
	std::cout << Contact::FirstName << std::endl;
}

void	Contact::get_LastName(void)
{
	std::cout << Contact::LastName << std::endl;
}

void	Contact::get_NickName(void)
{
	std::cout << Contact::NickName << std::endl;
}

void	Contact::get_PhoneNumber(void)
{
	std::cout << Contact::PhoneNumber << std::endl;
}

void	Contact::get_DarkestSecret(void)
{
	std::cout << Contact::DarkestSecret << std::endl;
}

void	Contact::set_FirstName(std::string s)
{
	Contact::FirstName = s;
}

void	Contact::set_LastName(std::string s)
{
	Contact::LastName = s;
}

void	Contact::set_NickName(std::string s)
{
	Contact::NickName = s;
}

void	Contact::set_PhoneNumber(std::string s)
{
	Contact::PhoneNumber = s;
}

void	Contact::set_DarkestSecret(std::string s)
{
	Contact::DarkestSecret = s;
}

//-----------------------*** PhoneBook Class member functions ***-----------------------//
