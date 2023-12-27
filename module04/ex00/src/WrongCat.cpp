/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:02:04 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/27 19:03:35 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "WrongCat.hpp"
#include "Colors.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

WrongCat::WrongCat(void): WrongAnimal("WrongCat")
{
	std::cout << CYAN "WrongCat default constructor called." RESET << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const & src): WrongAnimal(src._type)
{
	std::cout << CYAN "WrongCat copy constructor called." RESET << std::endl;
	*this = src;
}

WrongCat::~WrongCat(void)
{
	std::cout << PURPLE "WrongCat destructor called." RESET << std::endl;
}

/******************************************************************************/
/*								OPERATORS								  	  */
/******************************************************************************/

WrongCat &	WrongCat::operator=(WrongCat const & src)
{
	std::cout << BLUE "WrongCat copy assignment operator called." RESET << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

void	WrongCat::makeSound(void) const
{
	std::cout << RED << this->_type << BOLD ": * Purr! Purr! *" RESET << std::endl;
}
