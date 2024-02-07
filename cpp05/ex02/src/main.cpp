/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 23:26:03 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/08 00:47:43 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void)
{
	{
		Bureaucrat	b1("Intern", 142);
		Bureaucrat	b2("Jhesso", 65);
		Bureaucrat	b3("Leaders lackey", 6);

		std::cout << std::endl << "Bureaucrats working today:" << std::endl
					<< b1 << std::endl << b2 << std::endl << b3 << std::endl << std::endl;

		ShrubberyCreationForm	shrub("Dying house plant");
		RobotomyRequestForm		rob("GPT");
		PresidentialPardonForm	pardon(b2.getName());

		std::cout << std::endl << "Forms to be executed today:" << std::endl
					<< shrub << std::endl << rob << std::endl << pardon << std::endl << std::endl;

		std::cout << "Signing and executing shrubbery form: " << std::endl;
		b1.signForm(shrub);
		b1.executeForm(shrub);
		b2.executeForm(shrub);

		std::cout << std::endl << "Signing and executing robotomy form: " << std::endl;
		b1.signForm(rob);
		b2.executeForm(rob);
		b2.signForm(rob);
		b2.executeForm(rob);
		b1.executeForm(rob);
		b3.executeForm(rob);

		std::cout << std::endl << "Signing and executing presidential pardon form: " << std::endl;
		b2.signForm(pardon);
		b2.executeForm(pardon);
		b3.signForm(pardon);
		b3.executeForm(pardon);
		b3.incGrade();
		b3.executeForm(pardon);
		std::cout << std::endl;
	}

	std::cout << std::endl << "K thanks bye!" << std::endl;

	return 0;
}
