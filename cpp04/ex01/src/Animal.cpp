/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:33:37 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/27 18:45:13 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Colors.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Animal::Animal(void): _type("Undefined")
{
	std::cout << CYAN "Animal default constructor called." RESET << std::endl;
}

Animal::Animal(Animal const & src)
{
	std::cout << CYAN "Animal copy constructor called." RESET << std::endl;
	*this = src;
}

Animal::Animal(std::string const & type): _type(type)
{
	std::cout << CYAN "Animal type constructor called." RESET << std::endl;
}

Animal::~Animal(void)
{
	std::cout << PURPLE "Animal destructor called." RESET << std::endl;
}

/******************************************************************************/
/*								OPERATORS								  	  */
/******************************************************************************/

Animal &	Animal::operator=(Animal const & src)
{
	std::cout << BLUE "Animal copy assignment operator called." RESET << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

/******************************************************************************/
/*								GETTERS										  */
/******************************************************************************/

std::string const &	Animal::getType(void) const
{
	return (this->_type);
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

void	Animal::makeSound(void) const
{
	std::cout << this->_type << BOLD ": * Unidentifiable screech *" RESET << std::endl;
}
