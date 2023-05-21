/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 21:01:48 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/21 21:37:09 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called." << std::endl;
}

Intern::Intern(const Intern &obj)
{
	std::cout << "Intern copy assignment called." << std::endl;
	*this = obj;
}

Intern	&Intern::operator=(const Intern &obj)
{
	std::cout << "Intern copy assingnment called." << std::endl;
	(void)obj;
	return (*this);
}

AForm	*Intern::makeForm(const std::string formName, const std::string formTarget)
{
	// funcPtr forms[3] = {&ShrubberyCreationForm::execute, &RobotomyRequestForm::execute, &PresidentialPardonForm::execute};
	std::string ptr[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	for (int i = 0; i < 3; i++)
	{	
		if (formName == ptr[i])
		{
			std::cout << "Intern created " << formTarget << " form succesfully." << std::endl;
			break ;	
		}
		if (i == 2 && (formName != ptr[i]))
			std::cout << "Error: Seems that the form passed on as a parameter does not exist!" << std::endl;
	}
	AForm *a = NULL;
	return (a);
}

Intern::~Intern()
{
	std::cout << "Intern destructor called." << std::endl;
}