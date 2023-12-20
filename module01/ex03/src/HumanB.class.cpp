/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:14:34 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/20 14:28:01 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "HumanB.class.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

HumanB::HumanB(std::string const name) : _name(name), _weapon(NULL)
{
	std::cout << this->_name << " enters the fight!" << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << this->_name << " leaves the fight" << std::endl;
}

/******************************************************************************/
/*								SETTERS										  */
/******************************************************************************/

void	HumanB::setWeapon(Weapon &weapon)
{
	if (weapon.getType().empty())
		this->_weapon = NULL;
	else
		this->_weapon = &weapon;
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

void	HumanB::attack(void) const
{
	std::cout	<< this->_name << " attacks with their ";
	if (this->_weapon == NULL)
		std::cout << "bare hands";
	else
		std::cout << this->_weapon->getType();
	std::cout << std::endl;
}
