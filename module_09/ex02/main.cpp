/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:15:48 by aechafii          #+#    #+#             */
/*   Updated: 2023/06/24 21:44:38 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc < 3 || !argv[1][0] || !argv[2][0])
		{
			std::cout << "Error: Invalid arguments!" << std::endl;
			return (0);
		}
		struct timeval 		startTime, endTime;
		std::vector<int>	arr;
		std::vector<int>	result;
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

		//----------------------------------------***        DEQUE PART      ***-----------------------------------------------

		std::deque<int>	_arr;
		std::deque<int>	_result;
		_parser(argv, _arr);
		gettimeofday(&startTime, NULL);
		_result = _fordJhonson(_arr);
		gettimeofday(&endTime, NULL);
		double _elapsedTime = getTimeLap(startTime, endTime);
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::[deque]  : " << _elapsedTime << " us" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}