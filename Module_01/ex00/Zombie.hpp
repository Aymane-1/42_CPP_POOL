/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 02:34:08 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/16 22:53:23 by aechafii         ###   ########.fr       */
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

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

# endif