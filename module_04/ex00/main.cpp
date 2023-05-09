/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:23:01 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/09 18:10:22 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	meta->getType();
	delete meta;
	delete j;
	delete i;
	std::cout << "-------------------------------------" << std::endl;
	const WrongAnimal* x = new WrongAnimal();
	const WrongAnimal* y = new WrongCat();
	std::cout << x->getType() << " " << std::endl;
	std::cout << y->getType() << " " << std::endl;
	x->makeSound();
	y->makeSound();
	delete x;
	delete y;
	std::cout << "-------------------------------------" << std::endl;
	WrongCat Tom("Cat");
	Tom.makeSound();
	return (0);
}