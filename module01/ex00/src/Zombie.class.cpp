/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:44:44 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/18 20:51:02 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.class.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Zombie::Zombie(void)
{
	std::cout << "A wild zombie appeared!" << std::endl;
}

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << "A wild zombie called " << _name << " appeared!" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << _name << ": is dead" << std::endl;
}

/******************************************************************************/
/*								GETTERS										  */
/******************************************************************************/

std::string	Zombie::_getName(void)
{
	return (this->_name);
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

void	Zombie::announce(void)
{
	std::cout	<< this->_getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
