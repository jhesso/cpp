/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:11:53 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/22 19:32:09 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <climits>
#include "ClapTrap.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

ClapTrap::ClapTrap(void): _name("Default"), _hp(10), _energy(10), _ad(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hp(10), _energy(10), _ad(0)
{
	std::cout << "Constructor called" << std::endl;
	std::cout << "A new ClapTrap called " << name << " appeared" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	std::cout	<< "A duplicate ClapTrap called " << src.getName()
				<< " appeared" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called. Say bye bye to " << this->_name << std::endl;
}

/******************************************************************************/
/*								OPERATORS								  	  */
/******************************************************************************/

ClapTrap &	ClapTrap::operator=(ClapTrap const & src)
{
	std::cout	<< "Copy assignment operator called" << std::endl;
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
/*								GETTERS										  */
/******************************************************************************/

std::string	ClapTrap::getName(void) const
{
	return (this->_name);
}

unsigned int	ClapTrap::getHp(void) const
{
	return (this->_hp);
}

unsigned int	ClapTrap::getEnergy(void) const
{
	return (this->_energy);
}

unsigned int	ClapTrap::getAd(void) const
{
	return (this->_ad);
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

void	ClapTrap::attack(const std::string & target)
{
	if (this->_hp == 0)
	{
		std::cout	<< "ClapTrap " << this->_name << " can't attack: "
					<< "it's completely destroyed" << std::endl;
		return ;
	}
	if (this->_energy == 0)
	{
		std::cout	<< "ClapTrap " << this->_name << " can't attack: "
					<< "no energy left" << std::endl;
		return ;
	}
	if (target == this->_name)
		std::cout	<< "ClapTrap " << this->_name << " attacks " << "itself"
					<< ", causing " << this->_ad << " points of damage!" << std::endl;
	else
		std::cout	<< "ClapTrap " << this->_name << " attacks " << target
					<< ", causing " << this->_ad << " points of damage!" << std::endl;
	this->_energy--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hp == 0)
	{
		std::cout	<< "ClapTrap " << this->_name
					<< " is already completely destroyed!" << std::endl;
		return ;
	}
	std::cout	<< "ClapTrap " << this->_name << " takes " << amount
				<< " points of damage!" << std::endl;
	if (this->_hp <= amount)
	{
		std::cout	<< "ClapTrap " << this->_name << " was completely destroyed"
					<< std::endl;
		this->_hp = 0;
	}
	else
		this->_hp -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hp == 0)
	{
		std::cout	<< "ClapTrap " << this->_name << " can't be repaired: "
					<< "it's completely destroyed" << std::endl;
		return ;
	}
	if (this->_energy == 0)
	{
		std::cout	<< "ClapTrap " << this->_name << " can't be repaired: "
					<< "no energy left" << std::endl;
		return ;
	}
	if (amount == UINT_MAX)
	{
		std::cout	<< "ClapTrap " << this->_name << " can't be repaired for "
					<< amount << " amount of hp and instead gained ";
		amount -= this->_hp;
		std::cout	<< amount << " hp" << std::endl;
		this->_hp += amount;
		this->_energy--;
		return ;
	}
	std::cout	<< "ClapTrap " << this->_name << " was repaired and gained "
				<< amount << "hp" << std::endl;
	this->_hp += amount;
	this->_energy--;
}
