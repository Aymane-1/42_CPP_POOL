/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:15:48 by aechafii          #+#    #+#             */
/*   Updated: 2023/06/10 19:10:06 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2 || !argv[1][0])
		{
			std::cout << "Error: Invalid arguments!" << std::endl;
			return (0);
		}
		std::vector<int>	arr;
		std::string			input = (std::string)argv[1];
		parseInput(input);
		storeData(input, arr);
		fordJhonson(arr);
		// printData(arr);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}