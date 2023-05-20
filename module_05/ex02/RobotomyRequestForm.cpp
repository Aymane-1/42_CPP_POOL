/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:43:06 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/20 20:34:02 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

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

RobotomyRequestForm::RobotomyRequestForm(std::string namee, std::string targett, int toSign, int toExec) \
: AForm(namee, toSign, toExec)
{
	std::cout << "RobotomyRequestForm parametrized constructor called." << std::endl;
	target = targett;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &obj)
{
	*this = obj;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &obj)
{
	if (this != &obj)
	{
		this->target = obj.target;
	}
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSignedState())
		throw FormUnsignedException();
	else if (executor.getGrade() > this->getGradeToExec())
		throw GradeTooLowException();
	srand(time(0));
	int RandomNumber = rand();
	bool probability = RandomNumber % 2;
	std::cout << "Some drilling noises..." << std::endl;
	if (probability)
		std::cout << target << " has been robotomized succefully." << std::endl;
	else
		std::cout << target << " has failed to be robotomized." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called." << std::endl;
}