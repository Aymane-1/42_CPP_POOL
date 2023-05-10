/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:20:36 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/10 15:21:03 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

//------------------------*** Constructors ***--------------------------------

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
	this->type = "Centipede";
}

//-------------------------*** Copy constructor ***----------------------------

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = obj;
}

//-------------------------*** Copy constructor ***----------------------------

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj)
{
	std::cout << "WrongAnimal copy assignement called" << std::endl;
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

//-------------------------------*** Accessors ***------------------------------

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}

void	WrongAnimal::setType(std::string name)
{
	this->type = name;
}

//-------------------------*** Destructor ***----------------------------------

void	WrongAnimal::makeSound(void) const
{
	std::cout << "A wrongAnimal sound whatever that is, is being diffused!" << std::endl;
}

//-------------------------*** Destructor ***----------------------------------

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called." << std::endl;
}