/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:41:07 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/08 21:12:23 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//---------------------------------*** Constructors ***-------------------------

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string name)
{
	std::cout << "Dog default constructor called" << std::endl;
	if (name == "Dog")
		this->type = name;
	else
		this->type = "Some kinda specie...";
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
		this->type = obj.type;
	return (*this);
}

//------------------------------*** Member functions ***------------------------------

//------------------------------*** Destructor ***------------------------------

Dog::~Dog()
{
	std::cout << "Dog default destructor called" << std::endl;
}