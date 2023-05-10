/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:14:47 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/10 15:20:40 by aechafii         ###   ########.fr       */
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
		WrongAnimal(const WrongAnimal &obj);
		WrongAnimal	&operator=(const WrongAnimal &obj);
		std::string	getType(void) const;
		void		setType(std::string name);
		void	makeSound(void) const;
		virtual ~WrongAnimal();
};

#endif