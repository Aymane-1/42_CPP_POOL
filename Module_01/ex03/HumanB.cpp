/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 01:04:25 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/17 18:39:40 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
// #include "Weapon.hpp"

void	HumanB::attack()
{
	std::cout << HumanB::name << " attacks with their " << HumanB::weapon.getType() << std::endl;
}

HumanB::HumanB(std::string name)
{
	this->name = name;
}			