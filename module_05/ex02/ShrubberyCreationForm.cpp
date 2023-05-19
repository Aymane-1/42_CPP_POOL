/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:50:19 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/19 16:00:02 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): target("file")
{
	std::cout << "ShruberryCreationForm default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : target(name)
{
	std::cout << "Shrubbery parametrized constructor called." << std::endl;
}

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

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	(void)executor;
	std::fstream file;
	file.open((target + "_shrubbery"), std::ios::out);
	if (!file.is_open())
	{
		std::cout << "Error! couldn't open file.";
		exit(1);
	}
	file << "          " << std::endl;
	file << "         *" << std::endl;
	file << "        **" << std::endl;
	file << "       ****" << std::endl;
	file << "      ******" << std::endl;
	file << "     ********" << std::endl;
	file << "    **********" << std::endl;
	file << "   ************" << std::endl;
	file << "  **************" << std::endl;
	file << " ****************" << std::endl;
	file << "******************" << std::endl;
	file << "        ||        " << std::endl;
	file << "        --        " << std::endl;
	file << "------------------" << std::endl;
	file.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberryCreationForm destructor called." << std::endl; 
}