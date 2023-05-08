/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:23:44 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/08 21:20:32 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string name);
		Animal(const Animal &obj);
		Animal	&operator=(const Animal &obj);
		std::string	getType(void);
		void		setType(std::string name);
		void		makeSound();
		~Animal();
};

#endif