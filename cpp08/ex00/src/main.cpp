/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 23:42:26 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/15 17:02:12 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <iterator>
#include "easyfind.hpp"

# define	GREEN	"\033[0;32m"
# define	YELLOW	"\033[0;33m"
# define	BLUE	"\033[0;34m"
# define	RED		"\033[0;31m"
# define	RESET	"\033[0m"

template <typename T>
void	search(T & container, int elem)
{
	std::cout << BLUE << "Searching for: " << elem << RESET << std::endl;
	typename T::const_iterator iter;
	try
	{
		iter = easyfind(container, elem);
		std::cout << GREEN << "Found element at index: " << std::distance(container.cbegin(), iter) << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception: " << e.what() << std::endl;
	}
}

int	main(void)
{
	{
		std::cout << YELLOW << "--- TEST VECTOR ----" << RESET << std::endl << std::endl;
		std::vector<int> vec;

		std::cout << "Filling container with some values" << std::endl;
		for (int i = 0; i < 10; i++)
			vec.push_back(i / 2);
		search(vec, 4);
		search(vec, 2);
		search(vec, 42);
	}
	{
		std::cout << std::endl << YELLOW << "---- TEST LIST ----" << RESET << std::endl << std::endl;
		std::list<int> list;
		std::cout << "Filling container with some values" << std::endl;
		for (int i = 0; i < 43; i++)
			list.push_back(i);
		search(list, 3);
		search(list, 66);
		search(list, 42);
		search(list, -333);
	}
	{
		std::cout << std::endl << YELLOW << "---- TEST DEQUE ----" << RESET << std::endl << std::endl;
		std::deque<int> deque;
		std::cout << "Filling container with some values" << std::endl;
		for (int i = -42; i < 43; i++)
			deque.push_back(i);
		search(deque, -42);
		search(deque, 0);
		search(deque, 54);
		search(deque, 42);
	}

	return 0;
}
