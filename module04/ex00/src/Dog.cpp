/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:45:37 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/27 18:55:33 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Dog.hpp"
#include "Colors.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Dog::Dog(void): Animal("Dog")
{
	std::cout << CYAN "Dog default constructor called." RESET << std::endl;
	this->_type = "Dog";
}

Dog::Dog(Dog const & src): Animal(src._type)
{
	std::cout << CYAN "Dog copy constructor called." RESET << std::endl;
	*this = src;
}

Dog::~Dog(void)
{
	std::cout << PURPLE "Dog destructor called." RESET << std::endl;
}

/******************************************************************************/
/*								OPERATORS								  	  */
/******************************************************************************/

Dog &	Dog::operator=(Dog const & src)
{
	std::cout << BLUE "Dog copy assignment operator called." RESET << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

void	Dog::makeSound(void) const
{
	std::cout << GREEN << this->_type << BOLD ": * Woof! Woof! *" RESET << std::endl;
}
