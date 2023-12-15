/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:59:14 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/15 20:12:10 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include <iostream>
# include "Contact.class.hpp"

class PhoneBook
{
	private:
		Contact			Contacts[8];
		unsigned int	Index;
		bool			Abort;

		std::string		GetInput(std::string const prompt);
		void			IncrementIndex(void);
		void			PrintContacts(void);

	public:
		PhoneBook(void);
		~PhoneBook(void);
		bool	AddContact(void);
		bool	SearchContact(void);
};

#endif
