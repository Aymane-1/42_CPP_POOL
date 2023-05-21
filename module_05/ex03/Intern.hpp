/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:58:15 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/21 21:35:34 by aechafii         ###   ########.fr       */
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
					return ("The form is unsigned!");
				}	
		};
		class FormUnexistantException: public std::exception{
			public:
				const char *what() const throw (){
					return ("The form does not exist!");
				}
		};
		Intern();
		Intern(const Intern &obj);
		Intern	&operator=(const Intern &obj);
		AForm	*makeForm(const std::string formName, const std::string formTarget);
		~Intern();
};

typedef	void(*funcPtr)(void);

#endif