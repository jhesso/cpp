/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 22:47:45 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/07 23:20:54 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

void	createTestForm(std::string name, int signGrade, int executeGrade)
{
	std::cout << "Creating form called " << name << " with required grade to:"
				<< std::endl << "sign: " << signGrade << std::endl
				<< "execute: " << executeGrade << std::endl;
	try
	{
		Form	f(name, signGrade, executeGrade);
		std::cout << f << std::endl << " successfully created." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

int	main(void)
{
	std::cout << "---- TEST FORM ATTRIBUTE CONSTRUCTION ----" << std::endl;
	{
		createTestForm("Test Form", 21, 21);
		createTestForm("Fully Functional", 150, 1);
		createTestForm("Unsignable", 0, 1);
		createTestForm("Unexecutable", 1, 151);
	}
	std::cout << std::endl << "---- TEST FORM COPY CONSTRUCTOR ----" << std::endl;
	{
		Form f("Formal Form", 42, 42);
		std::cout << "Form is " << f << std::endl;
		Form fCopy(f);
		std::cout << "Form copy is " << fCopy << std::endl;
	}
	std::cout << std::endl << "---- TEST FORM SIGNING ----" << std::endl;
	{
		Bureaucrat	b1("Intern", 150);
		Bureaucrat	b2("Jhesso", 42);
		Bureaucrat	b3("Supreme leader", 1);
		Form	f1("Basic Form", 150, 150);
		Form	f2("license to kill", 42, 42);
		Form	f3("Nuclear launch code publication Form", 1, 1);

		std::cout << std::endl << "Bureaucrats at work today:" << std::endl
					<< b1 << std::endl << b2 << std::endl << b3 << std::endl;
		std::cout << std::endl << "Forms to be signed:" << std::endl
					<< f1 << std::endl << f2 << std::endl << f3 << std::endl << std::endl;
		std::cout << std::endl << "Attempting to sign " << f1 << std::endl;
		b1.signForm(f1);
		b2.signForm(f1);
		b3.signForm(f1);
		std::cout << std::endl << "Attempting to sign " << f2 << std::endl;
		b1.signForm(f2);
		b2.signForm(f2);
		b3.signForm(f2);
		std::cout << std::endl << "Attempting to sign form " << f3 << std::endl;
		b1.signForm(f3);
		b2.signForm(f3);
		b3.signForm(f3);
		std::cout << std::endl;
	}
	std::cout << std::endl << "Ok thanks Bye! :>" << std::endl;

	return 0;
}
