/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:18:05 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/18 19:38:43 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("SomeCorruptOfficial"), grade(150)
{
	std::cout << "Bureaucrat " << name <<  " default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &namee, int gradee) : name(namee) , grade(gradee)
{
	std::cout << name << " Bureaucrat parametrized constructor called." << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
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

std::string	Bureaucrat::getName()
{
	return (this->name);
}

int	Bureaucrat::getGrade()
{
	return (grade);
}

void	Bureaucrat::IncrementGrade()
{
	grade -= 1;
	if (grade < 1)
		throw GradeTooHighException();
}

void	Bureaucrat::DecrementGrade()
{
	grade += 1;
	if (grade > 150)
		throw GradeTooLowException();
}

void	Bureaucrat::signForm(AForm &obj)
{
	try
	{
		obj.beSigned(*this);
		std::cout << name << " signed " << obj.getName() << " form." << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << name << " couldn't sign " << obj.getName() << " form, because " << e.what() << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &out, Bureaucrat &obj)
{
	std::cout << obj.getName() << ", bureaucrat grade is " << obj.getGrade() << std::endl;
	return out;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << name << " destructor called." << std::endl;
}