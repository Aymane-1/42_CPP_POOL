/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:51:16 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/07 20:39:34 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap X("Napoleon");
	ClapTrap Y("Genghis khan");
	X.attack("Acquilis");
	Y.takeDamage(3);
	std::cout <<  "X HitPoints " << X.GetClpTrpHitPoints() << std::endl;
	std::cout <<  "X EnergyPoints " << Y.GetClpTrpEnergyPoints() << std::endl;
}