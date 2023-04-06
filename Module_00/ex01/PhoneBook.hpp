/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 22:02:59 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/06 02:28:28 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <string.h>
#include <iostream>
#include <stdlib.h>

class Contact{
	public:
	void		constructor();
	void		getter();
	void		setter(std::string field, std::string s, Contact contacts);
	~Contact();
	private:
	std::string FirstName;
	std::string LastName;
	std::string NickName;
	std::string PhoneNumber;
	std::string DarkestSecret;
};

class PhoneBook{
	public:
	void		constructor();
	std::string	getter();
	void		setter(std::string s, Contact contacts);
	~PhoneBook();
	private:
	Contact contacts[8];
};

#endif