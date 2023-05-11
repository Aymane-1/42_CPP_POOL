/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymane <aymane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:23:01 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/11 18:55:01 by aymane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	// Animal Wolf("MAX"); // attempt to instantiate an object from the animal abstract class. 
	Dog GermanShepherd;
	Cat MaineCoon;
	Animal *Feline = new Cat();

	std::cout << "\n-------------------*** DOG SOUND ***------------------\n" << std::endl;
	GermanShepherd.makeSound();
	std::cout << "\n-------------------*** CAT SOUND ***------------------\n" << std::endl;
	MaineCoon.makeSound();
	std::cout << "\n-------------------*** DYNAMICALLY ALLOCATED CAT SOUND ***------------------\n" << std::endl;
	Feline->makeSound();
	std::cout << "\n----------------------------------------------------------------------------\n" << std::endl;
	delete Feline;
	return (0);
}