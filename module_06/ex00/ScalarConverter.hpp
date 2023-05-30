/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:22:25 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/30 01:25:18 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

class ScalarConverter{
	private:
		char	c;
		int		iNumber;
		float	fNumber;
		double	dNumber;
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &obj);
		ScalarConverter	&operator=(const ScalarConverter &obj);
		void	convert(std::string	literalForm);
		void	convertData(int type, std::string input);
		void	print(std::string input);
		~ScalarConverter();
};

#endif