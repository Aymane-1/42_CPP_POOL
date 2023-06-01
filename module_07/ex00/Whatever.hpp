/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 00:54:10 by aechafii          #+#    #+#             */
/*   Updated: 2023/06/01 01:23:22 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>

void swap(T &value_1, T &value_2)
{
	T temp;
	temp = value_1;
	value_1 = value_2;
	value_2 = temp;
}

template <typename T>

T min(T value_1, T value_2)
{
	if (value_2 <= value_1)
		return (value_2);
	return (value_1);	
}

template <typename T>

T max(T value_1, T value_2)
{
	if (value_2 >= value_1)
		return (value_2);
	return (value_1);	
}

#endif