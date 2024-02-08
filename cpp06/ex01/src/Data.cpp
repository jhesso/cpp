/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:17:12 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/08 20:25:00 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"

#define MSG false

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Serializer::Serializer(void)
{
	if (MSG)
		std::cout << "Serializer default constructor called" << std::endl;
}

Serializer::Serializer(Serializer const & src)
{
	if (MSG)
		std::cout << "Serializer copy constructor called" << std::endl;
	*this = src;
}

Serializer::~Serializer(void)
{
	if (MSG)
		std::cout << "Serializer destructor called" << std::endl;
}

/******************************************************************************/
/*								OPERATORS								  	  */
/******************************************************************************/

Serializer &	Serializer::operator=(Serializer const & src)
{
	if (MSG)
		std::cout << "Serializer copy assignment operator called" << std::endl;
	(void)src;
	return (*this);
}

std::ostream &	operator<<(std::ostream & os, const Data & obj)
{
	os << "Data structure address: " << &obj << std::endl
		<< "\tvalue: " << obj.val << std::endl
		<< "\tstring: " << obj.string << std::endl;
	return (os);
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

uintptr_t	Serializer::serialize(Data * ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

