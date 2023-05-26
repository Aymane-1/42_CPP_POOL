/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 21:01:48 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/25 21:47:25 by aechafii         ###   ########.fr       */
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
	(void)obj; // No attributes to copy.
	return (*this);
}

//---------------------------*** member functions ***---------------------------

AForm	*Intern::makeShrubberyCreationForm(std::string name, std::string target)
{
	AForm	*form = new ShrubberyCreationForm(target);
	std::cout << "Intern created " << name << " form succesfully." << std::endl;
	return (form);
}

AForm	*Intern::makeRobotomyRequestForm(std::string name, std::string target)
{
	AForm *form = new RobotomyRequestForm(target);
	std::cout << "Intern created " << name << " form succesfully." << std::endl;
	return (form);
}

AForm	*Intern::makePresidentialPardonForm(std::string name, std::string target)
{
	AForm *form = new PresidentialPardonForm(target);
	std::cout << "Intern created " << name << " form succesfully." << std::endl;
	return (form);
}

AForm	*Intern::makeForm(std::string formName, std::string formTarget)
{
	std::string ptr[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	funcPtr forms[3] = {&Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm, &Intern::makePresidentialPardonForm};
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
			a = (this->*forms[0])(formName, formTarget);
			break;
		case 1:
			a = (this->*forms[1])(formName, formTarget);
			break;
		case 2:
			a = (this->*forms[2])(formName, formTarget);
			break;
	}
	return (a);
}

//---------------------------*** destructor ***---------------------------

Intern::~Intern()
{
	std::cout << "Intern destructor called." << std::endl;
}