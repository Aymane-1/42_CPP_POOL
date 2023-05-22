/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:33:23 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/22 20:51:44 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <cstdlib>
class RobotomyRequestForm: public AForm
{
	private:
		std::string	target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string name);
		RobotomyRequestForm(std::string namee, std::string targett, int toSign, int toExec);
		RobotomyRequestForm(RobotomyRequestForm &obj);
		RobotomyRequestForm	&operator=(RobotomyRequestForm const &obj);
		virtual	void	execute(Bureaucrat const &executor) const;
		~RobotomyRequestForm();	
};

#endif