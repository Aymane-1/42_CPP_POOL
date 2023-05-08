/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:08:10 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/08 15:14:40 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

//-------------------------*** Constructors ***-------------------------------------------

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called." << std::endl;
	this->AttackDamage = 30;
	this->HitPoints = 100;
	this->EnergyPoints = 100;
}

FragTrap::FragTrap(std::string	name)
{
	std::cout << "FragTrap parametrized constructor called." << std::endl;
	this->name = name;
	this->AttackDamage = 20;
	this->HitPoints = 100;
	this->EnergyPoints = 50;
}

//------------------------*** Copy constructor ***----------------------------------------

FragTrap::FragTrap(const FragTrap &obj)
{
	std::cout << "FragTrap Copy constructor called." << std::endl;
	*this = obj;
}

//------------------------*** Copy assingnement ***---------------------------------------

FragTrap	&FragTrap::operator=(const FragTrap &obj)
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

void	FragTrap::highFiveGuys(void)
{
	std::cout << this->name << " requests a positive high five!" << std::endl;
}

//-------------------------*** Destructor ***--------------------------------------------

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called." << std::endl;
}

