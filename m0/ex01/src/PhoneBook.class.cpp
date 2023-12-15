/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:00:06 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/15 20:20:51 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

/******************************************************************************/
/*						CONSTRUCTOR & DESTRUCTOR							  */
/******************************************************************************/

PhoneBook::PhoneBook(void)
{
	this->Index = 0;
	this->Abort = false;
	std::cout << "PhoneBook constructor called" << std::endl
	<< "index set to: " << this->Index << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook deconstructor called" << std::endl;
}

/******************************************************************************/
/*							PRIVATE FUNCTIONS								  */
/******************************************************************************/

/*
*	GetInput()
*	Prompt user for input.
*	Return:
*		String containing user input, trimmed of any leading
*			and trailing whitespaces.
*		An empty string if input is empty or EOF and sets the Abort flag
*/
std::string	PhoneBook::GetInput(std::string const prompt)
{
	std::string	input;
	size_t	start;
	size_t	end;

	std::cout << "Please enter " << prompt << ": ";
	std::getline(std::cin, input);
	if (std::cin.eof())
	{
		Abort = true;
		std::cout << std::endl;
		return (std::string());
	}
	start = input.find_first_not_of(" \t\n\r\v\f");
	end = input.find_last_not_of(" \t\n\r\v\f");
	if (start == end)
		return(input);
	return (input.substr(start, end - start + 1));
}

void	PhoneBook::IncrementIndex(void)
{
	Index++;
	if (Index > 7)
		Index = 0;
}

void	PhoneBook::PrintContacts(void)
{
	for (int i = 0; i <= 7; i++)
	{
		std::cout << "index: " << i << std::endl << "First name: "
		<< this->Contacts[i].GetFirstName() << std::endl;
	}
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

bool	PhoneBook::AddContact(void)
{
	std::string	input;

	while (!Abort)
	{
		input = GetInput("first name");
		std::cout << "input read successfully" << std::endl;
		if (Abort || this->Contacts[Index].SetFirstName(input))
			break;
	}
	while (!Abort)
	{
		input = GetInput("last name");
		if (Abort || this->Contacts[Index].SetLastName(input))
			break;
	}
	while (!Abort)
	{
		input = GetInput("nickname");
		if (Abort || this->Contacts[Index].SetNickname(input))
			break;
	}
	while (!Abort)
	{
		input = GetInput("phone number");
		if (Abort || this->Contacts[Index].SetNumber(input))
			break;
	}
	while (!Abort)
	{
		input = GetInput("deepest darkest secret");
		if (Abort || this->Contacts[Index].SetSecret(input))
			break;
	}
	if (Abort)
	{
		Abort = false;
		return (false);
	}
	std::cout << "Contact saved successfully!" << std::endl;
	IncrementIndex();
	PrintContacts();
	return (true);
}

bool	PhoneBook::SearchContact(void)
{
	std::cout << "searching contacts..." << std::endl;
	return (true);
}
