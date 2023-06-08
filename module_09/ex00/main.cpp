/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 23:44:10 by aechafii          #+#    #+#             */
/*   Updated: 2023/06/08 15:07:55 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
		{
			std::cout << "Error: could not open file." << std::endl;
			return (0);
		}
		std::map<std::string, double, std::greater<std::string> > data;
		storeData(data);
		// printMap(data);
		processInput(argv[1], data);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}