/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 00:29:47 by aechafii          #+#    #+#             */
/*   Updated: 2023/06/03 23:55:21 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sequence2(8);
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
	// try
	// {
	// 	std::cout << "\n------------------------------------\n" << std::endl;
	// 	Span sequence2(50000);
	// 	std::vector<int> sequence3;
	// 	for(int i = 0; i < 50000; i++)
	// 		sequence3.push_back(i);
	// 	sequence2.containerFiller(sequence3.begin(), sequence3.end());
	// 	std::cout << "vector elements: ";
	// 	sequence2.displayVector();
	// 	std::cout << "\nsequence3 size: " << sequence2.getContainer().size() << std::endl;
	// 	std::cout << "\n";
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	return (0);
}