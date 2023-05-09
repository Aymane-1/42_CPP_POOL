/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:23:37 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/09 15:25:36 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

//---------------------------------*** Constructors ***-------------------------

Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
	this->type = "Some unknown species";
}

Animal::Animal(std::string type)
{
	this->type = type;
	std::cout << "Animal parametrized constructor called" << std::endl;
}

//--------------------------------*** Copy constructor ***----------------------

Animal::Animal(const Animal &obj)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = obj;
}

//-------------------------------*** Copy assignement ***-----------------------

Animal	&Animal::operator=(const Animal &obj)
{
	std::cout << "Animal copy assignement called" << std::endl;
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

//-------------------------------*** Accessors ***------------------------------

std::string	Animal::getType(void) const
{
	return (this->type);
}

void	Animal::setType(std::string name)
{
	this->type = name;
}

void	Animal::makeSound(void) const
{
	std::cout << "Some weird unbearable sounds from an unknown species..." << std::endl;
}


//------------------------------*** Destructor ***------------------------------

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}