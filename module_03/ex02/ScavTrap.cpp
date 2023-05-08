/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 22:17:14 by aymane            #+#    #+#             */
/*   Updated: 2023/05/08 14:59:54 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//-------------------------*** Constructors ***-------------------------------------------

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called." << std::endl;
	this->AttackDamage = 20;
	this->HitPoints = 100;
	this->EnergyPoints = 50;
}

ScavTrap::ScavTrap(std::string	name)
{
	std::cout << "ScavTrap parametrized constructor called." << std::endl;
	this->name = name;
	this->AttackDamage = 20;
	this->HitPoints = 100;
	this->EnergyPoints = 50;
}

//------------------------*** Copy constructor ***----------------------------------------

ScavTrap::ScavTrap(const ScavTrap &obj)
{
	std::cout << "ScavTrap Copy constructor called." << std::endl;
	*this = obj;
}

//------------------------*** Copy assingnement ***---------------------------------------

ScavTrap	&ScavTrap::operator=(const ScavTrap &obj)
{
	if (this != &obj)
	{
		this->name = obj.name;
		this->HitPoints = obj.HitPoints;
		this->EnergyPoints = obj.HitPoints;
		this->AttackDamage = obj.AttackDamage;
	}
	return (*this);
}

//-------------------------*** Member functions ***--------------------------------------

void	ScavTrap::attack(const std::string& target)
{
	if (this->EnergyPoints)
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target << " causing " << this->AttackDamage << " points of damage!" << std::endl;
		this->EnergyPoints -= 1;
	}
	else
		std::cout << this->GetClpTrpName() << " cannot attack!" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode!" << std::endl;
}

//-------------------------*** Destructor ***--------------------------------------------

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called." << std::endl;
}

