/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:26:39 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/20 14:32:37 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.class.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Weapon::Weapon(std::string const type): _type(type)
{
	std::cout	<< "A new \"" << type << "\" was forged" << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout	<< "the weapon \""<< this->_type
				<< "\" was destroyed in the battle" << std::endl;
}

/******************************************************************************/
/*								GETTERS										  */
/******************************************************************************/

std::string const	&Weapon::getType(void) const
{
	return (this->_type);
}

/******************************************************************************/
/*								SETTERS										  */
/******************************************************************************/

void	Weapon::setType(std::string const type)
{
	this->_type = type;
}
