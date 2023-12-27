/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:45:37 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/27 19:40:14 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Dog.hpp"
#include "Colors.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Dog::Dog(void): Animal("Dog"), _brain(new Brain())
{
	std::cout << CYAN "Dog default constructor called." RESET << std::endl;
	this->_type = "Dog";
}

Dog::Dog(Dog const & src): Animal(src._type), _brain(NULL)
{
	std::cout << CYAN "Dog copy constructor called." RESET << std::endl;
	*this = src;
}

Dog::~Dog(void)
{
	std::cout << PURPLE "Dog destructor called." RESET << std::endl;
	delete this->_brain;
}

/******************************************************************************/
/*								OPERATORS								  	  */
/******************************************************************************/

Dog &	Dog::operator=(Dog const & src)
{
	std::cout << BLUE "Dog copy assignment operator called." RESET << std::endl;
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

Brain *	Dog::getBrain(void) const
{
	return (this->_brain);
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

void	Dog::makeSound(void) const
{
	std::cout << GREEN << this->_type << BOLD ": * Woof! Woof! *" RESET << std::endl;
}
