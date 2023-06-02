/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 01:33:02 by aechafii          #+#    #+#             */
/*   Updated: 2023/06/01 04:10:04 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{	
	char	charArr[3] = {'a', 'b', 'c'};
	int		intArr[3]  = {1, 2, 3};
	float	fltArr[3]  = {1.5f, 2.5f, 3.5f};
	double	dblArr[3]  = {1.5, 2.5, 3.5};
	
	std::cout << "char array: ";
	iter<char>(charArr, 3, func);
	std::cout << "\nint array: ";
	iter<int>(intArr, 3, func);
	std::cout << "\nfloat array: ";
	iter<float>(fltArr, 3, func);
	std::cout << "\ndouble array: ";
	iter<double>(dblArr, 3, func);

	return (0);
}