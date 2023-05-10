/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:41:07 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/10 17:29:32 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//---------------------------------*** Constructors ***-------------------------

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

//--------------------------------*** Copy constructor ***----------------------

Dog::Dog(const Dog &obj)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = obj;
}

//-------------------------------*** Copy assignement ***-----------------------

Dog	&Dog::operator=(const Dog &obj)
{
	std::cout << "Dog copy assignement called" << std::endl;
	if (this != &obj)
	{	
		this->type = obj.type;
		this->brain = new Brain();
	}
	return (*this);
}

//------------------------------*** Member functions ***------------------------------

void	Dog::makeSound(void) const
{
	std::cout << "Woof Woof!" << std::endl;
}

//------------------------------*** Destructor ***------------------------------

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}