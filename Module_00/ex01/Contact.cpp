/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 02:45:37 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/15 02:27:41 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

//-----------------------*** Contact Class member functions ***-----------------------//

int	Contact::get_Index(void)
{
	return Contact::Index;
}

std::string	Contact::get_FirstName(void)
{
	return Contact::FirstName;
}

std::string	Contact::get_LastName(void)
{
	return Contact::LastName;
}

std::string	Contact::get_NickName(void)
{
	return Contact::NickName;
}

std::string	Contact::get_PhoneNumber(void)
{
	return Contact::PhoneNumber;
}

std::string	Contact::get_DarkestSecret(void)
{
	return Contact::DarkestSecret;
}

//------------------------------------------------------------------------------------//

void	Contact::set_Index(int index)
{
	Contact::Index = index;
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

void	Contact::set_PhoneNumber(std::string PhoneNumber)
{
	Contact::PhoneNumber = PhoneNumber;
}

void	Contact::set_DarkestSecret(std::string s)
{
	Contact::DarkestSecret = s;
}
