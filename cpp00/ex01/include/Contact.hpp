/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:59:26 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/28 16:42:15 by jhesso           ###   ########.fr       */
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
		bool		isEmpty(void);
		bool		PrintContactInfo(void);
		bool		forbiddenChar(std::string str);

		bool		SetFirstName(std::string FirstName);
		bool		SetLastName(std::string LastName);
		bool		SetNickname(std::string Nickname);
		bool		SetNumber(std::string Number);
		bool		SetSecret(std::string Secret);

		std::string GetFirstName(void);
		std::string	GetLastName(void);
		std::string	GetNickname(void);
		std::string	GetNumber(void);
		std::string GetSecret(void);
};

#endif
