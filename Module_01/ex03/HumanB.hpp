/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 00:42:51 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/18 02:16:23 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB{
	private:
		std::string name;
		Weapon *weapon;
	public:
		HumanB(std::string name);
		void    setWeapon(Weapon &tool);
		void	attack(void);
};

#endif