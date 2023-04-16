/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 23:09:31 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/16 23:27:38 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *zombiesHorde;
	int 	i;

	i = 0;
	zombiesHorde = new Zombie[N];
	while (i < N)
	{
		zombiesHorde[i].set_name(name);
		i++;
	}
	return (zombiesHorde);
}