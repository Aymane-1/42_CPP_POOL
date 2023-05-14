/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:00:57 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/14 21:47:49 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
	private:
		const std::string	name;
		bool				Signed;
		const int			gradeToSign;
		const int			gradeToExec;
	public:
		class GradeTooHighException: public std::exception{
			public:
				const char *what() const throw(){
					return ("GradeTooHigh!");
				}
		};
		class GradeTooLowException: public std::exception{
			public:
				const char *what() const throw(){
					return ("GradeTooLow!");
				}
		};
		Form();
		Form(const std::string &namee, bool ssigned, const int GradeToSign, const int GradeToExec);
		Form(const Form &obj);
		Form &operator=(const Form &obj);
		std::string	getName();
		bool		getSignedState();
		int			getGradeToSign();	
		int			getGradeToExec();	
		void		beSigned(Bureaucrat &obj);
		~Form();
};

std::ostream &operator << (std::ostream &out, Form &obj);

#endif