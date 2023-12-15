/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:59:14 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/15 17:30:11 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include <iostream>
# include "Contact.class.hpp"

class PhoneBook
{
	private:
		Contact			contacts[8];
		unsigned int	index;

	public:
		PhoneBook(void);
		~PhoneBook(void);
		bool	AddContact(void);
		bool	SearchContact(void);
};

#endif
