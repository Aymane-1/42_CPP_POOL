/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:06:29 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/28 20:24:40 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <stdlib.h>

class Fixed{
	private:
		int					FixedVal;
		static const int	bits = 8;
	public:
		Fixed();
		Fixed(const int number);
		Fixed(const float number);
		Fixed(const Fixed &obj); // copy constructor
		Fixed &operator=(const Fixed &obj); // copy assignement
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		~Fixed();
		bool    operator>(const Fixed &obj);
        bool    operator<(const Fixed &obj);
        bool    operator>=(const Fixed &obj);
        bool    operator<=(const Fixed &obj);
        bool    operator==(const Fixed &obj);
        bool    operator!=(const Fixed &obj);
        Fixed   operator+(const Fixed &obj);
        Fixed   operator-(const Fixed &obj);
        Fixed   operator*(const Fixed &obj);
        Fixed   operator/(const Fixed &obj);
        Fixed   operator++(void);
        Fixed   operator++(int);
        Fixed   operator--(void);
        Fixed   operator--(int);
        static  Fixed &min(Fixed &number1, Fixed &number2);
        static  Fixed &min(const Fixed &number1, const Fixed &number2);
        static  Fixed &max(Fixed &number1, Fixed &number2);
        static  Fixed &max(const Fixed &number1, const Fixed &number2);
	private:
};

std::ostream &operator << (std::ostream &out, const Fixed &obj);

#endif