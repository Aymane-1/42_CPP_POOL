/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 23:32:26 by aechafii          #+#    #+#             */
/*   Updated: 2023/06/03 02:51:39 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): N(0)
{
	std::cout << "Span default constructor called." << std::endl;
	int_v = std::vector<int>(N);
}

Span::Span(unsigned int n): N(n)
{
	std::cout << "Span parametrized constructor called." << std::endl;
	int_v.reserve(N);
}

Span::Span(const Span &obj)
{
	*this = obj;
}

Span	&Span::operator=(const Span &obj)
{
	if (this != &obj)
	{
		this->N = obj.N;
		for (int i = 0; i < (int)int_v.size(); i++)
			this->int_v[i] = obj.int_v[i];
	}
	return (*this);
}

void	Span::addNumber(int number)
{
	if ((unsigned int)int_v.size() == N)
		throw std::out_of_range("Cannot add number, container is full!");
	int_v.push_back(number);
}

void	Span::longestSpan()
{
	int res = std::abs(*(std::max_element(int_v.begin(), int_v.end())) \
		- *(std::min_element(int_v.begin(), int_v.end())));
	if (!res)
		throw std::out_of_range("No span found!");
	std::cout << "longest distance is: " << res << std::endl;
}

void	Span::shortestSpan()
{
	std::sort(int_v.begin(), int_v.end());
	int shortestSpan = std::numeric_limits<int>::max();

    for (std::vector<int>::size_type i = 1; i < int_v.size(); ++i)
	{
        int span = int_v[i] - int_v[i - 1];
        if (span < shortestSpan) {
            shortestSpan = span;
        }
    }
	if (!shortestSpan)
		throw std::out_of_range("No span found!");
	std::cout << "shortest distance is: " << shortestSpan << std::endl;
}

void	Span::containerFiller(int number)
{
	for (int my_iterator : int_v)
		addNumber(2);
}

void	Span::displayVector()
{
	for(int i = 0; i < (int)int_v.size(); i++)
		std::cout << "[" << int_v[i] <<  "] ";
}

Span::~Span()
{
	std::cout << "Span destructor called." << std::endl;
}