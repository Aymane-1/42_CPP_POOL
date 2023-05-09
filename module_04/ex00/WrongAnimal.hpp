/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:14:47 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/09 15:25:05 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
	protected:
		std::string	type;
	public:
		WrongAnimal();
		WrongAnimal(std::string	name);
		// WrongAnimal(const WrongAnimal &obj);
		// WrongAnimal	&operator=(const WrongAnimal &obj);
		// virtual void	makeSound() const;
		virtual ~WrongAnimal();
};

#endif