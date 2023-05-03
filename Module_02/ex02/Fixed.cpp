/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:22:52 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/28 20:27:57 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->FixedVal = 0;
}

Fixed::Fixed(const Fixed &obj)
{
	*this = obj;
}

Fixed::Fixed(const int  number)
{
	this->FixedVal = (number) << Fixed::bits;
}

Fixed::Fixed(const float number)
{
	this->FixedVal = roundf((number * (float)(1 << Fixed::bits)));	
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}
         
//--------------------------------- OVERLOAD ---------------------------------


Fixed &Fixed::operator=(Fixed const &obj)
{
	if (this != &obj)
		this->FixedVal = obj.FixedVal;
	return (*this);
}

std::ostream &operator<<( std::ostream &out, Fixed const &obj)
{
	out << obj.toFloat();
	return (out);
}


//---------------------------------*** ACCESSORS ***----------------------------------

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->FixedVal);
}

void	Fixed::setRawBits( int const raw)
{
	this->FixedVal = raw;	
}

float   Fixed::toFloat(void) const
{
	return ((float)(this->FixedVal) / (float)(1 << Fixed::bits));
}

int Fixed::toInt( void ) const
{
	return (this->FixedVal >> Fixed::bits);
}


bool    Fixed::operator>(const Fixed &obj)
{
	if (this->toFloat() > obj.toFloat())
		return (true);
	return (false);
}

bool    Fixed::operator<(const Fixed &obj)
{
    if (this->toFloat() < obj.toFloat())
        return (true);
    return (false);
}

bool Fixed::operator>=(const Fixed &obj)
{
    if (this->toFloat() >= obj.toFloat())
        return (true);
    return (false);
}

bool Fixed::operator<=(const Fixed &obj)
{
    if (this->toFloat() <= obj.toFloat())
        return (true);
    return (false);
}

bool Fixed::operator==(const Fixed &obj)
{
    if (this->toFloat() != obj.toFloat())
        return (false);
    return (true);
}

bool Fixed::operator!=(const Fixed &obj)
{
    if (FixedVal == obj.FixedVal)
        return (false);
    return (true);
}

Fixed	Fixed::operator+(const Fixed &obj)
{
	float	result = this->toFloat() + obj.toFloat();
	return (Fixed(result));
}

Fixed	Fixed::operator-(const Fixed &obj)
{
	float	result = this->toFloat() - obj.toFloat();
	return (Fixed(result));
}

Fixed	Fixed::operator*(const Fixed &obj)
{
	float	result = this->toFloat() * obj.toFloat();
	return (Fixed(result));
}

Fixed	Fixed::operator/(const Fixed &obj)
{
	float	result = this->toFloat() / obj.toFloat();
	return (Fixed(result));	
}

Fixed &Fixed::min(Fixed &number1, Fixed &number2)
{
	if (number1.toFloat() < number2.toFloat())
		return (number1);
	return (number2);
}

Fixed & Fixed::min(const Fixed & number1, const Fixed & number2)
{
	if (number1.toFloat() < number2.toFloat())
		return ((Fixed &)number1);
	return ((Fixed &)number2);
}

Fixed & Fixed::max(const Fixed & number1, const Fixed & number2)
{
	if (number1.toFloat() > number2.toFloat())
		return ((Fixed &)number1);
	return ((Fixed &)number2);
}

Fixed & Fixed::max(Fixed & number1, Fixed & number2)
{
	if (number1.toFloat() > number2.toFloat())
		return (number1);
	return (number2);		
}

Fixed	Fixed::operator++(void)
{
	++FixedVal;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed obj = Fixed(this->toFloat());
	this->FixedVal++;
	return (obj);
}

Fixed	Fixed::operator--(void)
{
	return (Fixed(--FixedVal));
}

Fixed	Fixed::operator--(int)
{
	return (Fixed(FixedVal--));
}