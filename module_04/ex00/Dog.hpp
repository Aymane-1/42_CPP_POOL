/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:41:19 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/09 13:11:35 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal{
	public:
		Dog();
		Dog(std::string name);
		Dog(const Dog &obj);
		Dog	&operator=(const Dog &obj);
		void		makeSound() const;
		~Dog();
};

#endif