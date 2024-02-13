/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 23:24:45 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/13 18:12:37 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "RobotomyRequestForm.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

RobotomyRequestForm::RobotomyRequestForm(void)
	:	AForm("Robotomy Request Form", RobotomyRequestForm::gradeToSign,
			RobotomyRequestForm::gradeToExecute),
		_target("Unknown")
{
	srand(time(NULL));
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src)
	:	AForm(src),
		_target(src._target)
{
	srand(time(NULL));
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target)
	:	AForm("Robotomy Request Form", RobotomyRequestForm::gradeToSign,
			RobotomyRequestForm::gradeToExecute),
		_target(target)
{
	srand(time(NULL));
	std::cout << "RobotomyRequestForm attribute constructor called." << std::endl;
	if (_target.empty())
		_target = "Unknown";
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

/******************************************************************************/
/*								OPERATORS								  	  */
/******************************************************************************/

RobotomyRequestForm &	RobotomyRequestForm::operator=(RobotomyRequestForm const & src)
{
	std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	if (this != &src)
		this->_target = src._target;
	return (*this);
}

/******************************************************************************/
/*								GETTERS										  */
/******************************************************************************/

std::string const &	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

void	RobotomyRequestForm::beExecuted(void) const
{
	std::cout << "* drilling noices... *" << std::endl;
	if (std::rand() % 2)
		std::cout << this->_target << " successfully robotomized!" << std::endl;
	else
		std::cout << "Damn it! Failed to robotomize " << this->_target << std::endl;
}
