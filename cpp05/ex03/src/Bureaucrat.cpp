/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:35:45 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/13 18:25:52 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Bureaucrat::Bureaucrat(void): _name("Default"), _grade(Bureaucrat::lowestGrade)
{
	std::cout << "bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
	std::cout << "bureaucrat copy constructor called" << std::endl;
	*this = src;
}

Bureaucrat::Bureaucrat(std::string const & name, int grade)
: _name(name), _grade(Bureaucrat::lowestGrade)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	if (grade < Bureaucrat::highestGrade)
		throw(Bureaucrat::GradeTooHighException());
	else if (grade > Bureaucrat::lowestGrade)
		throw(Bureaucrat::GradeTooLowException());
	else
		this->_grade = grade;
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
		this->_grade = src._grade;
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}

/******************************************************************************/
/*								SETTERS										  */
/******************************************************************************/

void	Bureaucrat::setGrade(const int grade)
{
	if (grade < Bureaucrat::highestGrade)
		throw(Bureaucrat::GradeTooHighException());
	else if (grade > Bureaucrat::lowestGrade)
		throw(Bureaucrat::GradeTooLowException());
	else
	this->_grade = grade;
}

/******************************************************************************/
/*								GETTERS										  */
/******************************************************************************/

std::string const &	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

void	Bureaucrat::incGrade(void)
{
	if (this->_grade - 1 < Bureaucrat::highestGrade)
		return (throw(Bureaucrat::GradeTooHighException()));
	else
	{
		this->_grade--;
		std::cout << this->_name << " was promoted to grade: " << this->_grade << std::endl;
	}
}

void	Bureaucrat::incGrade(int grade)
{
	if (this->_grade - grade < Bureaucrat::highestGrade)
		return (throw(Bureaucrat::GradeTooHighException()));
	else
	{
		this->_grade -= grade;
		std::cout << this->_name << " was promoted to grade: " << this->_grade << std::endl;
	}
}

void	Bureaucrat::decGrade(void)
{
	if (this->_grade + 1 > Bureaucrat::lowestGrade)
		return (throw(Bureaucrat::GradeTooLowException()));
	else
	{
		this->_grade++;
		std::cout << this->_name << " was demoted to grade: " << this->_grade << std::endl;
	}
}

void	Bureaucrat::decGrade(int grade)
{
	if (this->_grade + grade > Bureaucrat::lowestGrade)
		return (throw(Bureaucrat::GradeTooLowException()));
	else
	{
		this->_grade += grade;
		std::cout << this->_name << " was demoted to grade: " << this->_grade << std::endl;
	}
}

void	Bureaucrat::signForm(AForm & form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << *this << " signed " << form << std::endl;
	}
	catch(std::exception const & e)
	{
		std::cerr << *this << " couldn't sign " << form << " because "
					<< e.what() << std::endl;
	}

}

void	Bureaucrat::executeForm(AForm & form) const
{
	try
	{
		form.execute(*this);
		std::cout << *this << " executed " << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: Couldn't execute " << form << std::endl << "because "
					<< e.what() << std::endl;
	}

}

/******************************************************************************/
/*								  EXCEPTIONS								  */
/******************************************************************************/

const char *	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Bureaucrat cannot rank this high without transforming to a supreme being and we dont want that!");
}

const char *	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Bureaucrat cannot rank this low, please fire them first!");
}
