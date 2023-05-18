/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:50:19 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/18 21:34:30 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): target("fileName")
{
	std::cout << "ShruberryCreationForm default constructor called" << std::endl;
}

// ShrubberyCreationForm::ShrubberyCreationForm()
// {
// 	std::cout << "ShrubberyCreationForm parametrized constructor called." << std::endl;
// }

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &obj)
{
	*this = obj;
	if (getGradeToSign() > 150 || getGradeToExec() > 150)
		throw GradeTooHighException();
	else if (getGradeToExec() < 1 || getGradeToExec() < 1)
		throw GradeTooLowException();
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	if (this != &obj)
	{
		this->target = obj.target;
	}
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat &executor) const
{
	if (executor.getGrade())
	std::cout << "         *" << std::endl;
	std::cout << "        **" << std::endl;
	std::cout << "       ****" << std::endl;
	std::cout << "      ******" << std::endl;
	std::cout << "     ********" << std::endl;
	std::cout << "    **********" << std::endl;
	std::cout << "   ************" << std::endl;
	std::cout << "  **************" << std::endl;
	std::cout << " ****************" << std::endl;
	std::cout << "******************" << std::endl;
	std::cout << "        ||        " << std::endl;
	std::cout << "        --        " << std::endl;
	std::cout << "------------------" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberryCreationForm destructor called." << std::endl; 
}