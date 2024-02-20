/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 23:40:04 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/20 17:03:01 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include <chrono>
#include <sstream>
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
		this->_deque = src._deque;
	}
	return (*this);
}

/******************************************************************************/
/*							PRIVATE FUNCTIONS								  */
/******************************************************************************/

void	PmergeMe::sort(char ** av)
{
	std::chrono::high_resolution_clock::time_point vecStart, vecEnd,
													dequeStart, dequeEnd;
	std::chrono::duration<double, std::micro> vecTime, dequeTime;

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

	std::cout << BLUE << "Sorting with std::deque" << RESET << std::endl;
	std::cout << "Before: ";
	dequeStart = std::chrono::high_resolution_clock::now();
	validateInput(av, _deque);
	printContainer(_deque);
	sortDeque();
	dequeEnd = std::chrono::high_resolution_clock::now();
	dequeTime = dequeEnd - dequeStart;
	std::cout << "After: ";
	printContainer(_deque);
	std::cout << std::endl;

	printTime("vec", vecTime);
	printTime("deque", dequeTime);
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

void	PmergeMe::validateInput(char **av, std::deque<int> & deque)
{
	int	i = 1;
	int	nb;

	while (av[i])
	{
		nb = convertStringToInt(av[i]);
		checkDuplicates(nb, deque);
		deque.push_back(nb);
		i++;
	}
}

int	PmergeMe::convertStringToInt(std::string str)
{
	std::stringstream s;
	s << str;
	int n;
	while (!(s >> n) || s.fail() || !s.eof() || n <= 0)
		throw std::runtime_error("Error: Invalid input");
	return n;
}

void	PmergeMe::checkDuplicates(int const nb, std::vector<int> const & vec)
{
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++)
	{
		if (nb == *it)
			throw std::runtime_error("Error: Duplicate input");
	}
}

void	PmergeMe::checkDuplicates(int const nb, std::deque<int> const & deque)
{
	for (std::deque<int>::const_iterator it = deque.begin(); it != deque.end(); it++)
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
	// if given an odd amount of numbers, keep the last number in a variable
	int	straggler = -1;
	if (_vec.size() % 2)
	{
		straggler = _vec.back();
		_vec.pop_back();
	}
	// pair up the numbers
	std::vector<std::pair<int, int>> pairs = makePairs(_vec);
	// sort the sequence recursively by the value of its largest pair
	sortPairs(pairs, (pairs.size() - 1));
	// create srted sequence from the pairs
	sortSequence(pairs, straggler);
}

std::vector<std::pair<int, int>>	PmergeMe::makePairs(std::vector<int> & vec)
{
	std::vector<std::pair<int, int>> pairs;
	for (size_t i = 0; i < vec.size(); i += 2)
	{
		std::pair<int, int> pair = std::minmax(vec[i], vec[i + 1]);
		pairs.push_back(pair);
	}
	return pairs;
}

void	PmergeMe::sortPairs(std::vector<std::pair<int, int>> & pairs, int len)
{
	if (len == 0)
		return ;
	sortPairs(pairs, len - 1);

	std::pair<int, int> pair = pairs[len];
	int i = len - 1;
	while (i >= 0 && pairs[i].second > pair.second)
	{
		pairs[i + 1] = pairs[i];
		i--;
	}
	pairs[i + 1] = pair;
}

void	PmergeMe::sortSequence(std::vector<std::pair<int, int>> & pairs, int straggler)
{
	_vec.clear();
	std::vector<int> pend;

	for (size_t i = 0; i < pairs.size(); i++)
	{
		_vec.push_back(pairs[i].second);
		pend.push_back(pairs[i].first);
	}
	int s1 = pend.front();
	pend.erase(pend.begin());
	_vec.insert(_vec.begin(), s1);
	if (straggler != -1)
		pend.push_back(straggler);
	for (int element : pend)
	{
		size_t pos = std::upper_bound(_vec.begin(), _vec.end(), element) - _vec.begin();
		_vec.insert(_vec.begin() + pos, element);
	}
}

/*-------------------------------   Deque   ----------------------------------*/

void	PmergeMe::sortDeque(void)
{
	if (_deque.size() == 1)
		return ;
	int	straggler = -1;
	if (_deque.size() % 2)
	{
		straggler = _deque.back();
		_deque.pop_back();
	}
	std::deque<std::pair<int, int>> pairs = makePairs(_deque);
	sortPairs(pairs, (pairs.size() - 1));
	sortSequence(pairs, straggler);
}

std::deque<std::pair<int, int>>	PmergeMe::makePairs(std::deque<int> & deque)
{
	std::deque<std::pair<int, int>> pairs;
	for (size_t i = 0; i < deque.size(); i += 2)
	{
		std::pair<int, int> pair = std::minmax(deque[i], deque[i + 1]);
		pairs.push_back(pair);
	}
	return pairs;
}

void	PmergeMe::sortPairs(std::deque<std::pair<int, int>> & pairs, int len)
{
	if (len == 0)
		return ;
	sortPairs(pairs, len - 1);

	std::pair<int, int> pair = pairs[len];
	int i = len - 1;
	while (i >= 0 && pairs[i].second > pair.second)
	{
		pairs[i + 1] = pairs[i];
		i--;
	}
	pairs[i + 1] = pair;
}

void	PmergeMe::sortSequence(std::deque<std::pair<int, int>> & pairs, int straggler)
{
	_deque.clear();
	std::deque<int> pend;

	for (size_t i = 0; i < pairs.size(); i++)
	{
		_deque.push_back(pairs[i].second);
		pend.push_back(pairs[i].first);
	}
	int s1 = pend.front();
	pend.erase(pend.begin());
	_deque.insert(_deque.begin(), s1);
	if (straggler != -1)
		pend.push_back(straggler);
	for (int element : pend)
	{
		size_t pos = std::upper_bound(_deque.begin(), _deque.end(), element) - _deque.begin();
		_deque.insert(_deque.begin() + pos, element);
	}
}

/*-------------------------------   Print   ----------------------------------*/

void	PmergeMe::printContainer(std::vector<int> const & container)
{
	for (std::vector<int>::const_iterator it = container.begin(); it != container.end(); it++)
		std::cout << *it << " ";

	std::cout << std::endl;
}

void	PmergeMe::printContainer(std::deque<int> const & container)
{
	for (std::deque<int>::const_iterator it = container.begin(); it != container.end(); it++)
		std::cout << *it << " ";

	std::cout << std::endl;
}

void	PmergeMe::printTime(std::string type, std::chrono::duration<double, std::micro> time)
{
	std::cout << YELLOW << "Time to process a range of ";
	if (type == "vec")
		std::cout << _vec.size() << " elements with std::vector : ";
	else
		std::cout << _deque.size() << " elements with std::deque : ";
	std::cout << time.count() << " us" << RESET << std::endl;

}
