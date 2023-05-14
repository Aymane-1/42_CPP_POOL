/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:38:11 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/14 21:46:58 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat Bloc0;
		Bureaucrat Bloc1("Governor", 140);
		std::cout << Bloc1;
		Bloc1.DecrementGrade();
		std::cout << Bloc1;
	}
	catch(std::exception &gradeExceptions)
	{
		std::cout << gradeExceptions.what() << std::endl;
	}
	try
	{
		Bureaucrat Bloc2("Judge", 0);
		std::cout << "This line won't be executed!" << std::endl;
	}
	catch(std::exception &obj)
	{
		std::cout << obj.what() << std::endl;
	}
	return (0);
}