/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 00:56:18 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/17 04:52:45 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void	HumanA::attack()
{
	std::cout << HumanA::name << " attacks with their " << HumanA::weapon.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon & _weapon)
{
	this->name = name;
	this->weapon = _weapon;
}
