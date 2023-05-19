/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:43:06 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/19 17:05:37 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : target("SomeRandomTarget")
{
	std::cout << "RobotomyRequestForm default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string name) : target(name)
{
	std::cout << "RobotomyRequestForm parametrized constructor called." << std::endl;
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
	(void)executor;
	srand(time(0));
	int RandomNumber = rand();
	bool probability = (RandomNumber % 2 == 0);
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