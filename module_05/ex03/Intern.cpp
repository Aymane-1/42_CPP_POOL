/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:07:19 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/19 19:56:30 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called." << std::endl;
}

Intern::Intern(Intern &obj)
{
	*this = obj;
}

Intern	&Intern::operator=(const Intern &obj)
{
	if (this != &obj)
	{
		;
	}
	return (*this);
}

AForm	*makeForm(std::string formName, std::string	formTarget)
{
	
	std::cout << "Intern creates " <<  "" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called." << std::endl;
}