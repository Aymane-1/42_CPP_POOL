/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 02:37:36 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/16 02:52:07 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
}

Zombie::~Zombie(void)
{
}

std::string	get_name(void)
{
	
}

void	Zombie::announce(void)
{
	std::cout << Zombie::name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* newZombie( std::string name)
{
	Zombie *name;
	
}