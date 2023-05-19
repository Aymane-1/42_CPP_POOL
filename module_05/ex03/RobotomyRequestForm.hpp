/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:33:23 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/19 17:04:36 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <iostream>
class RobotomyRequestForm: public AForm
{
	private:
		std::string	target;
	public:
		RobotomyRequestForm();	
		RobotomyRequestForm(std::string name);
		RobotomyRequestForm(RobotomyRequestForm &obj);
		RobotomyRequestForm	&operator=(RobotomyRequestForm const &obj);
		virtual	void	execute(Bureaucrat const &executor) const;
		~RobotomyRequestForm();	
};

#endif