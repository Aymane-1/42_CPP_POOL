/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 21:01:48 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/22 21:46:32 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

//---------------------------*** constructors ***---------------------------

Intern::Intern()
{
	std::cout << "Intern default constructor called." << std::endl;
}

//---------------------------*** copy constructor ***---------------------------

Intern::Intern(const Intern &obj)
{
	std::cout << "Intern copy constructor called." << std::endl;
	*this = obj;
}

//---------------------------*** copy assignment ***---------------------------

Intern	&Intern::operator=(const Intern &obj)
{
	std::cout << "Intern copy assignment called." << std::endl;
	(void)obj;
	return (*this);
}

//---------------------------*** member functions ***---------------------------

AForm	*Intern::makeShrubberyCreationForm(std::string name, std::string target)
{
	AForm	*form = new ShrubberyCreationForm(name, target);
	std::cout << "Intern created " << target << " form succesfully." << std::endl;
	return (form);
}

AForm	*Intern::makeRobotomyRequestForm(std::string name, std::string target)
{
	AForm *form = new RobotomyRequestForm(name, target);
	std::cout << "Intern created " << target << " form succesfully." << std::endl;
	return (form);
}

AForm	*Intern::makePresidentialPardonForm(std::string name, std::string target)
{
	AForm *form = new PresidentialPardonForm(name, target);
	std::cout << "Intern created " << target << " form succesfully." << std::endl;
	return (form);
}

AForm	*Intern::makeForm(const std::string formName, const std::string formTarget)
{
	std::string ptr[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	int i = 0;
	while (i < 3)
	{
		if (formName == ptr[i])
			break ;	
		if (i == 2 && (formName != ptr[i]))
			throw FormUnexistantException();
		i++;
	}
	AForm *a = NULL;
	switch (i){
		case 0:
			a = Intern::makeShrubberyCreationForm(formName, formTarget);
			break;
		case 1:
			a = Intern::makeRobotomyRequestForm(formName, formTarget);
			break;
		case 2:
			a = Intern::makePresidentialPardonForm(formName, formTarget);
			break;
	}
	return (a);
}

//---------------------------*** destructor ***---------------------------

Intern::~Intern()
{
	std::cout << "Intern destructor called." << std::endl;
}