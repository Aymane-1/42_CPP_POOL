/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 23:26:56 by aechafii          #+#    #+#             */
/*   Updated: 2023/06/03 02:45:42 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <exception>
#include <cmath>

class Span{
	private:
		unsigned int		N;
		std::vector<int>	int_v;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &obj);
		Span	&operator=(const Span &obj);
		void	addNumber(int number);
		void	shortestSpan();
		void	longestSpan();
		void	containerFiller(int number);
		void	displayVector();
		~Span();
};

#endif