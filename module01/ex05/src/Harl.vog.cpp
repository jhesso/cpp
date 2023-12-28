/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.vog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:44:38 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/28 13:00:31 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include "Harl.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Harl::Harl(void)
{
	std::cout << "Harl is ready to complain!" << std::endl;
}

Harl::~Harl(void)
{
	std::cout << "Harl has complained enough, Ciao!" << std::endl;
}

/******************************************************************************/
/*							PRIVATE FUNCTIONS								  */
/******************************************************************************/

void	Harl::_debug(void)
{
	std::cout	<< "I love having extra bacon for my "
				<< "7XL-double-cheese-triple-pickle-special-ketchup burger. "
				<< "I really do!" << std::endl;
}

void	Harl::_info(void)
{
	std::cout	<< "I cannot believe adding extra bacon costs more money. "
				<< "You didn't put enough bacon in my burger! "
				<< "If you did, I wouldn't be asking for more!"
				<< std::endl;
}

void	Harl::_warning(void)
{
	std::cout	<< "I think I deserve to have some extra bacon for free. "
				<< "I've been coming for years whereas you started working here "
				<< "since last month." << std::endl;
}

void	Harl::_error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

void	Harl::complain(std::string level)
{
	typedef void (Harl::*fptr)(void);

	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	fptr		pointers[4] = {&Harl::_debug, &Harl::_info,
								&Harl::_warning, &Harl::_error};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*pointers[i])();
			return ;
		}
	}
	std::cout << "Darn it, Harl did not find a way to complain at this level" << std::endl;
}
