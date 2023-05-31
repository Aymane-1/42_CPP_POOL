/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:43:43 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/31 01:25:26 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*Base::generate(void)
{
	srand(time(NULL));
	int RandomNumber = rand() % 3;
	Base	*obj;
	switch (RandomNumber)
	{
		case 0 :
			obj = new A;
			return (obj);
		case 1 :
			obj = new B;
			return (obj);
		case 2 :
			obj = new C;
			return (obj);
	}
	return (NULL);
}

void	Base::identify(Base *p)
{
	A	*ptrA;
	B	*ptrB;
	C	*ptrC;
	
	ptrA = dynamic_cast <A*> (p);
	if (ptrA)
		std::cout << "Type of object is 'A'" << std::endl;
	ptrB = dynamic_cast <B*> (p);
	if (ptrB)
		std::cout << "Type of object is 'B'" << std::endl;
	ptrC = dynamic_cast <C*> (p);
	if (ptrC)
		std::cout << "Type of object is 'C'" << std::endl;
}

void	Base::identify(Base &p)
{
	try
	{
		A ptrA;
		
		ptrA = dynamic_cast <A&> (p);
		std::cout << "Type of object is 'A'" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		std::cerr << " ... attempt to cast to 'A' failed." << '\n';
	}
	try
	{
		B ptrB;
		
		ptrB = dynamic_cast <B&> (p);
		std::cout << "Type of object is 'B'" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		std::cerr << " ... attempt to cast to 'B' failed." << '\n';
	}
	try
	{
		C ptrC;
		
		ptrC = dynamic_cast <C&> (p);
		std::cout << "Type of object is 'C'" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		std::cerr << " ... attempt to cast to 'C' failed." << '\n';
	}
}

Base::~Base()
{

}