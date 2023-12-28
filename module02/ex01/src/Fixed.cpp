/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:02:05 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/28 13:03:51 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Fixed::Fixed(void): _raw(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(int const raw): _raw(raw << _fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const raw): _raw(roundf(raw * (1 << _fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

/******************************************************************************/
/*								OPERATORS								  	  */
/******************************************************************************/

Fixed &	Fixed::operator=(Fixed const & src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_raw = src.getRawBits();
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& number)
{
	os << number.toFloat();
	return (os);
}

/******************************************************************************/
/*								GETTERS										  */
/******************************************************************************/

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_raw);
}

/******************************************************************************/
/*								SETTERS										  */
/******************************************************************************/

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called." << std::endl;
	this->_raw = raw;
}


/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

int	Fixed::toInt(void) const
{
	return (this->_raw >> Fixed::_fractionalBits);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_raw / (1 << _fractionalBits));
}
