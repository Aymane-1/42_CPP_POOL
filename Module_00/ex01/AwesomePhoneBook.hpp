/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AwesomePhoneBook.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 22:02:59 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/12 03:35:31 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef AWESOMEPHONEBOOK_HPP
# define AWESOMEPHONEBOOK_HPP

#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <iomanip>

class Contact{
	private:
	std::string FirstName;
	std::string LastName;
	std::string NickName;
	std::string PhoneNumber;
	std::string DarkestSecret;
	public:
	std::string	get_FirstName(void);
	std::string	get_LastName(void);
	std::string	get_NickName(void);
	std::string	get_PhoneNumber(void);
	std::string	get_DarkestSecret(void);
	void		set_FirstName(std::string s);
	void		set_LastName(std::string s);
	void		set_NickName(std::string s);
	void		set_PhoneNumber(std::string s);
	void		set_DarkestSecret(std::string s);
};

class PhoneBook{
	private:
	Contact contacts[8];
	public:
	int			check_input(std::string s);
	void		entry_display(void);
	void		Add(Contact &NewContact);
	void		Search(PhoneBook &Book);
	void		Exit(void);
	void		prompt(void);
	void		set_Contact(void);
	void		PhoneBookList(void);
	std::string	TextTraiter(std::string s);
	// std::string	get_Contact(void);
};

#endif