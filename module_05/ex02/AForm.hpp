/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:00:57 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/25 12:41:01 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
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
		class FormUnsignedException:public std::exception
		{
			public:
				const char * what() const throw()
				{
					return ("the Form is unsigned!");
				}
		};
		AForm();
		AForm(const std::string &namee, const int GradeToSign, const int GradeToExec);
		AForm(const AForm &obj);
		AForm			&operator=(const AForm &obj);
		std::string		getName() const;
		bool			getSignedState() const;
		int				getGradeToSign() const;	
		int				getGradeToExec() const;	
		void			beSigned(Bureaucrat &obj);
		virtual void	execute(Bureaucrat const &executor) const = 0;
		~AForm();
};

std::ostream	&operator<<(std::ostream &out, AForm &obj);

#endif