/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 20:21:34 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/29 23:42:30 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter default constructor called." << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
	*this = obj;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &obj)
{
	(void)obj;
	return (*this);
}

int	isWhiteSpaces(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	isNumeric(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	isPrintable(char c)
{
	if (c >= 32 && c <= 127)
		return (1);
	return (0);
}

int	isNonPrintable(char c)
{
	if (c >= 0 && c <= 31)
		return (1);
	return (0);
}

int	checkCharacter(std::string input)
{
	int index = 0;
	while (input[index] && isWhiteSpaces(input[index]))
		index++;
	if (index == 1)
		return (1);
	if (input[index] && !isNumeric(input[index]) && isPrintable(input[index]))
	{
		index++;
		while (input[index] && isWhiteSpaces(input[index]))
			index++;
		if (index == (int)input.length())
			return (1);
	}
	// else if (input[index] && isNonPrintable(input[index]))
	// {
	// 	index++;
	// 	while (input[index] && isWhiteSpaces(input[index]))
	// 		index++;
	// 	if (index == (int)input.length())
	// 		return (-1);
	// }
	return (0);
}

int	checkInteger(std::string input, int index)
{
	if (!isNumeric(input[index - 1]))
		return (0);
	while (input[index] && isWhiteSpaces(input[index]))
		index++;
	if (index == (int)input.length())
		return (1);
	return (0);
}

int	checkFloat(std::string input, int index)
{
	if (input[index] == '.')
	{
		index++;
		while (input[index] && isNumeric(input[index]))
			index++;
		if (input[index] == 'f')
		{
			index++;
			while (input[index] && isWhiteSpaces(input[index]))
				index++;
		if (index == (int)input.length())
			return (1);
		}
	}
	return (0);
}

int	checkDouble(std::string input, int index)
{
	if (input[index] == '.')
	{
		index++;
		while (input[index] && isNumeric(input[index]))
			index++;
		while (input[index] && isWhiteSpaces(input[index]))
			index++;
		if (index == (int)input.length())
			return (1);
	}
	return (0);
}

int	checkNumericality(std::string input)
{
	int index = 0;
	while (input[index] && isWhiteSpaces(input[index]))
		index++;
	while (((input[index]) && (input[index] == '-' && isNumeric(input[index + 1]))) \
		|| ((input[index]) && (input[index] == '+' && isNumeric(input[index + 1]))))
		index++;
	while (input[index] && isNumeric(input[index]))
		index++;
	if (checkInteger(input, index))
		return (2);
	else if (checkFloat(input, index))
		return (3);
	else if (checkDouble(input, index))
		return (4);
	return (0);
}

int	checkInput(std::string input)
{
	if (input.empty())
	{
		std::cout << "INVALID ARGUMENTS!" << std::endl;
		exit(1);
	}
	if (checkCharacter(input))
		return (checkCharacter(input));
	else if (checkNumericality(input))
		return (checkNumericality(input));
	return (0);
}

void	ScalarConverter::convert(std::string literalForm)
{
	std::cout << checkInput(literalForm) << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called." << std::endl;
}