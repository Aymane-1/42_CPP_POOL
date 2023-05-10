/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:25:03 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/10 16:08:28 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain &obj);
		Brain	&operator=(const Brain &obj);
		~Brain();
};

#endif