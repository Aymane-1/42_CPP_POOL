/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:50:36 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/08 21:09:00 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal{
	public:
		Cat();
		Cat(std::string name);
		Cat(const Cat &obj);
		Cat	&operator=(const Cat &obj);
		~Cat();
};

#endif