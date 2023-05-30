/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:57:26 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/30 20:08:33 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer default constructor called." << std::endl;
}

Serializer::Serializer(Serializer const &obj)
{
	std::cout << "Serializer copy constructor called." << std::endl;
	*this = obj;
}

Serializer	&Serializer::operator=(const Serializer &obj)
{
	(void)obj;
	return (*this);
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast <uintptr_t> (ptr));
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast <Data *> (raw));
}

Serializer::~Serializer()
{
	std::cout << "Serializer destructor called." << std::endl;
}