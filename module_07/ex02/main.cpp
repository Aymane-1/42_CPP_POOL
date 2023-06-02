/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 03:47:19 by aechafii          #+#    #+#             */
/*   Updated: 2023/06/02 19:31:33 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main()
{
	try
	{
		unsigned int length = 100;
		Array<int> intArr(length);
		Array<char> charArr;
		
		for (int i = 0; i < length; i++)
		{
			const int value = rand();
			intArr[i] = value;
		}
		// for (int i =0; i < intArr.size(); i++) // display array elements
		// 	std::cout << "[" << intArr[i] << "] ";
		std::cout << "Array length: " << intArr.size() << std::endl;
        intArr[-55] = 0; // out of bond exception thrown
        intArr[length] = 0; // out of bond exception thrown
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}