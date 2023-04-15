/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 22:02:59 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/15 02:24:31 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook{
	private:
	Contact contacts[9];
	public:
	int			check_input(std::string s);
	void		entry_display(void);
	void		Search(int index);
	void		PhoneTable(int index);
	void		Prompt(int index);
	void		set_Contact(int index);
	void		PhoneBookList(int index);
	void		TextTraiter(int index);
	int			FindIndex(int index);
	int			IndexParser(std::string input);
};

#endif