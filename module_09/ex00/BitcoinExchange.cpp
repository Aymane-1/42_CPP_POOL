/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:42:14 by aechafii          #+#    #+#             */
/*   Updated: 2023/06/08 16:28:17 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	isWhiteSpaces(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	whiteSpacesSkipper(std::string str, size_t &index)
{
	while (str[index] && isWhiteSpaces(str[index]))
		index++;
}

void	whiteSpacesEraser(std::string &str, size_t index)
{
	while (str[index] && isWhiteSpaces(str[index]))
		str.erase(index--);
}

void storeData(std::map<std::string, double, std::greater<std::string> > &data)
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

void	printMap(std::map<std::string, double, std::greater<std::string> > data)
{
	std::map<std::string, double, std::greater<std::string> >::iterator it = data.begin();
	while (it != data.end())
	{
		std::cout << it->first << " | " << it->second << std::endl;
		it++;
	}
}

void		processInput(char *argument, std::map<std::string, double, std::greater<std::string> > &data)
{
	std::ifstream	inputFile;
	std::string		line;

	inputFile.open(argument);
	if (!inputFile.is_open())
		throw std::runtime_error("Could not open file.");
	while(std::getline(inputFile, line) && line.empty())
		;
	if (checkHeader(line) == -1)
	{
		std::cout << "Error: check header!" << std::endl;
		return ;
	}
	while(std::getline(inputFile, line))
	{
		if (line.empty())
			continue;
		int pipeIndex = line.find("|");
		processLine(line, pipeIndex, data);
	}
	
}

void	processLine(std::string line, int pipeIndex, std::map<std::string, double, std::greater<std::string> > &data)
{
	if (pipeIndex == -1)
		std::cout << "Error: bad input => " << line << std::endl;
	else if (pipeIndex)
	{
		if (checkSyntax(line) == -1 || checkDate(line) == "Error" || checkValue(line) == -1)
			return ;
		else
			getExchangeRate(checkDate(line), checkValue(line), data);
	}
}


int	checkHeader(std::string line)
{
	size_t startIndex = 0;
	whiteSpacesEraser(line, line.length() - 1);
	whiteSpacesSkipper(line, startIndex);
	size_t endIndex = startIndex;
	while (isalpha(line[endIndex]))
		endIndex++;
	std ::string part1 = line.substr(startIndex, endIndex);
	whiteSpacesEraser(part1, part1.length() - 1);
	startIndex = line.find("|") + 1;
	whiteSpacesSkipper(line, startIndex);
	endIndex = startIndex;
	while (isalpha(line[endIndex]))
		endIndex++;
	std ::string part2 = line.substr(startIndex, endIndex);
	whiteSpacesEraser(part2, part2.length() - 1);
	std::string header = part1 + " | " + part2;
	if (header == "date | value")
		return (0);
	return (-1);
	
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

std::string checkDate(std::string line)
{
	size_t startIndex = 0;
	size_t pipeIndex = line.find("|");
	if (pipeIndex == std::string::npos)
	{
		std::cout << "Error: bad input => " << line << std::endl;	
		return ("Error"); 
	}
	std::string date = line.substr(0, pipeIndex - 1);
	int hyphenIndex = date.find("-");
	if ((date[hyphenIndex] != '-' && date[hyphenIndex + 3] != '-'))
	{
		std::cout << "Error: bad input => " << line << std::endl;	
		return ("Error"); 
	}
	whiteSpacesSkipper(date, startIndex);
	while (date[startIndex] && isdigit(date[startIndex]))
		startIndex++;
	size_t endIndex =  hyphenIndex + 6;
	startIndex = endIndex;
	whiteSpacesSkipper(date, startIndex);
	if (startIndex != (size_t)date.length())
	{
		std::cout << "Error: bad input => " << line << std::endl;	
		return ("Error");
	}
	size_t i = 0;
	whiteSpacesSkipper(date, i);
	int year = std::stoi(date.substr(i, date.find("-")));
	int month = std::stoi(date.substr(date.find("-") + 1, date.find("-") + 2));
	int day = std::stoi(date.substr(date.find("-") + 4, endIndex));
	if (year < 2009 || month > 12 || month < 1 || day < 1 || day > 31)
	{
		std::cout << "Error: bad input => " << line << std::endl;	
		return ("Error");
	}
	if (day == 29 && month == 2 && \
		!(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
	{
		std::cout << "Error: Non-existant date => " << line << std::endl;	
		return ("Error");
	}
	return (date.substr(i, endIndex));
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

double			checkValue(std::string line)
{
	size_t startIndex = line.find("|") + 1;
	whiteSpacesSkipper(line, startIndex);
	std::string	sValue = line.substr(startIndex, line.length());
	startIndex = 0;
	if (sValue[startIndex] == '-')
		startIndex++;
	while (sValue[startIndex] && isdigit(sValue[startIndex]))
		startIndex++;
	if (sValue[startIndex] == '.')
	{
		startIndex++;	
		while (sValue[startIndex] && isdigit(sValue[startIndex]))
			startIndex++;
	}
	whiteSpacesSkipper(sValue, startIndex);
	if (startIndex != sValue.length() && !isFloat(sValue))
	{
		std::cout << "here" << std::endl;
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
	return (value);
}

void	getExchangeRate(std::string date, double value, std::map<std::string, double, std::greater<std::string> > &data)
{
	whiteSpacesEraser(date, date.length() - 1);
	std::map<std::string, double, std::greater<std::string> >::iterator it = data.lower_bound(date);
	if (it != data.end())
		std::cout << it->first << " => " << value << " = "  << it->second * value << std::endl;		
 }
