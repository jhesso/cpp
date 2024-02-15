/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:04:17 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/15 20:13:38 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "MutantStack.hpp"

# define	GREEN	"\033[0;32m"
# define	YELLOW	"\033[0;33m"
# define	BLUE	"\033[0;34m"
# define	RED		"\033[0;31m"
# define	RESET	"\033[0m"

void	subjectTest(void)
{
	MutantStack<int> mstack;
	std::list<int>	list;

	std::cout << YELLOW << "---- SUBJECT TEST ----" << RESET << std::endl << std::endl;
	mstack.push(5);
	mstack.push(17);
	list.push_back(5);
	list.push_back(17);
	std::cout << "mstack top: " << mstack.top() << std::endl;
	std::cout << "list top " << list.back() << std::endl;
	mstack.pop();
	list.pop_back();
	std::cout << "mstack size: " << mstack.size() << std::endl;
	std::cout << "list size: " << list.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << "iterating over mstack from begin() to end()" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);
	std::cout << "iterating over list from begin() to end()" << std::endl;
	std::list<int>::iterator listIt = list.begin();
	std::list<int>::iterator listIte = list.end();
	++listIt;
	--listIt;
	while (listIt != listIte)
	{
		std::cout << *listIt << std::endl;
		++listIt;
	}
}

void	constIterTest(void)
{
	MutantStack<int> mstack;
	std::list<int>	list;

	std::cout << YELLOW << "---- SUBJECT TEST USING CONST ITERATORS ----" << RESET << std::endl << std::endl;
	mstack.push(5);
	mstack.push(17);
	list.push_back(5);
	list.push_back(17);
	mstack.pop();
	list.pop_back();
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << "iterating over mstack from begin() to end()" << std::endl;
	MutantStack<int>::const_iterator it = mstack.begin();
	MutantStack<int>::const_iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);
	std::cout << "iterating over list from begin() to end()" << std::endl;
	std::list<int>::const_iterator listIt = list.cbegin();
	std::list<int>::const_iterator listIte = list.cend();
	++listIt;
	--listIt;
	while (listIt != listIte)
	{
		std::cout << *listIt << std::endl;
		++listIt;
	}
}

int	main(void)
{
	subjectTest();
	std::cout << std::endl;
	constIterTest();

	return 0;
}
