/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 23:42:26 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/15 00:29:07 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include "easyfind.hpp"

# define	GREEN	"\033[0;32m"
# define	YELLOW	"\033[0;33m"
# define	BLUE	"\033[0;34m"
# define	RED		"\033[0;31m"
# define	RESET	"\033[0m"

int	main(void)
{
	std::cout << YELLOW << "--- TEST VECTOR ----" << RESET << std::endl << std::endl;
	std::vector<int> vec;

	std::cout << "Filling container with some values" << std::endl;
	for (int i = 0; i < 10; i++)
		vec.push_back(i / 2);
	std::cout << "Container:" << std::endl;
	for (std::vector<int>::iterator i = vec.begin(); i != vec.end(); i++)
		std::cout << "[" << vec[*i] << "] ";
	std::cout << std::endl;
	std::cout << "easyfind(vec, 4): " << *(easyfind(vec, 4)) << std::endl;
	std::cout << "easyfind(vec, 2): " << *(easyfind(vec, 2)) << std::endl << std::endl;



	return 0;
}
