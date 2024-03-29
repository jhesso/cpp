/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:38:27 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/18 20:55:45 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

# define	GREEN	"\033[0;32m"
# define	YELLOW	"\033[0;33m"
# define	BLUE	"\033[0;34m"
# define	RED		"\033[0;31m"
# define	RESET	"\033[0m"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << RED << "Usage: ./RPN \"Inverted Polish expression\"" << RESET << std::endl;
		return 1;
	}
	try
	{
		RPN rpn;
		rpn.calculate(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
		return 1;
	}
	return 0;
}
