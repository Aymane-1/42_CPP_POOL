/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:51:16 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/09 13:25:06 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//---------------------------------*** Constructors ***-------------------------

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(std::string name)
{
	std::cout << "Cat default constructor called" << std::endl;
	if (name == "Cat")
		this->type = name;
}

//--------------------------------*** Copy constructor ***----------------------

Cat::Cat(const Cat &obj)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = obj;
}

//-------------------------------*** Copy assignement ***-----------------------

Cat	&Cat::operator=(const Cat &obj)
{
	std::cout << "Cat copy assignement called" << std::endl;
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

//------------------------------*** Member functions ***------------------------------

void	Cat::makeSound(void) const
{
	std::cout << "Miaaw!" << std::endl;
}

//------------------------------*** Destructor ***------------------------------

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}