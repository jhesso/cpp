/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:04:45 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/15 19:01:25 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
#include "Span.hpp"

# define	GREEN	"\033[0;32m"
# define	YELLOW	"\033[0;33m"
# define	BLUE	"\033[0;34m"
# define	RED		"\033[0;31m"
# define	RESET	"\033[0m"

void	findShortestLongest(Span & sp)
{
	try
	{
		std::cout << "Finding shortest span..." << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << GREEN << "SUCCESS!" << RESET << std::endl;
		std::cout << "Finding longest span..." << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << GREEN << "SUCCESS!" << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}
}

void	addRangeOfNumbersToSpan(Span & sp, int size)
{
	std::list<int> list;

	for (int i = 0; i < size; i++)
			list.push_back(rand());
	try
	{
		std::list<int>::iterator begin = list.begin();
		std::list<int>::iterator end = list.end();
		sp.addNumberRange<std::list<int>>(begin, end);
		std::cout << GREEN << "Numbers added to span" << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}
}

int	main(void)
{
	{
		std::cout << YELLOW << "---- TEST SUBJECT ----" << RESET << std::endl << std::endl;

		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		srand(time(NULL));
		Span	sp(10000);

		std::cout << std::endl << YELLOW << "---- TEST 10k numbers ----" << RESET << std::endl << std::endl;
		addRangeOfNumbersToSpan(sp, 10000);
		findShortestLongest(sp);
	}
	{
		std::cout << std::endl << YELLOW << "---- TEST 100k numbers ----" << RESET << std::endl << std::endl;

		Span sp(100000);
		addRangeOfNumbersToSpan(sp, 100000);
		findShortestLongest(sp);
	}
	{
		std::cout << std::endl << YELLOW << "---- TEST SPAN SIZE 1 ----" << RESET << std::endl << std::endl;
		Span sp(1);
		sp.addNumber(42);
		try
		{
			std::cout << "Finding shortest span..." << std::endl;
			sp.shortestSpan();
			std::cout << RED << "well this is awkward.." << RESET << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << GREEN << "Found exception as expected!" << RESET << std::endl;
			std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
		}
		try
		{
			std::cout << "Finding longest span..." << std::endl;
			sp.longestSpan();
			std::cout << RED << "well this is awkward.." << RESET << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << GREEN << "Found exception as expected!" << RESET << std::endl;
			std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl << YELLOW << "---- TEST ADD ELEMENT(S) TO FULL SPAN ----" << RESET << std::endl << std::endl;
		Span sp(0);
		try
		{
			std::cout << "Adding one number to span" << std::endl;
			sp.addNumber(42);
			std::cout << RED << "Whoops! you shouldn't be reading this!" << RESET << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << GREEN << "Found exception as expected!" << RESET << std::endl;
			std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
		}
		std::cout << "Adding multiple numbers to span" << std::endl;
		addRangeOfNumbersToSpan(sp, 500);
	}
	return 0;
}
