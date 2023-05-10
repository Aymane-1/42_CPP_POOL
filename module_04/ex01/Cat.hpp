/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:50:36 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/10 15:19:02 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal{
	public:
		Cat();
		Cat(const Cat &obj);
		Cat	&operator=(const Cat &obj);
		void	makeSound() const;
		~Cat();
	private:
		Brain *brain;
};

#endif