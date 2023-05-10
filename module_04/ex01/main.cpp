/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:23:01 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/10 21:44:19 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
	std::cout << "\n-------------------*** CREATION OF 2 DOGS ***------------------\n" << std::endl; 
	Animal *Animals[4];
	for (int i = 0; i < 2; i++)
		Animals[i] = new Dog();
	std::cout << "\n------------------*** CREATION OF 2 CATS ***-------------------\n" << std::endl; 
	for (int i = 2; i < 4; i++)
		Animals[i] = new Cat();
	std::cout << "\n------------*** DELETION OF DOG AND CAT OBJECTS ***------------\n" << std::endl; 
	for (int i = 0; i < 4; i++)
		delete Animals[i];
	// system("leaks App");
	return (0);
}