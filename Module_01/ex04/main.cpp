/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 01:26:18 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/19 00:38:10 by aechafii         ###   ########.fr       */
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
	std::string infileName, outfileName, s1, s2;
	std::string buffer;
	infileName = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	if (!s1.size() || !s2.size())
	{
		std::cout << "\e[31;1mSECOND AND THIRD ARGUMENTS SHOULDN'T BE EMPTY!\e[0m" << std::endl;
		return (1);
	}
	std::ifstream infile;
	std::ofstream outfile(generateOutfileName(infileName));
	infile.open(infileName, std::ios::in);
	if (!infile.is_open())
	{
		std::cout << "\e[31;1mCOULDN'T OPEN INFILE!\nCHECK THAT THE FILE EXISTS OR CHANGE IT'S PERMISSIONS.\e[0m";
		return (1);
	}
	if (!outfile.is_open())
	{
		std::cout << "\e[31;1mCOULDN'T OPEN OUTFILE!.\e[0m";
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