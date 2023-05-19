/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:00:34 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/19 19:07:12 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class Intern: public AForm{
	public:
		Intern();
		Intern(Intern &obj);
		Intern	&operator=(const Intern &obj);
		AForm	*makeForm(std::string formName, std::string formTarget);	
		~Intern();
};

#endif 