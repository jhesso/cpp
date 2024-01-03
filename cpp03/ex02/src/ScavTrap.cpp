/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:25:45 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/27 17:01:13 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ScavTrap.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

ScavTrap::ScavTrap(void): ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->_name = "default";
	this->_hp = SCAVTRAP_DEFAULT_HP;
	this->_energy = SCAVTRAP_DEFAULT_ENERGY;
	this->_ad = SCAVTRAP_DEFAULT_AD;
}

ScavTrap::ScavTrap(std::string & name): ClapTrap(name)
{
	std::cout << "A new ScavTrap called " << name << " appeared" << std::endl;
	this->_hp = SCAVTRAP_DEFAULT_HP;
	this->_energy = SCAVTRAP_DEFAULT_ENERGY;
	this->_ad = SCAVTRAP_DEFAULT_AD;
}

ScavTrap::ScavTrap(ScavTrap const & src): ClapTrap()
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	std::cout	<< "A duplicate ScavTrap called " << src.getName()
				<< " appeared" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called. Say bye bye to " << this->_name << std::endl;
}

/******************************************************************************/
/*								OPERATORS								  	  */
/******************************************************************************/

ScavTrap &	ScavTrap::operator=(ScavTrap const & src)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_name = src.getName();
		this->_hp = src.getHp();
		this->_energy = src.getEnergy();
		this->_ad = src.getAd();
	}
	return (*this);
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

void	ScavTrap::attack(std::string const & target)
{
	if (this->_hp == 0)
	{
		std::cout	<< "ScavTrap " << this->_name << " can't attack: "
					<< "it's completely destroyed" << std::endl;
		return ;
	}
	if (this->_energy == 0)
	{
		std::cout	<< "ScavTrap " << this->_name << " can't attack: "
					<< "no energy left" << std::endl;
		return ;
	}
	if (target == this->_name)
		std::cout	<< "ScavTrap " << this->_name << " attacks " << "itself"
					<< ", causing " << this->_ad << " points of damage!" << std::endl;
	else
		std::cout	<< "ScavTrap " << this->_name << " attacks " << target
					<< ", causing " << this->_ad << " points of damage!" << std::endl;
	this->_energy--;
}

void	ScavTrap::guardGate(void)
{
	if (this->_hp == 0)
	{
		std::cout	<< "Nice try but ScavTrap " << this->_name
					<< " can't guard the gate as it is completely destroyed" << std::endl;
		return ;
	}
	if (this->_energy == 0)
	{
		std::cout	<< "Nice try but ScavTrap " << this->_name
					<< " can't guard the gate as its battery is completely drained" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " Guards the gate" << std::endl;
}
