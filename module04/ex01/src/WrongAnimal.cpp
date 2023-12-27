/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:57:33 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/27 19:01:29 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"
#include "Colors.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

WrongAnimal::WrongAnimal(void): _type("Undefined")
{
	std::cout << CYAN "WrongAnimal default constructor called." RESET << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src)
{
	std::cout << CYAN "WrongAnimal copy constructor called." RESET << std::endl;
	*this = src;
}

WrongAnimal::WrongAnimal(std::string const & type): _type(type)
{
	std::cout << CYAN "WrongAnimal type constructor called." RESET << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << PURPLE "WrongAnimal destructor called." RESET << std::endl;
}

/******************************************************************************/
/*								OPERATORS								  	  */
/******************************************************************************/

WrongAnimal &	WrongAnimal::operator=(WrongAnimal const & src)
{
	std::cout << BLUE "WrongAnimal copy assignment operator called." RESET << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

/******************************************************************************/
/*								GETTERS										  */
/******************************************************************************/

std::string const &	WrongAnimal::getType(void) const
{
	return (this->_type);
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

void	WrongAnimal::makeSound(void) const
{
	std::cout << RED << this->_type << BOLD ": * Unidentifiable screech *" RESET << std::endl;
}
