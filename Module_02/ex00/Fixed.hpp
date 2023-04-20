/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 23:53:23 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/19 23:58:29 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class fixedPoint{
	private:
		int	fixedPointVal;
		static const int	bits = 8;
	public:
		fixedPoint();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		~fixedPoint();
};

#endif