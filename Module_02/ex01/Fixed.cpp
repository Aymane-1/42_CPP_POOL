/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:22:57 by aymane            #+#    #+#             */
/*   Updated: 2023/04/27 17:59:31 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//------------------------*** CONSTRUCTORS ***---------------------------------------

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->FixedVal = 0;
}

Fixed::Fixed(const int integer)
{
	std::cout << "Int constructor called" << std::endl;
	this->FixedVal = integer << bits;
}

Fixed::Fixed(const float integer)
{
	std::cout << "Float constructor called" << std::endl;
	this->FixedVal = roundf((integer * (float)(1 << this->bits)));
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

//-----------------------*** MEMBER FUNCTIONS OF FIXED CLASS ***---------------------

float	Fixed::toFloat(void) const
{
	return ((float)(this->FixedVal) / (float)(1 << Fixed::bits));
}

int	Fixed::toInt(void) const
{
	return (this->FixedVal >> Fixed::bits);
}

//-------------------*** COPY ASSIGNEMENT OPERATOR ***-------------------------------

Fixed &Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->FixedVal = obj.FixedVal;
	return (*this);
}

//---------------------------*** ACCESSORS ***---------------------------------------

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->FixedVal);
}

void	Fixed::setRawBits(int const raw)
{
	this->FixedVal = raw;
}

//-----------------------*** DESTRUCTOR ***------------------------------------------

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

//-----------------------*** OPERATOR OVERLOAD ***-----------------------------------

std::ostream &operator << (std::ostream &out, const Fixed &obj)
{
	out << obj.toFloat();
	return out;
}