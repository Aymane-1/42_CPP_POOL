/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 01:04:25 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/18 02:14:02 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
}

void	HumanB::attack()
{
	std::cout << HumanB::name << " attacks with their " << this->weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon &tool)
{
    this->weapon = &tool;
}
