/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:43:06 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/25 18:36:00 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//---------------------------*** constructors ***---------------------------

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm default constructor called." << std::endl;
	target = "someTarget";
}

RobotomyRequestForm::RobotomyRequestForm(std::string targett) : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm parametrized constructor" << std::endl;
	target = targett;
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