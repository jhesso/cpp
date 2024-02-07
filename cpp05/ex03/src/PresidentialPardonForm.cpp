/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 23:49:41 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/07 23:57:45 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PresidentialPardonForm.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

PresidentialPardonForm::PresidentialPardonForm(void)
	:	AForm("Presidential Pardon Form", PresidentialPardonForm::gradeToSign,
			PresidentialPardonForm::gradeToExecute),
		_target("Unknown")
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src)
	:	AForm(src),
		_target(src._target)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target)
	:	AForm("Presidential Pardon Form", PresidentialPardonForm::gradeToSign,
			PresidentialPardonForm::gradeToExecute),
		_target(target)
{
	std::cout << "PresidentialPardonForm attribute constructor called" << std::endl;
	if (_target.empty())
		_target = "Unknown";
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

/******************************************************************************/
/*								OPERATORS								  	  */
/******************************************************************************/

PresidentialPardonForm &	PresidentialPardonForm::operator=(PresidentialPardonForm const & src)
{
	std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
	if (this != &src)
		this->_target = src._target;
	return (*this);
}

/******************************************************************************/
/*								GETTERS										  */
/******************************************************************************/

std::string const &	PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

void	PresidentialPardonForm::beExecuted(void) const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
