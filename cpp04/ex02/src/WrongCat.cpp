/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:02:04 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/27 19:42:03 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "WrongCat.hpp"
#include "Colors.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

WrongCat::WrongCat(void): WrongAnimal("WrongCat"), _brain(new Brain())
{
	std::cout << CYAN "WrongCat default constructor called." RESET << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const & src): WrongAnimal(src._type), _brain(NULL)
{
	std::cout << CYAN "WrongCat copy constructor called." RESET << std::endl;
	*this = src;
}

WrongCat::~WrongCat(void)
{
	std::cout << PURPLE "WrongCat destructor called." RESET << std::endl;
	delete this->_brain;
}

/******************************************************************************/
/*								OPERATORS								  	  */
/******************************************************************************/

WrongCat &	WrongCat::operator=(WrongCat const & src)
{
	std::cout << BLUE "WrongCat copy assignment operator called." RESET << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
		if (this->_brain != NULL)
			delete this->_brain;
		this->_brain = new Brain(*src._brain);
	}
	return (*this);
}

/******************************************************************************/
/*								GETTERS										  */
/******************************************************************************/

Brain *	WrongCat::getBrain(void) const
{
	return (this->_brain);
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

void	WrongCat::makeSound(void) const
{
	std::cout << RED << this->_type << BOLD ": * Purr! Purr! *" RESET << std::endl;
}
