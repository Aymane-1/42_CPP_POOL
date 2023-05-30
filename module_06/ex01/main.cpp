/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:12:24 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/30 22:37:15 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	
	Serializer	obj;
	Data		myData;
    uintptr_t	number;
    Data 		*myDataPtr;
	
    myData.number = 55;
	
    number = obj.serialize(&myData);
	
    myDataPtr = obj.deserialize(number);
    std::cout << myDataPtr->number << std::endl;
	
    return (0);
}