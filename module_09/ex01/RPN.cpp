/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 09:12:09 by aechafii          #+#    #+#             */
/*   Updated: 2023/06/09 09:15:45 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void operate(std::stack<int> &rpnStack, char c)
{
	int a, b, res = 0;
	b = rpnStack.top();
	rpnStack.pop();
	a = rpnStack.top();
	if (c == '-')
		res = a - b;
	else if (c == '+') 
		res = a + b;
	else if (c == '*') 
		res = a * b;
	else if (c == '/') 
	{
		if (!b)
			throw std::runtime_error("Cannot divide by 0!");
		res = a / b;
	}
	rpnStack.pop();
	rpnStack.push(res);
}

void processInput(char *s)
{
	int i;
	std::stack<int> rpnStack;

	i = -1;
	while (s[++i])
	{
		if (s[i] == '-' || s[i] == '+' ||s[i] == '*' ||s[i] == '/')
			operate(rpnStack, s[i]);
		else if (isdigit(s[i]))
			rpnStack.push(s[i] - 48);
		else if (s[i] == ' ')
			continue;
		else 
			throw std::invalid_argument("Error.");
	}
	std::cout << rpnStack.top() << std::endl;
}