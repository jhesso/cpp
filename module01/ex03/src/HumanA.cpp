/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:41:07 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/28 12:53:49 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "HumanA.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

HumanA::HumanA(std::string const name, Weapon const &weapon)
				: _name(name), _weapon(weapon)
{
	std::cout << this->_name << " enters the fight!" << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << this->_name << " leaves the fight" << std::endl;
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

void	HumanA::attack(void) const
{
	std::cout	<< this->_name << " attacks with their "
				<< this->_weapon.getType() << std::endl;
}
