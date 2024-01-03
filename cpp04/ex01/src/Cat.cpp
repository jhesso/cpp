/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:53:16 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/27 19:40:22 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Cat.hpp"
#include "Colors.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Cat::Cat(void): Animal("Cat"), _brain(new Brain())
{
	std::cout << CYAN "Cat default constructor called." RESET << std::endl;
	this->_type = "Cat";
}

Cat::Cat(Cat const & src): Animal(src._type), _brain(NULL)
{
	std::cout << CYAN "Cat copy constructor called." RESET << std::endl;
	*this = src;
}

Cat::~Cat(void)
{
	std::cout << PURPLE "Cat destructor called." RESET << std::endl;
	delete this->_brain;
}

/******************************************************************************/
/*								OPERATORS								  	  */
/******************************************************************************/

Cat &	Cat::operator=(Cat const & src)
{
	std::cout << BLUE "Cat copy assignment operator called." RESET << std::endl;
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

Brain *	Cat::getBrain(void) const
{
	return (this->_brain);
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

void	Cat::makeSound(void) const
{
	std::cout << YELLOW << this->_type << BOLD ": * Meow! Meow! *" RESET << std::endl;
}
