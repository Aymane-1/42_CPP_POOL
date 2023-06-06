/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 23:40:59 by aechafii          #+#    #+#             */
/*   Updated: 2023/06/06 04:51:18 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <exception>
#include <map>
#include <string>

void		storeData(std::map<std::string, double> &data);
void		printMap(std::map<std::string, double> data);
void		processInput(char *argument);
void		processLine(std::string line, int pipeIndex);
int			checkSyntax(std::string line);
int			checkDate(std::string line);
void		whiteSpacesTrimmer(std::string &date);

#endif