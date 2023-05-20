/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:38:11 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/20 20:50:44 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat Counselor("Counselor", 1);
		ShrubberyCreationForm ChristmasTree("binaryTree", "home", 145, 137);
		RobotomyRequestForm machine("someGuy", "birthCertificate", 70, 40);
		PresidentialPardonForm Document("Contract", "Prisoner", 20, 2);
		
		// Instantiation of objects with different constructors between above and below. 
		
		PresidentialPardonForm rb("PresidentialPardon");
		RobotomyRequestForm	lb("robotomyRequest");
		ShrubberyCreationForm jb("asciiTree");

		rb.beSigned(Counselor);
		rb.execute(Counselor);
		lb.beSigned(Counselor);
		lb.execute(Counselor);
		jb.beSigned(Counselor);
		jb.execute(Counselor);
		
		std::cout << "-----------------------" << std::endl;
		
		ChristmasTree.beSigned(Counselor);
		machine.beSigned(Counselor);
		Document.beSigned(Counselor);
		
		ChristmasTree.execute(Counselor);
		machine.execute(Counselor);
		// Document.execute(Counselor);
		AForm *form;
		form = &Document;
		Counselor.executeForm(*form);
		
		std::cout << "-----------------------" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}