/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 22:10:49 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/07 22:47:40 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Form::Form(void)
	: _name("General Form"),
	_signGrade(Bureaucrat::lowestGrade),
	_executeGrade(Bureaucrat::lowestGrade)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(Form const & src)
	: _name(src._name), _signGrade(src._signGrade), _executeGrade(src._executeGrade)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form::Form(std::string const & name, int const signGrade, int const executeGrade)
	: _name(name), _signGrade(signGrade), _executeGrade(executeGrade)
{
	std::cout << "Form constructor called" << std::endl;
	if (signGrade < Bureaucrat::highestGrade || executeGrade < Bureaucrat::highestGrade)
		throw(Form::GradeTooHighException());
	else if (signGrade > Bureaucrat::lowestGrade || executeGrade > Bureaucrat::lowestGrade)
		throw(Form::GradeTooLowException());
}

Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
}

/******************************************************************************/
/*								OPERATORS								  	  */
/******************************************************************************/

Form &	Form::operator=(Form const & src)
{
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &src)
		this->_signed = src._signed;
	return (*this);
}

std::ostream &	operator<<(std::ostream & os, Form const & form)
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

std::string const &	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getSigned(void) const
{
	return (this->_signed);
}

int	Form::getSignGrade(void) const
{
	return (this->_signGrade);
}

int	Form::getExecuteGrade(void) const
{
	return (this->_executeGrade);
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

void	Form::beSigned(Bureaucrat const & b)
{
	if (this->_signed)
		return (throw(Form::AlreadySignedException()));
	if (this->_signGrade < b.getGrade())
		return (throw(Form::GradeTooLowException()));
	this->_signed = true;
}

/******************************************************************************/
/*								  EXCEPTIONS								  */
/******************************************************************************/

const char *	Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high for form.");
}

const char *	Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low for form.");
}

const char *	Form::AlreadySignedException::what(void) const throw()
{
	return ("Form is already signed and thus can't be signed again!");
}
