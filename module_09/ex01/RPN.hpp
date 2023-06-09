/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:55:56 by aechafii          #+#    #+#             */
/*   Updated: 2023/06/09 12:13:04 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

void	checkOperator(char *s, int i, std::stack<int> rpnStack);
void	checkDigits(char *s, int i);
int		isOperator(char c);
void 	operate(std::stack<int> &stk, char c);
void 	processInput(char *s);

#endif