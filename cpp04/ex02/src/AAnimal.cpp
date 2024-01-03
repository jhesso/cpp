/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:33:37 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/27 20:42:00 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.hpp"
#include "Colors.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

AAnimal::AAnimal(void): _type("Undefined")
{
	std::cout << CYAN "Animal default constructor called." RESET << std::endl;
}

AAnimal::AAnimal(AAnimal const & src)
{
	std::cout << CYAN "Animal copy constructor called." RESET << std::endl;
	*this = src;
}

AAnimal::~AAnimal(void)
{
	std::cout << PURPLE "Animal destructor called." RESET << std::endl;
}

/******************************************************************************/
/*								OPERATORS								  	  */
/******************************************************************************/

AAnimal &	AAnimal::operator=(AAnimal const & src)
{
	std::cout << BLUE "Animal copy assignment operator called." RESET << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

// void	AAnimal::makeSound(void) const
// {
// 	std::cout << this->_type << BOLD ": * Unidentifiable screech *" RESET << std::endl;
// }
