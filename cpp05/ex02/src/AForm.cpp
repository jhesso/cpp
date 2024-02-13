/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 22:10:49 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/13 18:19:22 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

AForm::AForm(void)
	:	_name("General Form"),
		_signed(false),
		_signGrade(Bureaucrat::lowestGrade),
		_executeGrade(Bureaucrat::lowestGrade)
{
	std::cout << "Form default constructor called" << std::endl;
}

AForm::AForm(AForm const & src)
	:	_name(src._name), _signed(src._signed), _signGrade(src._signGrade),
		_executeGrade(src._executeGrade)
{
	std::cout << "Form copy constructor called" << std::endl;
}

AForm::AForm(std::string const & name, int const signGrade, int const executeGrade)
	:	_name(name), _signed(false), _signGrade(signGrade),
		_executeGrade(executeGrade)
{
	std::cout << "Form constructor called" << std::endl;
	if (signGrade < Bureaucrat::highestGrade || executeGrade < Bureaucrat::highestGrade)
		throw(AForm::GradeTooHighException());
	else if (signGrade > Bureaucrat::lowestGrade || executeGrade > Bureaucrat::lowestGrade)
		throw(AForm::GradeTooLowException());
}

AForm::~AForm(void)
{
	std::cout << "Form destructor called" << std::endl;
}

/******************************************************************************/
/*								OPERATORS								  	  */
/******************************************************************************/

AForm &	AForm::operator=(AForm const & src)
{
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &src)
		this->_signed = src._signed;
	return (*this);
}

std::ostream &	operator<<(std::ostream & os, AForm const & form)
{
	os << "Form: " << form.getName() << std::endl << "state: "
		<< (form.getSigned() ? "signed" : "unsigned") << std::endl
		<< "Required grade to sign: " << form.getSignGrade() << std::endl
		<< "Required grade to execute: " << form.getExecuteGrade();
	return (os);
}

/******************************************************************************/
/*								GETTERS										  */
/******************************************************************************/

std::string const &	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getSigned(void) const
{
	return (this->_signed);
}

int	AForm::getSignGrade(void) const
{
	return (this->_signGrade);
}

int	AForm::getExecuteGrade(void) const
{
	return (this->_executeGrade);
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

void	AForm::beSigned(Bureaucrat const & b)
{
	if (this->_signed)
		return (throw(AForm::AlreadySignedException()));
	if (this->_signGrade < b.getGrade())
		return (throw(AForm::GradeTooLowException()));
	this->_signed = true;
}

void	AForm::execute(Bureaucrat const & b) const
{
	if (this->_signed == false)
		throw(AForm::NotSignedException());
	if (this->_executeGrade < b.getGrade())
		throw(AForm::GradeTooLowException());
	this->beExecuted();
}

/******************************************************************************/
/*								  EXCEPTIONS								  */
/******************************************************************************/

const char *	AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high for form.");
}

const char *	AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low for form.");
}

const char *	AForm::AlreadySignedException::what(void) const throw()
{
	return ("Form is already signed and thus can't be signed again!");
}

const char *	AForm::NotSignedException::what(void) const throw()
{
	return ("Form has not been signed.");
}
