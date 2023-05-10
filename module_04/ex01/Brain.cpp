/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:38:18 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/10 16:47:19 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

//---------------------------------*** Constructor ***-------------------------

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

//--------------------------------*** Copy constructor ***----------------------

Brain::Brain(const Brain &obj)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = obj;
}

//-------------------------------*** Copy assignment ***-----------------------

Brain	&Brain::operator=(const Brain &obj)
{
	std::cout << "Brain copy assignement called" << std::endl;
	if (this != &obj)
		for (int i = 0; i < 100; i++)
			this->ideas[i] = obj.ideas[i];
	return (*this);
}

//------------------------------*** Member functions ***------------------------------


//------------------------------*** Destructor ***------------------------------

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}