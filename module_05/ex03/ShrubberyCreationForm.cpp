/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:50:19 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/25 18:19:20 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

//---------------------------*** constructors ***---------------------------

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShruberryCreationForm default constructor called." << std::endl;
	target = "file";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) \
: AForm(name, 145, 137)
{
	target = name;
	std::cout << "ShrubberyCreationForm parametrized constructor called." << std::endl;
}

//---------------------------*** copy constructor ***---------------------------

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &obj):AForm(obj.getName(), 145, 137)
{
	*this = obj;
}

//---------------------------*** copy assignment ***---------------------------

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	if (this != &obj)
	{
		this->target = obj.target;
	}
	return (*this);
}

//---------------------------*** member functions ***---------------------------

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSignedState())
		throw FormUnsignedException();
	else if (executor.getGrade() > this->getGradeToExec())
		throw	GradeTooLowException();
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
	std::cout << "'" + target + "_shrubbery'" << " file created succefully." << std::endl;
}

//------------------------------*** destructor ***-------------------------------

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberryCreationForm destructor called." << std::endl; 
}