/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:22:25 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/29 22:24:39 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>

class ScalarConverter{
	private:
		// char	c;
		// int		iNumber;
		// float	fNumber;
		// double	dNumber;
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &obj);
		ScalarConverter	&operator=(const ScalarConverter &obj);
		static void	convert(std::string	literalForm);
		~ScalarConverter();
};

#endif