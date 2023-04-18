/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 00:38:34 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/18 02:06:13 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA{
	private:
		std::string name;
		Weapon &weapon;
	public:
		HumanA(std::string name, Weapon &tool);
		void	attack(void);
};

#endif