/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 00:00:18 by aechafii          #+#    #+#             */
/*   Updated: 2023/06/04 21:06:52 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <vector>
#include <stack>
#include <deque>
#include <list>

template <typename T, typename T_container = std::deque<T> >
class MutantStack: public std::stack<T, T_container>{
	public:
		MutantStack(){};
		MutantStack(const MutantStack &obj){(void)&obj;};
		MutantStack	&operator=(const MutantStack &obj){(void)&obj;};
		~MutantStack(){};
		typedef typename T_container::iterator iterators;
		iterators    begin(void)
		{
			return this->c.begin();
		}
		iterators	end(void)
		{
			return this->c.end();
		}
};

#endif