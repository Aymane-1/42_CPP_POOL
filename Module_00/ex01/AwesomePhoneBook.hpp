/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AwesomePhoneBook.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 22:02:59 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/07 04:54:55 by aechafii         ###   ########.fr       */
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
	void		get_FirstName(void); // return string
	void		get_LastName(void);	// return string
	void		get_NickName(void); // return string
	void		get_PhoneNumber(void); // return string
	void		get_DarkestSecret(void); // return string
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
	int		check_input(std::string s);
	void	entry_display();
	void	Add(Contact &NewContact);
	void	Search(PhoneBook &Book);
	void	Exit();
	void	set_Contact(void);
	void	PhoneBookList(Contact Cntct);
};

#endif