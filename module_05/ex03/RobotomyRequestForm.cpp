/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:43:06 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/22 20:08:18 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

//---------------------------*** constructors ***---------------------------

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequest", 72, 45)
{
	std::cout << "RobotomyRequestForm default constructor called." << std::endl;
	target = "someTarget";
}

RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm("RobotomyRequest", 72, 45)
{
	std::cout << "RobotomyRequestForm parametrized constructor" << std::endl;
	target = name;
}

RobotomyRequestForm::RobotomyRequestForm(std::string name, std::string type) \
: AForm(name, 72, 45)
{
	this->target = type;
	std::cout << "RobotomyRequestForm parametrized constructor called." << std::endl;
}

//---------------------------*** copy constructor ***---------------------------

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &obj)
{
	*this = obj;
}

//---------------------------*** copy assignment ***---------------------------

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &obj)
{
	if (this != &obj)
	{
		this->target = obj.target;
	}
	return (*this);
}

//---------------------------*** member functions ***---------------------------

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSignedState())
		throw FormUnsignedException();
	else if (executor.getGrade() > this->getGradeToExec())
		throw GradeTooLowException();
	srand(time(NULL));
	int RandomNumber = rand();
	bool probability = RandomNumber % 2;
	std::cout << "Some drilling noises..." << std::endl;
	if (probability)
		std::cout << target << " has been robotomized succefully." << std::endl;
	else
		std::cout << target << " has failed to be robotomized." << std::endl;
}

//---------------------------*** destructor ***---------------------------

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called." << std::endl;
}