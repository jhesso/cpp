/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 23:24:48 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/08 00:19:06 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "ShrubberyCreationForm.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

ShrubberyCreationForm::ShrubberyCreationForm(void)
	:	AForm("Shrubbery Creation Form", ShrubberyCreationForm::gradeToSign,
			ShrubberyCreationForm::gradeToExecute),
		_target("Unknown")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src)
	:	AForm(src),
		_target(src._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target)
	:	AForm("Shrubbery Creation Form", ShrubberyCreationForm::gradeToSign,
			ShrubberyCreationForm::gradeToExecute),
		_target(target)
{
	std::cout << "ShrubberyCreationForm attribute constructor called" << std::endl;
	if (_target.empty())
		_target = "Unknown";
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

/******************************************************************************/
/*								OPERATORS								  	  */
/******************************************************************************/

ShrubberyCreationForm &	ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src)
{
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	if (this != &src)
		this->_target = src._target;
	return (*this);
}

/******************************************************************************/
/*								GETTERS										  */
/******************************************************************************/

std::string const &	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

void	ShrubberyCreationForm::beExecuted(void) const
{
	std::ofstream ofs;

	ofs.open((this->_target + "_shrubbery").c_str(), std::ofstream::out | std::ofstream::app);
	if (ofs.is_open())
	{
		if (std::rand() % 2)
			ofs << ShrubberyCreationForm::_tree;
		else
			ofs << ShrubberyCreationForm::_altTree;
		std::cout << "A shrubbery has been planted at " << _target << "_shrubbery." << std::endl;
		ofs.close();
	}
}

std::string const ShrubberyCreationForm::_tree =
"\n"
"                %%%,%%%%%%%\n"
"                 ,'%% \\\\-*%%%%%%%\n"
"           ;%%%%%*%   _%%%%\"\n"
"            ,%%%       \\(_.*%%%%.\n"
"            % *%%, ,%%%%*(    '\n"
"          %^     ,*%%% )\\|,%%*%,_\n"
"               *%    \\/ #).-\"*%%*\n"
"                   _.) ,/ *%,\n"
"           _________/)#(_____________\n\n";

std::string const	ShrubberyCreationForm::_altTree =
"\n"
"           \\/ |    |/\n"
"        \\/ / \\||/  /_/___/_\n"
"         \\/   |/ \\/\n"
"    _\\__\\_\\   |  /_____/_\n"
"           \\  | /          /\n"
"  __ _-----`  |{,-----------~\n"
"            \\ }{\n"
"             }{{\n"
"             }}{\n"
"             {{}\n"
"       , -=-~{ .-^- _\n"
"             `}\n"
"              {\n\n";
