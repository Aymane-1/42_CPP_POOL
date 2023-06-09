/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 09:12:09 by aechafii          #+#    #+#             */
/*   Updated: 2023/06/09 13:10:54 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void	checkOperator(char *argument, int i, std::stack<int> rpnStack)
{
	if (rpnStack.size() <= 1)
		throw std::invalid_argument("Error: invalid input!");
	if (isOperator(argument[i + 2]) && isdigit(argument[i + 3]))
		throw std::invalid_argument("Error: negative number detected!");
}

void	checkDigits(char *argument, int i)
{
	if (isdigit(argument[i + 1]))
		throw std::invalid_argument("Error: numbers should be less than 10,therefore represented through a single digit!");
	if (argument[i + 1] != ' ' && argument[i + 1])
		throw std::invalid_argument("Error: invalid input!");
}

int	isOperator(char c)
{
	if (c == '-' || c == '+' ||c == '*' ||c == '/')
		return (1);
	return (0);
}

void processInput(char *argument)
{
	int 			i;
	std::stack<int> rpnStack;

	i = -1;
	while (argument[++i])
	{
		if (isOperator(argument[i]))
		{
			checkOperator(argument, i, rpnStack);
			operate(rpnStack, argument[i]);
		}
		else if (isdigit(argument[i]))
		{
			checkDigits(argument, i);
			rpnStack.push(argument[i] - 48);
		}
		else if (argument[i] == ' ')
			continue;
		else 
			throw std::invalid_argument("Error: invalid arguments");
	}
	if (rpnStack.size() == 1)
		std::cout << rpnStack.top() << std::endl;
	else	
		throw std::runtime_error("Error: invalid input!");
}

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
			throw std::runtime_error("Error: attempt to divide by 0!");
		res = a / b;
	}
	rpnStack.pop();
	rpnStack.push(res);
}
