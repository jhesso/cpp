/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:00:06 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/28 16:26:16 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/******************************************************************************/
/*						CONSTRUCTOR & DESTRUCTOR							  */
/******************************************************************************/

PhoneBook::PhoneBook(void)
{
	this->Index = 0;
	this->Abort = false;
}

PhoneBook::~PhoneBook(void)
{}

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

void	PhoneBook::PrintContactTable(void)
{
	std::cout	<< "+----------+----------+----------+----------+" << std::endl
				<< "|   INDEX  |FIRST NAME| LAST NAME| NICKNAME |" << std::endl
				<< "+----------+----------+----------+----------+" << std::endl;
	for (int i = 0; i < 8; i++)
		PrintContactInfoToTable(i);
	std::cout << std::endl;
}

void	PhoneBook::PrintContactInfoToTable(int i)
{
	if (this->Contacts[i].isEmpty())
		return;
	std::cout << "|" << std::setw(10) << i << "|";
	PrintTableString(this->Contacts[i].GetFirstName());
	PrintTableString(this->Contacts[i].GetLastName());
	PrintTableString(this->Contacts[i].GetNickname());
	std::cout	<< std::endl
				<< "+----------+----------+----------+----------+" << std::endl;
}

void	PhoneBook::PrintTableString(std::string str)
{
	if (str.length() > 10)
	{
		str.resize(9);
		str += ".";
	}
	std::cout << std::setw(10) << str << "|";
}

bool	PhoneBook::PrintContactByIndex(std::string str)
{
	int	index = 0;

	if (str.length() == 1 && std::isdigit(str[0]))
	{
		index = str[0] - '0';
		if (index >= 0 && index < 8)
		{
			if (this->Contacts[index].PrintContactInfo())
				return (true);
			else
			{
				std::cout << "Error: No record at specified index." << std::endl;
				return (false);
			}
		}
	}
	std::cout << "Error: \'" << str << "\' is not a valid index." << std::endl;
	return (false);
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

bool	PhoneBook::AddContact(void)
{
	std::string	input;

	std::cout << std::endl << "+------------ New Contact Menu -------------+" << std::endl << std::endl;
	while (!Abort)
	{
		input = GetInput("first name");
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
	return (true);
}

bool	PhoneBook::SearchContact(void)
{
	std::string	input;

	std::cout << std::endl << "+-------------- Search Menu ----------------+" << std::endl << std::endl;
	std::cout << "searching contacts..." << std::endl;
	this->PrintContactTable();
	input = GetInput("index of contact to display");
	if (input.empty())
		return (false);
	this->PrintContactByIndex(input);
	return (true);
}
