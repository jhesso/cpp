/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:00:03 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/15 17:23:53 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(void)
{
	std::cout << "Contact constructor called" << std::endl;
}

Contact::~Contact(void)
{
	std::cout << "Contact deconstructor called" << std::endl;
}

void	Contact::SetFirstName(std::string FirstName)
{
	FirstName[0] = std::toupper(FirstName[0]);
	for (int i = 1; FirstName[i]; i++)
		FirstName[i] = std::tolower(FirstName[i]);
	this->FirstName = FirstName;
}

void	Contact::SetLastName(std::string LastName)
{
	LastName[0] = std::toupper(LastName[0]);
	for (int i = 1; LastName[i]; i++)
		LastName[i] = std::tolower(LastName[i]);
	this->LastName = LastName;
}

void	Contact::SetNickname(std::string Nickname)
{
	Nickname[0] = std::toupper(Nickname[0]);
	for (int i = 1; Nickname[i]; i++)
		Nickname[i] = std::tolower(Nickname[i]);
	this->Nickname = Nickname;
}

/*
*	Maybe should add some error checking here unless its done when actually
*	getting the input (phone number should only contain digits and maybe + first)
*/
void	Contact::SetNumber(std::string Number)
{
	this->Number = Number;
}

void	Contact::SetSecret(std::string Secret)
{
	this->Secret = Secret;
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
