/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 01:26:18 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/18 23:27:09 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedForLosers.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "INVALD ARGUMENTS!" << std::endl;
		return (0);
	}
	std::string fileName, s1, s2;
	std::string buffer;
	std::ifstream infile;
	std::ofstream outfile("hemmadi");
	fileName = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	if (!s1.size() || !s2.size())
	{
		std::cout << "NO " << std::endl;
		return (1);
	}
	infile.open(fileName, std::ios::in);
	if (!infile.is_open())
	{
		std::cout << "\e[31;1mCOULDN'T OPEN FILE!\nCHECK THAT THE FILE EXISTS OR CHANGE IT'S PERMISSIONS.\e[0m";
		return (1);
	}
	if (!outfile.is_open())
	{
		std::cout << "\e[31;1mCOULDN'T OPEN FILE!\nCHECK THAT THE FILE EXISTS OR CHANGE IT'S PERMISSIONS.\e[0m";
		return (1);
	}
	while (std::getline(infile, buffer))
	{
		buffer = replaceOccurrence(buffer, s1, s2);
		outfile << buffer << std::endl;
	}
	infile.close();
	outfile.close();
}