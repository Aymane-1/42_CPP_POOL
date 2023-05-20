/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:53:40 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/20 19:58:10 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:
		std::string	target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string name);
		PresidentialPardonForm(std::string namee, std::string targett, int toSign, int toExec);	
		PresidentialPardonForm(PresidentialPardonForm &obj);
		PresidentialPardonForm	&operator=(PresidentialPardonForm const &obj);
		virtual void	execute(Bureaucrat const &executor) const;
		~PresidentialPardonForm();
};

#endif