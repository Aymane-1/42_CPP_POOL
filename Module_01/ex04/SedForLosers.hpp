/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedForLosers.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 02:29:39 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/19 00:37:40 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEDFORLOSERS_HPP
#define SEDFORLOSERS_HPP

#include <fstream>
#include <iostream>
#include <string>

std::string generateOutfileName(std::string fileName)
{
	return (fileName + ".replace");
}

std::string	replaceOccurrence(std::string buffer, std::string s1, std::string s2)
{
	std::size_t index = buffer.find(s1);
	if (index != std::string::npos)
	{
		buffer.erase(index, s1.length());
		buffer.insert(index, s2);
	}
	return (buffer);
}

#endif