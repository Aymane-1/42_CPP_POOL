/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:22:25 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/30 19:29:50 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <sstream>

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
		int		isWhiteSpaces(char c);
		int		isNumeric(char c);
		int		isPrintable(char c);
		int		isPseudoLiteral(std::string input);
		int		checkInput(std::string literalForm);
		int		checkCharacter(std::string input);
		int		checkRange(std::string input);
		int		checkNumericality(std::string input);
		int		checkInteger(std::string input, int index);
		int		checkFloat(std::string input, int index);
		int		checkDouble(std::string input, int index);
		~ScalarConverter();
};


#endif