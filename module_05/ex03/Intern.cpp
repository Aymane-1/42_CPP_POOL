/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 21:01:48 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/20 21:10:01 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called." << std::endl;
}

Intern::Intern(const Intern &obj)
{
	*this = obj;
}

Intern	&Intern::operator=(const Intern &obj)
{
	std::cout << "Intern copy assingnment called." << std::endl;
}

Form	Intern::makeForm(std::string formName, std::string formTarget)
{
	std::cout << "Intern creates " << formName << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called." << std::endl;
}