/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 21:27:45 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/15 21:04:40 by aechafii         ###   ########.fr       */
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
		int				Index;
		std::string 	FirstName;
		std::string 	LastName;
		std::string 	NickName;
		std::string		PhoneNumber;
		std::string		DarkestSecret;
	public:
		int				get_Index(void);
		std::string		get_FirstName(void);
		std::string		get_LastName(void);
		std::string		get_NickName(void);
		std::string		get_PhoneNumber(void);
		std::string		get_DarkestSecret(void);
		void			set_Index(int index);
		void			set_FirstName(std::string s);
		void			set_LastName(std::string s);
		void			set_NickName(std::string s);
		void			set_PhoneNumber(std::string PhoneNumber);
		void			set_DarkestSecret(std::string s);
};

#endif