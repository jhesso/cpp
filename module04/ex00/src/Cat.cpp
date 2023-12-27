/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:53:16 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/27 18:56:37 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Cat.hpp"
#include "Colors.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Cat::Cat(void): Animal("Cat")
{
	std::cout << CYAN "Cat default constructor called." RESET << std::endl;
	this->_type = "Cat";
}

Cat::Cat(Cat const & src): Animal(src._type)
{
	std::cout << CYAN "Cat copy constructor called." RESET << std::endl;
	*this = src;
}

Cat::~Cat(void)
{
	std::cout << PURPLE "Cat destructor called." RESET << std::endl;
}

/******************************************************************************/
/*								OPERATORS								  	  */
/******************************************************************************/

Cat &	Cat::operator=(Cat const & src)
{
	std::cout << BLUE "Cat copy assignment operator called." RESET << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

void	Cat::makeSound(void) const
{
	std::cout << YELLOW << this->_type << BOLD ": * Meow! Meow! *" RESET << std::endl;
}
