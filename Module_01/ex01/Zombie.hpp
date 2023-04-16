/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 23:08:23 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/16 23:09:17 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie{
	private:
		std::string name;
	public:
		Zombie(void);
		void		announce(void);
		std::string	get_name(void);
		void		set_name(std::string name);
		~Zombie(void);
};

Zombie* zombieHorde(int N, std::string name);

# endif