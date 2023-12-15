/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:59:26 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/15 17:12:19 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <iostream>

class Contact
{
	private:
		std::string	FirstName;
		std::string	LastName;
		std::string	Nickname;
		std::string	Number;
		std::string Secret;

	public:
		Contact(void);
		~Contact(void);
		void		SetFirstName(std::string FirstName);
		void		SetLastName(std::string LastName);
		void		SetNickname(std::string Nickname);
		void		SetNumber(std::string Number);
		void		SetSecret(std::string Secret);
		std::string GetFirstName(void);
		std::string	GetLastName(void);
		std::string	GetNickname(void);
		std::string	GetNumber(void);
		std::string GetSecret(void);
};

#endif
