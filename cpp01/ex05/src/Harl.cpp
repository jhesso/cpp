/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:44:38 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/29 12:38:17 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include "Harl.hpp"
#include "Colors.hpp"

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
	std::cout	<< BLUE "[DEBUG]: I love having extra bacon for my "
				<< "7XL-double-cheese-triple-pickle-special-ketchup burger. "
				<< "I really do!" RESET << std::endl;
}

void	Harl::_info(void)
{
	std::cout	<< CYAN "[INFO]: I cannot believe adding extra bacon costs more money. "
				<< "You didn't put enough bacon in my burger! "
				<< "If you did, I wouldn't be asking for more!" RESET
				<< std::endl;
}

void	Harl::_warning(void)
{
	std::cout	<< YELLOW "[WARNING]: I think I deserve to have some extra bacon for free. "
				<< "I've been coming for years whereas you started working here "
				<< "since last month." RESET << std::endl;
}

void	Harl::_error(void)
{
	std::cout << RED "[ERROR]: This is unacceptable! I want to speak to the manager now." RESET << std::endl;
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

void	Harl::complain(std::string level)
{
	typedef void (Harl::*fptr)(void);
	std::map<std::string, fptr> functionMap;

	functionMap["DEBUG"] = &Harl::_debug;
	functionMap["INFO"] = &Harl::_info;
	functionMap["WARNING"] = &Harl::_warning;
	functionMap["ERROR"] = &Harl::_error;
	std::map<std::string, fptr>::iterator it = functionMap.find(level);
	if (it != functionMap.end())
		(this->*(it->second))();
	else
		std::cout << "Darn it, Harl did not find a way to complain at this level" << std::endl;
}
