/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymane <aymane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:19:51 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/07 22:07:54 by aymane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//------------------------------*** Constructors ***------------------------------

ClapTrap::ClapTrap():HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
	std::cout << "Default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name):HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
	std::cout << "Parametrized constructor called." << std::endl;
	this->name = name;
}

//------------------------------*** Copy Constructor ***--------------------------

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = obj;
}

//-----------------------------*** Copy assignement ***---------------------------

ClapTrap	&ClapTrap::operator=(const ClapTrap &obj)
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

//----------------------------*** Member functions ***----------------------------

void	ClapTrap::attack(const std::string& target)
{
	if (this->EnergyPoints)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << " causing " << this->AttackDamage << " points of damage!" << std::endl;
		this->EnergyPoints -= 1;
	}
	else
		std::cout << this->GetClpTrpName() << " cannot attack!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->HitPoints)
	{
		std::cout << "ClapTrap " << this->name << " got hit! Deduction of " << amount << " of HitPoints." << std::endl;
		this->HitPoints -= amount;
		if (this->HitPoints < 0)
			this->HitPoints = 0;
	}
	else
		std::cout << this->GetClpTrpName() << " is wasted!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->EnergyPoints)
	{
		std::cout << "ClapTrap "  << this->name << " is regenerating " << amount << " of HitPoints back."<< std::endl;
		this->HitPoints += amount;
		this->EnergyPoints -= 1;
	}
	else
		std::cout << this->GetClpTrpName() << " cannot repair itself!" << std::endl;
}

//-----------------------------*** Getters ***-------------------------------------

std::string	ClapTrap::GetClpTrpName(void) const
{
	return (this->name);
}

int	ClapTrap::GetClpTrpHitPoints(void) const
{
	return (this->HitPoints);
}

int	ClapTrap::GetClpTrpEnergyPoints(void) const
{
	return (this->EnergyPoints);
}

int	ClapTrap::GetClpTrpAttackDamage(void) const
{
	return (this->AttackDamage);
}

//--------------------------*** Desctructor ***------------------------------------

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}