/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 23:20:47 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/16 23:33:22 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *newZombie;

	newZombie = zombieHorde(5, "JACK");
	int i = 0;
	while (i < 5)
	{
		newZombie[i].announce();
		i++;
	}
	delete[] newZombie;
}