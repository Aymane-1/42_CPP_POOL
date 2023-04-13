/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 22:02:59 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/13 00:49:50 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <iomanip>
#include <ctype.h>
#include "Contact.hpp"

class PhoneBook{
	private:
	Contact contacts[8];
	public:
	int			check_input(std::string s);
	void		entry_display(void);
	void		Search(int index);
	void		Exit(void);
	void		PhoneTable(int index);
	void		Prompt(int index);
	void		set_Contact(int index);
	void		PhoneBookList(int index);
	void		TextTraiter(int index);
	// std::string	get_Contact(void);
};

#endif