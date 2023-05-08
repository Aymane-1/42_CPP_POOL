/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:23:37 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/08 21:07:10 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

//---------------------------------*** Constructors ***-------------------------

Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
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

std::string	Animal::getType(void)
{
	return (this->type);
}

void	Animal::setType(std::string name)
{
	this->type = name;
}

void	Animal::makeSound(void)
{
	if (this->type == "Dog")
		std::cout << "Woof Woof!" << std::endl;
	else if (this->type == "Cat")
		std::cout << "Miaaw!" << std::endl;
}


//------------------------------*** Destructor ***------------------------------

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}