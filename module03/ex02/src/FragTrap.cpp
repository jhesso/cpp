/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:20:00 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/27 17:33:54 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

FragTrap::FragTrap(void): ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->_name = "default";
	this->_hp = FRAGTRAP_DEFAULT_HP;
	this->_energy = FRAGTRAP_DEFAULT_ENERGY;
	this->_ad = FRAGTRAP_DEFAULT_AD;
}

FragTrap::FragTrap(std::string & name): ClapTrap(name)
{
	std::cout << "A new FragTrap called " << name << " appeared" << std::endl;
	this->_hp = FRAGTRAP_DEFAULT_HP;
	this->_energy = FRAGTRAP_DEFAULT_ENERGY;
	this->_ad = FRAGTRAP_DEFAULT_AD;
}

FragTrap::FragTrap(FragTrap const & src): ClapTrap()
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	std::cout	<< "A duplicate FragTrap called " << src.getName()
				<< " appeared" << std::endl;
	*this = src;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called. Say bye bye to " << this->_name << std::endl;
}

/******************************************************************************/
/*								OPERATORS								  	  */
/******************************************************************************/

FragTrap &	FragTrap::operator=(FragTrap const & src)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
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

void	FragTrap::highFivesGuys(void)
{
	if (this->_hp == 0)
	{
		std::cout	<< "FragTrap " << this->_name << " might be a smoking pile of"
					<< " debris, but it's spirit is still high! It extends it's"
					<< " battle scarred hand looking for a high-five" << std::endl;
	}
	else
	{
		std::cout	<< "FragTrap " << this->_name << " raises it's hand"
					<< " desperately looking for a high-five" << std::endl;
	}
}
