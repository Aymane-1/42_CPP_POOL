/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:58:15 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/20 21:08:34 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "Form.hpp"
class Intern{
	public:
		Intern();
		Intern(const Intern &obj);
		Intern	&operator=(const Intern &obj);
		Form	makeForm(std::string formName, std::string formTarget);
		~Intern();	
};

#endif