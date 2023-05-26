/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:58:15 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/25 21:46:45 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
class Intern{
	public:
		class GradeTooHighException: public std::exception{
			public:
				const char *what() const throw (){
					return ("GradeTooHigh!");
				}
		};
		class GradeTooLowException: public std::exception{
			public:
				const char *what() const throw (){
					return ("GradeTooLow!");
				}
		};
		class FormUnsignedException: public std::exception{
			public:
				const char *what() const throw (){
					return ("the form is unsigned!");
				}	
		};
		class FormUnexistantException: public std::exception{
			public:
				const char *what() const throw (){
					return ("Error: Seems that the form passed on as a parameter does not exist!");
				}
		};
		Intern();
		Intern(const Intern &obj);
		Intern	&operator=(const Intern &obj);
		AForm	*makeForm(const std::string formName, const std::string formTarget);
		AForm	*makeShrubberyCreationForm(std::string name, std::string target);
		AForm	*makePresidentialPardonForm(std::string name, std::string target);
		AForm	*makeRobotomyRequestForm(std::string name, std::string target);
		~Intern();
};

typedef	AForm *(Intern::*funcPtr)(std::string formName, std::string formTarget);

#endif