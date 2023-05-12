/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:45:35 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/12 21:02:35 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat{
	private:
		const std::string	name;	
		int					grade;
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &obj);
		Bureaucrat &operator=(const Bureaucrat &obj);
		void		GradeTooHighException();
		void		GradeTooLowException();
		std::string	getName();
		int			getGrade();
		~Bureaucrat();
		
};

#endif