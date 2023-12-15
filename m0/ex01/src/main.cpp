/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:03:07 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/15 20:17:14 by jhesso           ###   ########.fr       */
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

	while (1)
	{
		cmd = GetCommand();
		std::cout << "cmd: " << cmd << std::endl;
		if (cmd == "ADD")
		{
			std::cout << "adding new contact..." << std::endl;
			if (!PhoneBook.AddContact())
				break;
		}
		else if (cmd == "SEARCH")
		{
			std::cout << "searching from contacts..." << std::endl;
			if (!PhoneBook.SearchContact())
				break;
		}
		else if (cmd == "EXIT")
			break;
	}
	return (0);
}
