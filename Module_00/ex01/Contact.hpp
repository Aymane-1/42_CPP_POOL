/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 21:27:45 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/14 00:59:17 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CONTACT_HPP
# define CONTACT_HPP

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
	int			PhoneNumber;
	std::string DarkestSecret;
	public:
	std::string	get_FirstName(void);
	std::string	get_LastName(void);
	std::string	get_NickName(void);
	int			get_PhoneNumber(void);
	std::string	get_DarkestSecret(void);
	void		set_FirstName(std::string s);
	void		set_LastName(std::string s);
	void		set_NickName(std::string s);
	void		set_PhoneNumber(int PhoneNumber);
	void		set_DarkestSecret(std::string s);
};

#endif