/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:18:05 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/12 21:42:41 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat default constructor called." << std::endl;
	this->grade = 1;
	try
	{
		if (this->grade < 1 || this->grade > 150)
			throw this->grade;
	}
	catch(int grade)
	{
		std::cout << "Too high / Too low\n";
		if (grade < 1)
			this->GradeTooHighException();
		else if (grade > 150)
			this->GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = obj;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &obj)
{
	std::cout << "Bureaucrat copy assignment called." << std::endl;
	if (this != &obj)
	{
		(std::string)this->name = obj.name;
		this->grade = obj.grade;
	}
	return (*this);
}

void	Bureaucrat::GradeTooHighException()
{
	std::cout << "GradeTooHigh!" << std::endl;
}

void	Bureaucrat::GradeTooLowException()
{
	std::cout << "GradeTooLow!" << std::endl;
}
,

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called." << std::endl;
}