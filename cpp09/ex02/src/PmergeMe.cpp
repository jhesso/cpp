/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 23:40:04 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/20 01:08:13 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <chrono>
#include "PmergeMe.hpp"

#define MSG false

# define	GREEN	"\033[0;32m"
# define	YELLOW	"\033[0;33m"
# define	BLUE	"\033[0;34m"
# define	RED		"\033[0;31m"
# define	RESET	"\033[0m"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

PmergeMe::PmergeMe(void)
{
	if (MSG)
		std::cout << "PmergeMe default constructor called" << std::endl;
}

PmergeMe::PmergeMe(PmergeMe const & src)
{
	if (MSG)
		std::cout << "PmergeMe copy constructor called" << std::endl;
	*this = src;
}

PmergeMe::PmergeMe(char ** av)
{
	sort(av);
}

PmergeMe::~PmergeMe(void)
{
	if (MSG)
		std::cout << "PmergeMe destructor called" << std::endl;
}

/******************************************************************************/
/*								OPERATORS								  	  */
/******************************************************************************/

PmergeMe &	PmergeMe::operator=(PmergeMe const & src)
{
	if (MSG)
		std::cout << "PmergeMe copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_vec = src._vec;
		this->_list = src._list;
	}
	return (*this);
}

/******************************************************************************/
/*							PRIVATE FUNCTIONS								  */
/******************************************************************************/

void	PmergeMe::sort(char ** av)
{
	std::chrono::high_resolution_clock::time_point vecStart, vecEnd,
													listStart, listEnd;
	std::chrono::duration<double, std::micro> vecTime, listTime;

	std::cout << BLUE << "Sorting with std::vector" << RESET << std::endl;
	std::cout << "Before: ";
	vecStart = std::chrono::high_resolution_clock::now();
	validateInput(av, _vec);
	printContainer(_vec);
	sortVec();
	vecEnd = std::chrono::high_resolution_clock::now();
	vecTime = vecEnd - vecStart;
	std::cout << "After: ";
	printContainer(_vec);
	std::cout << std::endl;

	std::cout << BLUE << "Sorting with std::list" << RESET << std::endl;
	std::cout << "Before: ";
	listStart = std::chrono::high_resolution_clock::now();
	validateInput(av, _list);
	printContainer(_list);
	sortList();
	listEnd = std::chrono::high_resolution_clock::now();
	listTime = listEnd - listStart;
	std::cout << "After: ";
	printContainer(_list);
	std::cout << std::endl;

	printTime("vec", vecTime);
	printTime("list", listTime);
}

/*-------------------------------   Input   ----------------------------------*/

void	PmergeMe::validateInput(char **av, std::vector<int> & vec)
{
	int	i = 1;
	int	nb;

	while (av[i])
	{
		nb = convertStringToInt(av[i]);
		checkDuplicates(nb, vec);
		vec.push_back(nb);
		i++;
	}
}

void	PmergeMe::validateInput(char **av, std::list<int> & list)
{
	int	i = 1;
	int	nb;

	while (av[i])
	{
		nb = convertStringToInt(av[i]);
		checkDuplicates(nb, list);
		list.push_back(nb);
		i++;
	}
}

int	PmergeMe::convertStringToInt(std::string str)
{
	try
	{
		int nb = std::stoi(str);
		if (nb < 1)
			throw std::runtime_error("Error: Invalid input");
		return nb;
	}
	catch(const std::exception& e)
	{
		throw std::runtime_error("Error: Invalid input");
	}
}

void	PmergeMe::checkDuplicates(int const nb, std::vector<int> const & vec)
{
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++)
	{
		if (nb == *it)
			throw std::runtime_error("Error: Duplicate input");
	}
}

void	PmergeMe::checkDuplicates(int const nb, std::list<int> const & list)
{
	for (std::list<int>::const_iterator it = list.begin(); it != list.end(); it++)
	{
		if (nb == *it)
			throw std::runtime_error("Error: Duplicate input");
	}
}

/*-------------------------------   Vector   ---------------------------------*/

void	PmergeMe::sortVec(void)
{
	if (_vec.size() == 1)
		return ;

}

/*--------------------------------   List   ----------------------------------*/

void	PmergeMe::sortList(void)
{
	if (_list.size() == 1)
		return ;
}

/*-------------------------------   Print   ----------------------------------*/

void	PmergeMe::printContainer(std::vector<int> const & container)
{
	for (std::vector<int>::const_iterator it = container.begin(); it != container.end(); it++)
		std::cout << *it << " ";

	std::cout << std::endl;
}

void	PmergeMe::printContainer(std::list<int> const & container)
{
	for (std::list<int>::const_iterator it = container.begin(); it != container.end(); it++)
		std::cout << *it << " ";

	std::cout << std::endl;
}

void	PmergeMe::printTime(std::string type, std::chrono::duration<double, std::micro> time)
{
	std::cout << YELLOW << "Time to process a range of ";
	if (type == "vec")
		std::cout << _vec.size() << " elements with std::vector : ";
	else
		std::cout << _list.size() << " elements with std::list : ";
	std::cout << time.count() << " us" << RESET << std::endl;

}
