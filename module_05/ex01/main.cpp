/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:38:11 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/18 17:31:44 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
    {
        Bureaucrat obj("Counselor", 1);
        Form form("Judge", 1, 50);
        form.beSigned(obj);
        obj.signForm(form);
        std::cout << obj;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
	return (0);
}