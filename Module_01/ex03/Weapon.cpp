/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 00:45:48 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/18 02:18:14 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string tool)
{
	this->setType(tool);
}

std::string	const &Weapon::getType()
{
	return (this->type);
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}
