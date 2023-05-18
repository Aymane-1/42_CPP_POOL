/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:47:33 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/18 19:25:41 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form():name("SomeRandomDocument"), gradeToSign(150),gradeToExec(150)
{
	std::cout << "Form default constructor called." << std::endl;
}

Form::Form(const std::string &namee, const int GradeToSign, const int GradeToExec):name(namee), gradeToSign(GradeToSign) ,gradeToExec(GradeToExec)
{
	std::cout << "Form parametrized constructor called" << std::endl;
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
}

Form::Form(const Form &obj):name(obj.name), gradeToSign(obj.gradeToSign) ,gradeToExec(obj.gradeToExec)
{
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	*this = obj;
}



Form	&Form::operator=(const Form &obj)
{
	if (this != &obj)
	{
		this->Signed = obj.Signed;
	}
	return *this;
}

std::ostream	&operator<<(std::ostream &output, Form &obj)
{
	if (obj.getSignedState())
		std::cout << "Name: " << obj.getName() << " GradeSignedRequired "<< obj.getGradeToSign() << " GradeExecRequired " << obj.getGradeToExec() << " State: true" << std::endl;
	else
		std::cout << "Name: " << obj.getName() << " GradeSignedRequired "<< obj.getGradeToSign() << " GradeExecRequired " << obj.getGradeToExec() << " State: false" << std::endl;
	return (output);
}


std::string	Form::getName()
{
	return (name);
}

bool	Form::getSignedState(void)
{
	return (Signed);	
}

int	Form::getGradeToSign(void)
{
	return (gradeToSign);
}

int	Form::getGradeToExec(void)
{
	return (gradeToExec);
}


void	Form::beSigned(Bureaucrat &obj)
{
	if (obj.getGrade() > this->gradeToSign)
		throw GradeTooLowException();
	else
		Signed = true;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}