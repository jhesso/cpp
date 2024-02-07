/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 00:53:07 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/08 01:29:39 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

void	createForm(std::string name, std::string target)
{
	std::cout << std::endl << "Creating form " << name << " with target " << target << std::endl << std::endl;
	Intern	intern;
	Bureaucrat	boss("Bossman", 1);
	AForm	*form;

	try
	{
		form = intern.makeForm(name, target);
		boss.signForm(*form);
		boss.executeForm(*form);
		delete(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

int	main(void)
{
	std::string const	shrubberyFormName = "shrubbery creation";
	std::string const	robotomyFormName = "robotomy request";
	std::string const	presidentialFormName = "presidential pardon";

	createForm(shrubberyFormName, "this-one-is-gonna-survive");
	createForm(robotomyFormName, "Bender");
	createForm(presidentialFormName, "007");
	createForm("srurrerycreat", "nope");
	createForm("", "");

	std::cout << std::endl << "K, thanks bye!" << std::endl;

	return 0;
}
