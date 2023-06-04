/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 00:01:07 by aechafii          #+#    #+#             */
/*   Updated: 2023/06/04 21:08:56 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	std::cout << "\n---------------------*** MutantStack output ***--------------------\n" << std::endl;
	try
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterators it = mstack.begin();
		MutantStack<int>::iterators ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n---------------------*** List output ***--------------------\n" << std::endl;
	try
	{
		std::list<int> g;
		g.push_back(5);
		g.push_back(17);
		std::cout << g.back() << std::endl;
		g.pop_back();
		std::cout << g.size() << std::endl;
		g.push_back(3);
		g.push_back(5);
		g.push_back(737);
		g.push_back(0);
		std::list<int>::iterator it = g.begin();
		std::list<int>::iterator ite = g.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(g);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n---------------------*** Vector output ***--------------------\n" << std::endl;
	try
	{
		std::vector<int> g;
		g.push_back(5);
		g.push_back(17);
		std::cout << g.back() << std::endl;
		g.pop_back();
		std::cout << g.size() << std::endl;
		g.push_back(3);
		g.push_back(5);
		g.push_back(737);
		g.push_back(0);
		std::vector<int>::iterator it = g.begin();
		std::vector<int>::iterator ite = g.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::vector<int> s(g);
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}