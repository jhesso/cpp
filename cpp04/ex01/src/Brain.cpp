/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:18:36 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/30 15:20:27 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"
#include "Colors.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Brain::Brain(void)
{
	std::cout << CYAN "Brain default constructor called." RESET << std::endl;
}

Brain::Brain(Brain const & src)
{
	std::cout << CYAN "Brain copy constructor called." RESET << std::endl;
	*this = src;
}

Brain::~Brain(void)
{
	std::cout << PURPLE "Brain destructor called." RESET << std::endl;
}

/******************************************************************************/
/*								OPERATORS								  	  */
/******************************************************************************/

Brain &	Brain::operator=(Brain const & src)
{
	std::cout << CYAN "Brain copy assignment operator called." RESET << std::endl;
	for (int i = 0; i < this->nbIdeas; i++)
		this->_ideas[i] = src._ideas[i];
	return (*this);
}

/******************************************************************************/
/*								GETTERS										  */
/******************************************************************************/

std::string const &	Brain::getIdea(int index) const
{
	if (index < 0)
		index = 0;
	if (index > this->nbIdeas)
		index = this->nbIdeas;
	return (this->_ideas[index]);
}

/******************************************************************************/
/*								SETTERS										  */
/******************************************************************************/

void	Brain::setIdea(int index, std::string const & idea)
{
	if (index < 0)
		index = 0;
	if (index > this->nbIdeas)
		index = this->nbIdeas;
	this->_ideas[index] = idea;
}
