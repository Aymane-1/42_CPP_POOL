/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 00:29:47 by aechafii          #+#    #+#             */
/*   Updated: 2023/06/03 02:49:01 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	try
	{
		Span sequence(5);
		
		sequence.addNumber(6);
		sequence.addNumber(3);
		sequence.addNumber(17);
		sequence.addNumber(9);
		sequence.addNumber(11);
		
		std::cout << "vector elements: ";
		sequence.displayVector();
		std::cout << "\n";
		
		sequence.longestSpan();
		sequence.shortestSpan();

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Span sequence2(0);
		sequence2.containerFiller(5);
		std::cout << "vector elements: ";
		sequence2.displayVector();
		std::cout << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}