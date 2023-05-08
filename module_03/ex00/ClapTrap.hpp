/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:13:19 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/08 14:19:36 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap{
	private:
		std::string		name;
		int				HitPoints;
		int				EnergyPoints;
		int				AttackDamage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &obj); // COPY CONTRUCTOR
		ClapTrap &operator=(const ClapTrap &obj); // COPY ASSINGNMENT
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		std::string	GetClpTrpName(void) const;
		int			GetClpTrpHitPoints(void) const;
		int			GetClpTrpEnergyPoints(void) const;
		int			GetClpTrpAttackDamage(void) const;
		~ClapTrap();
};

#endif