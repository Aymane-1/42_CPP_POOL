/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymane <aymane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:41:07 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/11 18:33:12 by aymane           ###   ########.fr       */
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
		delete this->brain;
		this->brain = new Brain();
		*(this->brain) = *(obj.brain);
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