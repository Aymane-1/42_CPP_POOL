/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:38:11 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/19 18:56:34 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat Counselor("counselor", 1);
	ShrubberyCreationForm ChristmasTree("Home");
	RobotomyRequestForm machine("someGuy");
	PresidentialPardonForm Document("Truce");
	std::cout << "-----------------------" << std::endl;
	ChristmasTree.execute(Counselor);
	machine.execute(Counselor);
	Document.execute(Counselor);
	std::cout << "-----------------------" << std::endl;
}