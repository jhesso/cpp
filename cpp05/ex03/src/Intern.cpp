/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 00:54:15 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/08 01:07:59 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Intern::Intern(void)
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern const & src)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = src;
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor called" << std::endl;
}

/******************************************************************************/
/*								OPERATORS								  	  */
/******************************************************************************/

Intern &	Intern::operator=(Intern const & src)
{
	std::cout << "Intern copy assignment operator called" << std::endl;
	(void)src;
	return (*this);
}

/******************************************************************************/
/*							PRIVATE FUNCTIONS								  */
/******************************************************************************/

static AForm *	createPresidentialPardonForm(std::string const & target)
{
	return (new PresidentialPardonForm(target));
}

static AForm *	createRobotomyRequestForm(std::string const & target)
{
	return (new RobotomyRequestForm(target));
}

static AForm *	createShrubberyCreationForm(std::string const & target)
{
	return (new ShrubberyCreationForm(target));
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

AForm *	Intern::makeForm(std::string name, std::string target)
{
	AForm * formToCreate = NULL;
	static formList const forms[3] =
	{
		{"shrubbery creation", createShrubberyCreationForm},
		{"robotomy request", createRobotomyRequestForm},
		{"presidential pardon", createPresidentialPardonForm}
	};
	for (int i = 0; i < 3; i++)
	{
		if (forms[i].name == name)
		{
			formToCreate = forms[i].function(target);
			std::cout << "Intern created " << *formToCreate << std::endl;
			return (formToCreate);
		}
	}
	std::cout << "Intern couldn't create form named " << name << std::endl;
	throw Intern::InvalidFormName();
}

/******************************************************************************/
/*								  EXCEPTIONS								  */
/******************************************************************************/

const char *	Intern::InvalidFormName::what(void) const throw()
{
	return ("Invalid form name");
}
