/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 21:46:10 by aechafii          #+#    #+#             */
/*   Updated: 2023/06/03 04:45:37 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	try
	{
		std::cout << "\n-------------*** vector<int> ***---------------\n" << std::endl;
		
		std::vector<int> int_v;
		
		for (int i = 0; i <= 10; i++)
			int_v.push_back(i);
		
		std::cout << "int_v: ";
		for (int i = 0; i < (int)int_v.size(); i++)
			std::cout << "[" << int_v[i] << "] ";
			
		std::cout << "\nSearch for number [7]: ";
		easyfind(int_v, 7);
		std::cout << "Search for number [154] : ";
		easyfind(int_v, 154);
		
		std::cout << "\n-------------*** vector<char> ***---------------\n" << std::endl;
		
		std::vector<char>	char_v;
		char 				c = 'a';
		
		for (int i = 0; i <= 5; i++)
		{
			c++;
			char_v.push_back(c);
		}
		
		std::cout << "char_v: ";
		for (int i = 0; i < (int)char_v.size(); i++)
			std::cout << "[" << char_v[i] << "] ";
		
		std::cout << "\nSearch for character [d]: ";
		easyfind(int_v, 'd');
		std::cout << "Search for character [x] : ";
		easyfind(int_v, 'x');
		return (0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}