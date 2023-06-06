/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymane <aymane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:42:14 by aechafii          #+#    #+#             */
/*   Updated: 2023/06/06 11:50:30 by aymane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	isWhiteSpaces(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void storeData(std::map<std::string, double> &data)
{
	std::ifstream	dataFile;
	std::string		line;
	dataFile.open("./data.csv");
	if (!dataFile.is_open())
		throw std::runtime_error("Could not open database.");
	std::getline(dataFile, line);
	while (std::getline(dataFile, line))
	{
		std::string	date = line.substr(0, line.find(","));
		double 		test = std::atof(line.substr(line.find(",") + 1, line.length()).c_str());
		data.insert(std::make_pair(date, test));
	}
	dataFile.close();
}

void	printMap(std::map<std::string, double> data)
{
	std::map<std::string, double>::iterator it = data.begin();
	while (it != data.end())
	{
		std::cout << it->first << " | " << it->second << std::endl;
		it++;
	}
}

void	processInput(char *argument)
{
	std::ifstream	inputFile;
	std::string		line;

	inputFile.open(argument);
	if (!inputFile.is_open())
		throw std::runtime_error("Could not open file.");
	std::getline(inputFile, line);
	while(std::getline(inputFile, line))
	{
		int pipeIndex = line.find("|");
		if (line.empty())
			continue;
		processLine(line, pipeIndex);
	}
	
}

void	processLine(std::string line, int pipeIndex)
{
	if (pipeIndex == -1)
		std::cout << "Error: bad input => " << line << std::endl;
	else if (pipeIndex)
	{
		if (checkSyntax(line) == -1 || checkDate(line) == -1 || checkValue(line) == -1)
			return ;
		else
			getExchangeRate(line);
	}
}

int	checkSyntax(std::string line)
{
	for (int i = 0; i < (int)line.length(); i++)
	{
		if (!isdigit(line[i]) && !isWhiteSpaces(line[i]) \
				&& line[i] != '-' && line[i] != '|' && line[i] != '.' && line[i] != 'f')
		{
			std::cout << "Error: bad input => " << line << std::endl;	
			return (-1);
		}
	}
	return (0);
}

int checkDate(std::string line)
{
	int startIndex = 0;
	while (isWhiteSpaces(line[startIndex]))
		startIndex++;
	std::string date = line.substr(startIndex, line.find("|"));
	if ((date[4] != '-' && date[7] != '-'))
	{
		std::cout << "Error: bad input => " << line << std::endl;	
		return (-1);
	}
	startIndex += 8;
	while (date[startIndex] && isdigit(line[startIndex]))
			startIndex++;
	while (date[startIndex] && isWhiteSpaces(line[startIndex]))
			startIndex++;
	if (startIndex != (int)date.length())
	{
		std::cout << "Error: bad input => " << line << std::endl;	
		return (-1);
	}
	int year = std::stoi(date.substr(0, 4));
	int month = std::stoi(date.substr(5, 7));
	int day = std::stoi(date.substr(8, (int)date.length()));
	if (year < 2009 || month > 12 || month < 1 || day < 1 || day > 31)
	{
		std::cout << "Error: bad input => " << line << std::endl;	
		return (-1);
	}
	if (day == 29 && month == 2 && \
		!(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
	{
		std::cout << "Error: Non-existant date => " << line << std::endl;	
		return (-1);
	}
	return (0);
}

void	whiteSpacesTrimmer(std::string &date)
{
	
	for (int i = 0; i < (int)date.length(); i++)
		if (date[i] == ' ')
			date.erase(i);
}

int	isFloat(std::string input)
{
	int index = 0;
	while (input[index] && isdigit(input[index]))
		index++;
	if (input[index] == '.')
	{
		index++;
		while (input[index] && isdigit(input[index]))
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

int			checkValue(std::string line)
{
	int startIndex = line.find("|") + 1;
	while (isWhiteSpaces(line[startIndex]))
		startIndex++;
	std::string	sValue = line.substr(startIndex, line.length());
	startIndex = 0;
	while (sValue[startIndex] && isdigit(sValue[startIndex]))
		startIndex++;
	if (sValue[startIndex] == '.')
	{
		startIndex++;	
		while (sValue[startIndex] && isdigit(sValue[startIndex]))
			startIndex++;
	}
	while (sValue[startIndex] && isWhiteSpaces(sValue[startIndex]))
			startIndex++;
	if (startIndex != (int)sValue.length() && !isFloat(sValue))
	{
		std::cout << "Error: bad input => " << line << std::endl;	
		return (-1);
	}
	double value = std::atof(sValue.c_str());
	if (value < 1)
	{
		std::cout << "Error: not a positive number." << std::endl;	
		return (-1);
	}
	if (value > 1000)
	{
		std::cout << "Error: too large number." << std::endl;	
		return (-1);
	}
	return (0);
}

void	getExchangeRate(std::string line)
{
	(void)line;
}
