/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:00:03 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/15 20:26:47 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

/******************************************************************************/
/*						CONSTRUCTOR & DESTRUCTOR							  */
/******************************************************************************/

Contact::Contact(void)
{
	std::cout << "Contact constructor called" << std::endl;
}

Contact::~Contact(void)
{
	std::cout << "Contact deconstructor called" << std::endl;
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

bool	Contact::SetFirstName(std::string FirstName)
{
	if (FirstName.length() == 0)
	{
		std::cout << "Field cannot be empty!" << std::endl;
		return (false);
	}
	FirstName[0] = std::toupper(FirstName[0]);
	for (int i = 1; FirstName[i]; i++)
		FirstName[i] = std::tolower(FirstName[i]);
	this->FirstName = FirstName;
	return (true);
}

bool	Contact::SetLastName(std::string LastName)
{
	if (LastName.length() == 0)
	{
		std::cout << "Field cannot be empty!" << std::endl;
		return (false);
	}
	LastName[0] = std::toupper(LastName[0]);
	for (int i = 1; LastName[i]; i++)
		LastName[i] = std::tolower(LastName[i]);
	this->LastName = LastName;
	return (true);
}

bool	Contact::SetNickname(std::string Nickname)
{
	if (Nickname.length() == 0)
	{
		std::cout << "Field cannot be empty!" << std::endl;
		return (false);
	}
	Nickname[0] = std::toupper(Nickname[0]);
	for (int i = 1; Nickname[i]; i++)
		Nickname[i] = std::tolower(Nickname[i]);
	this->Nickname = Nickname;
	return (true);
}

/*
*	Maybe should add some error checking here unless its done when actually
*	getting the input (phone number should only contain digits and maybe + first)
*/
bool	Contact::SetNumber(std::string Number)
{
	if (Number.length() == 0)
	{
		std::cout << "Field cannot be empty!" << std::endl;
		return (false);
	}
	this->Number = Number;
	return (true);
}

bool	Contact::SetSecret(std::string Secret)
{
	if (Secret.length() == 0)
	{
		std::cout << "Field cannot be empty!" << std::endl;
		return (false);
	}
	this->Secret = Secret;
	return (true);
}

std::string	Contact::GetFirstName(void)
{
	return (this->FirstName);
}

std::string	Contact::GetLastName(void)
{
	return (this->LastName);
}

std::string	Contact::GetNickname(void)
{
	return (this->Nickname);
}

std::string	Contact::GetNumber(void)
{
	return (this->Number);
}

std::string	Contact::GetSecret(void)
{
	return (this->Secret);
}
