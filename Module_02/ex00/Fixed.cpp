/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 23:57:27 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/24 18:56:37 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->FixedVal = 0;
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	this->FixedVal = obj.FixedVal;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assingment operator called" << std::endl;
	if (this != &obj)
		this->FixedVal = obj.FixedVal;
	return *this;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->FixedVal);
}

void	Fixed::setRawBits(int const raw)
{
	this->FixedVal = raw;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}