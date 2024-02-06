/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:35:45 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/06 15:19:06 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "bureaucrat.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Bureaucrat::Bureaucrat(void): _name("Default"), _grade(150)
{
	std::cout << "bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
	std::cout << "bureaucrat copy constructor called" << std::endl;
	*this = src;
}

//TODO: this needs exception handling
Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "bureaucrat destructor called" << std::endl;
}

/******************************************************************************/
/*								OPERATORS								  	  */
/******************************************************************************/

Bureaucrat &	Bureaucrat::operator=(Bureaucrat const & src)
{
	std::cout << "bureaucrat copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		this->_grade = src._grade;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return os;
}

/******************************************************************************/
/*								SETTERS										  */
/******************************************************************************/

void	Bureaucrat::setName(const std::string name)
{
	this->_name = name;
}

//TODO: maybe add exception handling here too
void	Bureaucrat::setGrade(const int grade)
{
	this->_grade = grade;
}

/******************************************************************************/
/*								GETTERS										  */
/******************************************************************************/

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

/******************************************************************************/
/*							PRIVATE FUNCTIONS								  */
/******************************************************************************/

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

//TODO: these need exception handling
void	Bureaucrat::incGrade(void)
{
	this->_grade++;
}

void	Bureaucrat::decGrade(void)
{
	this->_grade--;
}
