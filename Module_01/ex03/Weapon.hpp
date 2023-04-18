/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 00:34:26 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/18 02:10:08 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon{
	private:
		std::string	type;
	public:
		Weapon(std::string tool);
		std::string const & getType(void);
		void	setType(std::string type);
};

#endif