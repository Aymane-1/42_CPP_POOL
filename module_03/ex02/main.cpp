/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:51:16 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/08 15:15:04 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	FragTrap Lord("Genkhis khan");
	Lord.attack("Soldier");
	std::cout << Lord.GetClpTrpName() << " EnergyPoints are: " << Lord.GetClpTrpEnergyPoints() << std::endl;
	Lord.highFiveGuys();
}