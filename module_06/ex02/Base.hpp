/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:43:46 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/31 00:39:39 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>

class Base{
	public:
		Base	*generate(void);
		void	identify(Base *p);
		void	identify(Base &p);
		virtual ~Base();
};

#endif 