/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:15:48 by aechafii          #+#    #+#             */
/*   Updated: 2023/06/22 16:09:27 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	try
	{
		(void)argc;
		(void)argv;
		if (!argv[1][0])
		{
			if (argc < 2)
				std::cout << "Error: Invalid arguments!" << std::endl;
			else
				std::cout << "Error: Numbers should be 4 or more in order to start the sort!" << std::endl;
			return (0);
		}
		struct timeval 		startTime, endTime;
		std::vector<int>	arr;
		std::vector<int>	result;
		std::string			input = "";
		parser(argv, arr);
		gettimeofday(&startTime, NULL);
		result = fordJhonson(arr);
		gettimeofday(&endTime, NULL);
		double elapsedTime = getTimeLap(startTime, endTime);
		std::cout << "Before: ";
		printData(arr);
		std::cout << "After:  ";
		printData(result);
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::[vector] : " << elapsedTime << " us" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}