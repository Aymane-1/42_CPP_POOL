/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:53:40 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/19 17:10:46 by aechafii         ###   ########.fr       */
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
		PresidentialPardonForm(PresidentialPardonForm &obj);
		PresidentialPardonForm	&operator=(PresidentialPardonForm const &obj);
		virtual void	execute(Bureaucrat const &executor) const;
		~PresidentialPardonForm();
};

#endif