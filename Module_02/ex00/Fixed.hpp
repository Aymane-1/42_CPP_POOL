/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 23:53:23 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/24 18:56:37 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
	private:
		int					FixedVal;
		static const int	bits = 8;
	public:
		Fixed(void);
		Fixed(const Fixed &obj); // copy constructor
		Fixed &operator=(const Fixed &obj); // copy assignement
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		~Fixed();
};

#endif