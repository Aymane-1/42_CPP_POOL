/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:32:17 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/20 20:42:09 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERRY_HPP
#define SHRUBBERRY_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>
#include <stdlib.h>

class ShrubberyCreationForm: public AForm
{
	private:
		std::string target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string name);
		ShrubberyCreationForm(std::string namee, std::string targett, int toSign, int toExec);
		ShrubberyCreationForm(ShrubberyCreationForm &obj);
		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &obj);
		void					execute(Bureaucrat const &executor) const;
		~ShrubberyCreationForm();
};

#endif