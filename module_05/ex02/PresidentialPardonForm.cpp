/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:58:17 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/20 20:30:04 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("SomeType", 25, 5)
{
	std::cout << "PresidentialPardonForm default constructor called." << std::endl;
	target = "someTarget";
}

PresidentialPardonForm::PresidentialPardonForm(std::string name) \
 : AForm(name, 25, 5)
{
	target = name;
}

PresidentialPardonForm::PresidentialPardonForm(std::string namee, std::string targett, int toSign, int toExec) \
: AForm(namee, toSign, toExec)
{
	target = targett;
	std::cout << "PresidentialPardonForm parametrized constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &obj)
{
	*this= obj;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &obj)
{
	if (this != &obj)
	{
		this->target = obj.target;
	}
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSignedState())
		throw FormUnsignedException();
	else if (executor.getGrade() > this->getGradeToExec())
		throw GradeTooLowException();	
	std::cout << target << " has been pardoned by Zaphod Beeblerox." << std::endl;	
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called." << std::endl;
}
