/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 00:51:06 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/19 02:55:33 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << " cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << " think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	funcPtr funcs[4] = {&Harl::debug, &Harl::error, &Harl::info, &Harl::warning};
	std::string levels[4];
	levels[0] =  "DEBUG";
	levels[1] =  "INFO";
	levels[2] =  "WARNING";
	levels[3] =  "ERROR";
	int i = 0;
	while (i < 4)
	{
		if (level == levels[i])
			(funcs[i])();
		i++;
	}
}