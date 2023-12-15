/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:03:07 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/15 21:33:25 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

/*
*	GetCommand()
*	Get command from user
*	Trim any leading or trailing whitespaces
*/
std::string	GetCommand(void)
{
	std::string	cmd;
	size_t		start;
	size_t		end;

	std::cout << "Phonebook > ";
	std::getline(std::cin, cmd);
	if (std::cin.eof())
		return ("EXIT");
	start = cmd.find_first_not_of(" \t\n\r\v\f");
	end = cmd.find_last_not_of(" \t\n\r\v\f");
	if (start == end)
		return(cmd);
	return (cmd.substr(start, end - start + 1));
}

int	main(void)
{
	PhoneBook	PhoneBook;
	std::string	cmd;

	std::cout	<< std::endl
				<< "Welcome to the awesome phonebook written(some time after 1985) by: jhesso!"
				<< std::endl;
	while (1)
	{
		cmd = GetCommand();
		if (cmd == "ADD")
		{
			if (!PhoneBook.AddContact())
				break;
		}
		else if (cmd == "SEARCH")
		{
			if (!PhoneBook.SearchContact())
				break;
		}
		else if (cmd == "EXIT")
			break;
		else
		{
			std::cout	<< "Please enter one of the following commands: " << std::endl
						<< "\tADD: add a new contact" << std::endl
						<< "\tSEARCH: search the contact list" << std::endl
						<< "\tEXIT: exit the awesome phonebook" << std::endl;
		}
	}
	std::cout << "Thank you for using the awesome phonebook!" << std::endl;
	return (0);
}
