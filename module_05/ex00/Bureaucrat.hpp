/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:45:35 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/14 18:53:45 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat{
	private:
		const std::string	name;	
		int					grade;
	public:
		class GradeTooHighException : public std::exception{
			public :
				const char *what() const throw (){
					return ("GradeTooHigh!");
				}
		};
		class GradeTooLowException : public std::exception{
			public :
				const char *what() const throw (){
					return ("GradeTooLow!");
				}
		};
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &obj);
		Bureaucrat &operator=(const Bureaucrat &obj);
		std::string	getName();
		int			getGrade();
		void		IncrementGrade();
		void		DecrementGrade();
		~Bureaucrat();
};

std::ostream &operator << (std::ostream &out, Bureaucrat &obj);

#endif