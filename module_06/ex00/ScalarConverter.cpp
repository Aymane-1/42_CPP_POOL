/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 20:21:34 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/29 20:26:27 by aechafii         ###   ########.fr       */
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

int	checkCharacter(std::string input)
{
	int i = 0;
	while (input[i] && (input[i] == ' ' || input[i] == '\t'))
		i++;
	if (input[i] && input[i] >= 32 && input[i] <= 127)
	{
		i++;
		while (input[i] && (input[i] == ' ' || input[i] == '\t'))
			i++;
		if (i == (int)input.length())
			return (1);
	}
	if (input[i] && input[i] >= 0 && input[i] <= 31)
	{
		i++;
		while (input[i] && (input[i] == ' ' || input[i] == '\t'))
			i++;
		if (i == (int)input.length())
			return (0);
	}
	return (-1);
}

bool	checkInteger(std::string input)
{
	int i = 0;
	while (input[i] && (input[i] == ' ' || input[i] == '\t'))
		i++;
	while (((input[i]) && ((input[i] == '-' && \
			input[i + 1] >= 48 && input[i + 1] <= 57))) || \
				(((input[i]) && (input[i] == '+') && \
					input[i + 1] >= 48 && input[i + 1] <= 57)))
		i++;
	while (input[i] && input[i] >= 48 && input[i] <= 57)
		i++;
	while (input[i] && (input[i] == ' ' || input[i] == '\t'))
		i++;
	if (i == (int)input.length())
		return (true);
	return (false);
}

bool	checkFloat(std::string input)
{
	int i = 0;
	while (input[i] && (input[i] == ' ' || input[i] == '\t'))
		i++;
	while (((input[i]) && ((input[i] == '-' && \
			input[i + 1] >= 48 && input[i + 1] <= 57))) || \
				(((input[i]) && (input[i] == '+') && \
					input[i + 1] >= 48 && input[i + 1] <= 57)))
		i++;
	while (input[i] && (input[i] >= 48 && input[i] <= 57))
		i++;
	if (input[i] == '.')
	{
		i++;
		while (input[i] && (input[i] >= 48 && input[i] <= 57))
			i++;
		if (input[i] == 'f')
		{
			i++;
			while (input[i] && (input[i] == ' ' || input[i] == '\t'))
				i++;
		}
		if (i == (int)input.length())
			return (true);
	}
	return (false);
}

bool	checkDouble(std::string input)
{
	int i = 0;
	while (input[i] && (input[i] == ' ' || input[i] == '\t'))
		i++;
	while (((input[i]) && ((input[i] == '-' && \
			input[i + 1] >= 48 && input[i + 1] <= 57))) || \
				(((input[i]) && (input[i] == '+') && \
					input[i + 1] >= 48 && input[i + 1] <= 57)))
		i++;
	while (input[i] && (input[i] >= 48 && input[i] <= 57))
		i++;
	if (input[i] == '.')
	{
		i++;
		while (input[i] && (input[i] >= 48 && input[i] <= 57))
			i++;
		while (input[i] && (input[i] == ' ' || input[i] == '\t'))
			i++;
		if (i == (int)input.length())
			return (true);
	}
	return (false);
}

void	checkNumericality(std::string input)
{
	if (input.empty())
	{
		std::cout << "INVALID ARGUMENTS!" << std::endl;
		return ;
	}
	std::cout << "char check: " << checkCharacter(input) << std::endl;
	std::cout << "integer check: " << checkInteger(input) << std::endl;
	std::cout << "float check: " << checkFloat(input) << std::endl;
	std::cout << "double check: " << checkDouble(input) << std::endl;
}

void	ScalarConverter::convert(std::string literalForm)
{
	
	checkNumericality(literalForm);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called." << std::endl;
}