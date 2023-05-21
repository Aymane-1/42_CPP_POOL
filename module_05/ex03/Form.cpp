/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:12:23 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/21 19:37:25 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): name("someForm"), Signed(false), gradeToSign(150), gradeToExec(150)
{
	std::cout << "Form default constructor called." << std::endl;
}

Form::Form(const std::string &namee, const int GradeToSign, const int GradeToExec) \
: name(namee), Signed(false), gradeToSign(GradeToSign), gradeToExec(GradeToExec)
{
	std::cout << "Form parametrized constructor called." << std::endl;
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
}

Form::Form(Form &obj) : name("someForm"), Signed(false), gradeToSign(150), gradeToExec(150)
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
	return (*this);
}

std::string	Form::getName() const
{
	return (name);	
}

bool	Form::getSignedState() const
{
	return (Signed);	
}

int	Form::getGradeToSign() const
{
	return (gradeToSign);
}

int	Form::getGradeToExec() const
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
	std::cout << "AForm destructor called." << std::endl;	
}