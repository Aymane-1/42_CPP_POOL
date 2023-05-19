/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:58:17 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/19 17:15:11 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): target("SomeKindaType")
{
	std::cout << "PresidentialPardonForm default constructor called." << std::endl;

}

PresidentialPardonForm::PresidentialPardonForm(std::string name): target(name)
{
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
	(void)executor;
	std::cout << target << " has been pardoned by Zaphod Beeblerox." << std::endl;	
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called." << std::endl;
}
