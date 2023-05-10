/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:52:49 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/10 15:35:20 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

//------------------------*** Constructors ***--------------------------------

WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor called" << std::endl;
	this->type = "Centipede";
}

//-------------------------*** Copy constructor ***----------------------------

WrongCat::WrongCat(const WrongCat &obj)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = obj;
}

//-------------------------*** Copy constructor ***----------------------------

WrongCat &WrongCat::operator=(const WrongCat &obj)
{
	std::cout << "WrongCat copy assignement called" << std::endl;
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

//-------------------------*** Destructor ***----------------------------------

void	WrongCat::makeSound(void) const
{
	std::cout << "A wrongCat sound whatever that is, is being diffused!" << std::endl;
}

//-------------------------*** Destructor ***----------------------------------

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called." << std::endl;
}