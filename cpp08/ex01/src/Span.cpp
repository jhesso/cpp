/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:14:21 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/15 18:26:52 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <numeric>
#include "Span.hpp"

#define MSG false

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Span::Span(void) : _range(), _maxSize(0)
{
	if (MSG)
		std::cout << "Span default constructor called" << std::endl;
}

Span::Span(Span const & src) : _range(src._range), _maxSize(src._maxSize)
{
	if (MSG)
		std::cout << "Span copy constructor called" << std::endl;
	*this = src;
}

Span::Span(unsigned int N) : _range(), _maxSize(N)
{
	if (MSG)
		std::cout << "Span param constructor called" << std::endl;
}

Span::~Span(void)
{
	if (MSG)
		std::cout << "Span destructor called" << std::endl;
}

/******************************************************************************/
/*								OPERATORS								  	  */
/******************************************************************************/

Span &	Span::operator=(Span const & src)
{
	if (MSG)
		std::cout << "Span copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_maxSize = src._maxSize;
		this->_range.clear();
		this->_range.insert(this->_range.end(), src._range.begin(), src._range.end());
	}
	return (*this);
}

/******************************************************************************/
/*								GETTERS										  */
/******************************************************************************/

std::vector<int> const &	Span::getRange(void) const
{
	return (this->_range);
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

void	Span::addNumber(int num)
{
	if (this->_range.size() == this->_maxSize)
		throw (Span::FullRangeException());
	this->_range.push_back(num);
}

unsigned int	Span::shortestSpan(void) const
{
	int	shortest;

	if (this->_range.size() < 2)
		throw (Span::RangeTooSmallException());
	std::vector<int>	sorted(this->_range);
	std::sort(sorted.begin(), sorted.end());
	shortest = sorted[1] - sorted[0];
	for (unsigned int i = 1; i < sorted.size(); i++)
		if (sorted[i] - sorted[i - 1] < shortest)
			shortest = sorted[i] - sorted[i - 1];
	return shortest;
}

unsigned int	Span::longestSpan(void) const
{
	if (this->_range.size() < 2)
		throw (Span::RangeTooSmallException());
	std::vector<int>	sorted(this->_range);
	std::sort(sorted.begin(), sorted.end());
	return (sorted[sorted.size() - 1] - sorted[0]);
}

/******************************************************************************/
/*								  EXCEPTIONS								  */
/******************************************************************************/

const char *	Span::FullRangeException::what(void) const throw()
{
	return "Too many numbers in range";
}

const char *	Span::RangeTooSmallException::what(void) const throw()
{
	return "Too few elements in range to calculate span";
}
