/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:42:14 by aechafii          #+#    #+#             */
/*   Updated: 2023/06/06 04:52:57 by aechafii         ###   ########.fr       */
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
		processLine(line, pipeIndex);
	}
	
}

void	processLine(std::string line, int pipeIndex)
{
	if (pipeIndex == -1)
		std::cout << "Error: bad input => " << line << std::endl;
	else if (pipeIndex)
	{
		if (checkSyntax(line) == -1 || checkDate(line) == -1)
			std::cout << "Error: bad input => " << line << std::endl;
	}
}

int	checkSyntax(std::string line)
{
	for (int i = 0; i < (int)line.length(); i++)
	{
		if (!isdigit(line[i]) && !isWhiteSpaces(line[i]) \
				&& line[i] != '-' && line[i] != '|' && line[i] != '.')
			return (-1);
	}
	return (1);
}

int checkDate(std::string line)
{
	std::string year = line.substr(0, line.find("|"));
	whiteSpacesTrimmer(year);
	return (0);
}

void	whiteSpacesTrimmer(std::string &date)
{
	for (int i = 0; i < (int)date.length(); i++)
	{
		if (date[i] == ' ')
			date.erase(i);
	}
}