/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:38:11 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/22 20:47:26 by aechafii         ###   ########.fr       */
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
		std::cout << "\n------------------*** CONSTRUCTORS ***-------------------\n" << std::endl;
		
		Bureaucrat Counselor("Counselor", 1);
		
		PresidentialPardonForm ppf("Bandit");
		RobotomyRequestForm	rrf("drivingLicence");
		ShrubberyCreationForm scf("home");

		std::cout << "\n--------------*** FORMS DEMONSTRATION ***---------------\n" << std::endl;
		
		ppf.beSigned(Counselor);
		ppf.execute(Counselor);
		rrf.beSigned(Counselor);
		rrf.execute(Counselor);
		scf.beSigned(Counselor);
		scf.execute(Counselor);
		
		std::cout << "\n-----------*** BUREAUCRAT FORMS EXECUTION ***-----------\n" << std::endl;
		
		AForm *form;
		
		form = &rrf;
		form->beSigned(Counselor);
		Counselor.executeForm(*form);
		
		std::cout << "\n------------------*** DESTRUCTORS ***-------------------\n" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}