/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymane <aymane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:51:16 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/07 22:42:43 by aymane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap Warrior("Napoleon");
	Warrior.attack("Acquilis");
	std::cout <<  Warrior.GetClpTrpName() << " EnergyPoints " << Warrior.GetClpTrpEnergyPoints() << std::endl;
	Warrior.takeDamage(3);
	std::cout <<  Warrior.GetClpTrpName() <<  " HitPoints are " << Warrior.GetClpTrpHitPoints() << std::endl;
	Warrior.beRepaired(3);
	std::cout <<  Warrior.GetClpTrpName() << " EnergyPoints are " << Warrior.GetClpTrpHitPoints() << std::endl;
}