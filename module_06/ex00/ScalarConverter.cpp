/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 20:21:34 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/30 19:45:48 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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

int	ScalarConverter::isWhiteSpaces(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	ScalarConverter::isNumeric(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ScalarConverter::isPrintable(char c)
{
	if (c >= 32 && c <= 127)
		return (1);
	return (0);
}

int	ScalarConverter::checkCharacter(std::string input)
{
	int index = 0;
	while (input[index] && isWhiteSpaces(input[index]))
		index++;
	if (index == (int)input.length())
		return (1);
	if (input[index] && !isNumeric(input[index]))
	{
		index++;
		while (input[index] && isWhiteSpaces(input[index]))
			index++;
		if (index == (int)input.length())
			return (1);
	}
	return (0);
}

int	ScalarConverter::checkInteger(std::string input, int index)
{
	if (!isNumeric(input[index - 1]))
		return (0);
	while (input[index] && isWhiteSpaces(input[index]))
		index++;
	if (index == (int)input.length())
		return (1);
	return (0);
}

int	ScalarConverter::checkFloat(std::string input, int index)
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

int	ScalarConverter::checkDouble(std::string input, int index)
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

int	ScalarConverter::checkNumericality(std::string input)
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

int	ScalarConverter::checkInput(std::string input)
{
	if (input.empty())
		return (0);
	if (checkCharacter(input))
		return (checkCharacter(input));
	if (input.length() > 9)
			return (checkRange(input));
	else if (checkNumericality(input))
		return (checkNumericality(input));
	return (0);
}

void	ScalarConverter::convertData(int type, std::string input)
{
		int i = 0;
		std::istringstream literalForm(input);
		switch (type)
		{
			case 1:
				while (input[i])
				{
					if (!isWhiteSpaces(input[i]))
						break;
					i++;
				}
				c = input[i];
				iNumber = static_cast <int> (c);
				fNumber = static_cast <float> (c);
				dNumber = static_cast <double> (c);
				break;
			case 2:
				iNumber = std::stoi(input);
				c = static_cast <char> (iNumber);
				fNumber = static_cast <float> (iNumber);
				dNumber = static_cast <double> (iNumber);
				break;
			case 3:
				literalForm >> fNumber;
				c = static_cast <char> (fNumber);
				iNumber = static_cast <int> (fNumber);
				dNumber = static_cast <double> (fNumber);
				break;
			case 4:
				literalForm >> dNumber;
				c = static_cast <char> (dNumber);
				iNumber = static_cast <int> (dNumber);
				fNumber = static_cast <float> (dNumber);
				break;
		}
}

int		ScalarConverter::isPseudoLiteral(std::string input)
{
	if (input == "nan" || input == "nanf" || input == "-inf" \
		|| input == "+inf" || input == "-inff" || input == "+inff")
		return (1);
	return (0);
}

void	ScalarConverter::print(std::string input)
{
	if (!isPseudoLiteral(input))
	{
		if (isPrintable(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << iNumber << std::endl;
		std::cout << "float: " << std::setprecision(1) << std::fixed << fNumber << 'f' << std::endl;
		std::cout << "double: " << std::setprecision(1) << std::fixed << dNumber << std::endl;
	}
	else
	{
		std::cout << "char: " << "impossible" << std::endl;
        std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "nanf" << std::endl;
		std::cout << "double: " << "nan" << std::endl;   
	}
}

int		ScalarConverter::checkRange(std::string input)
{
	try
	{
		int	testInt = std::stoi(input);  // to test if stoi throws an out of range exception 
		(void)testInt;
		return (1);
	}
	catch(const std::exception& e)
	{
		return (0);
	}
}

void	ScalarConverter::convert(std::string literalForm)
{
	int type = 5;
	try 
	{
		if (isPseudoLiteral(literalForm))
		{
			print(literalForm);
			return ;
		}
		type = checkInput(literalForm);
		if (!type)
			throw (type);
		convertData(type, literalForm);
		print(literalForm);
	}
	catch (int num)
	{
		std::cerr << "INVALID ARGUMENTS!" << std::endl;
	}
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called." << std::endl;
}