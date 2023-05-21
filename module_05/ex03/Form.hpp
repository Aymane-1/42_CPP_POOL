/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:59:20 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/21 19:36:55 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

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
		class FormUnsignedException: public std::exception{
			public:
				const char *what() const throw(){
					return ("The form is unsigned!");
				}
		};
		Form();
		Form(const std::string &namee, const int GradeToSign, const int GradeToExec);
		Form(Form &obj);
		Form		&operator=(const Form &obj);
		std::string		getName() const;
		bool			getSignedState() const;
		int				getGradeToSign() const;
		int				getGradeToExec() const;
		void			beSigned(Bureaucrat &obj);
		// virtual void	execute(Bureaucrat const &executor);
		~Form();	
};

#endif