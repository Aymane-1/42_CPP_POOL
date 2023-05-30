/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:54:05 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/30 22:37:06 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define  SERIALIZER_HPP

#include <iostream>

struct Data{
	int	number;	
};

class Serializer{
	public:
		Serializer();
		Serializer(Serializer const &obj);
		Serializer	&operator=(const Serializer &obj);
		uintptr_t	serialize(Data *ptr);
		Data		*deserialize(uintptr_t raw);
		~Serializer();
};


#endif