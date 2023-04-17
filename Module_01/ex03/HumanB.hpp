/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 00:42:51 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/17 04:56:49 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB{
	private:
		std::string name;
		Weapon & weapon;
	public:
		HumanB(std::string name);
		// void	set_Weapon(Weapon weapon);
		void	attack();
};

#endif