/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:34:49 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/07 21:50:05 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

void	createBureaucrat(std::string name, int grade)
{
	std::cout << "Constructing bureaucrat called: " << name << " with grade: "
				<< grade << std::endl;
	try
	{
		Bureaucrat b(name, grade);
		std::cout << b << " created" << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException & e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException & e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

int	main(void)
{
	std::cout << "---- TEST CONSTRUCTING BUREAUCRATS ----" << std::endl;
	{
		createBureaucrat("John", 42);
		createBureaucrat("Dave", -42);
		createBureaucrat("CEO", 0);
		createBureaucrat("Mary", 1);
		createBureaucrat("Michelle", 150);
		createBureaucrat("Michael", 151);
	}
	std::cout << std::endl << "---- TEST ASSIGNMENT OPERATOR ----" << std::endl;
	{
		Bureaucrat b1("Jhesso", 42);
		Bureaucrat b2("Evaluator", Bureaucrat::lowestGrade);

		std::cout << "Two bureaucrats created:" << std::endl;
		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		b2 = b1;
		std::cout << "bureaucrat nbr 2 = bureaucrat nbr 1" << std::endl;
		std::cout << "(b2) " << b2 << " == (b1) " << b1 << std::endl;
	}
	std::cout << std::endl << "---- TEST GRADE INCREMENT/DECREMENT ----" << std::endl;
	{
		Bureaucrat b1("Jhesso", Bureaucrat::highestGrade);
		std::cout << "Bureaucrat " << b1 << " created" << std::endl;
		try
		{
			std::cout << "Decrementing grade. result should be: " << b1.getGrade() + 1 << std::endl;
			b1.decGrade();
			std::cout << b1 << std::endl;
			std::cout << "Incrementing grade. result should be: " << b1.getGrade() - 1 << std::endl;
			b1.incGrade();
			std::cout << b1 << std::endl;
			std::cout << "Incrementing grade. result should be: " << b1.getGrade() - 1 << std::endl;
			b1.incGrade();
			std::cout << b1 << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException & e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException & e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		try
		{
			std::cout << "Setting grade to: " << Bureaucrat::lowestGrade << std::endl;
			b1.setGrade(Bureaucrat::lowestGrade);
			std::cout << b1 << std::endl;
			std::cout << "Decrementing grade. result should be: " << b1.getGrade() + 1 << std::endl;
			b1.decGrade();
			std::cout << b1 << std::endl;
		}
		catch(Bureaucrat::GradeTooHighException & e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooLowException & e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "---- TEST INCREMENT/DECREMENT 2 ----" << std::endl;
	{
		Bureaucrat b1("Final Boss", Bureaucrat::highestGrade);
		std::cout << "Bureaucrat " << b1 << " created" << std::endl;
		try
		{
			std::cout << "Decrementing grade by 42. result should be: " << b1.getGrade() + 42 << std::endl;
			b1.decGrade(42);
			std::cout << b1 << std::endl;
			std::cout << "Incrementing grade by 21. result should be: " << b1.getGrade() - 21 << std::endl;
			b1.incGrade(21);
			std::cout << b1 << std::endl;
			std::cout << "Decrementing grade by 500. result should be: " << b1.getGrade() + 500 << std::endl;
			b1.decGrade(500);
			std::cout << b1 << std::endl;
		}
		catch(Bureaucrat::GradeTooHighException & e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooLowException & e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl << std::endl << "All Gucci!" << std::endl;

	return 0;
}
