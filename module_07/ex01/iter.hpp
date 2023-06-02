/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 01:33:09 by aechafii          #+#    #+#             */
/*   Updated: 2023/06/01 01:53:57 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>

void	iter(T *arrAddress, T arrLength, void (*func)(T value))
{
	int i = 0;
	while (i < arrLength)
		func(arrAddress[i++]);
}

template <typename T>

void	func(T value)
{
	std::cout << "[" << value << "] ";
}

#endif