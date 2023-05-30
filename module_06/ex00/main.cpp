/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 21:06:12 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/30 19:48:03 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "INVALID NUMBER OF ARGUMENTS!" << std::endl;
		return (0);
	}
	ScalarConverter obj;
	obj.convert(argv[1]);
	return (0);
}