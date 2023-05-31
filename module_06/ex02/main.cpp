/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:43:14 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/31 01:26:17 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
	Base obj;
	Base *ptr;

	ptr = obj.generate();
	obj.identify(ptr);
	
	std::cout << "--------------------------------" << std::endl;
	
	Base &ptri = *ptr; 
	obj.identify(ptri);
	return (0);
}