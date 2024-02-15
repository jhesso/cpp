/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:21:28 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/15 21:24:59 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

# define	GREEN	"\033[0;32m"
# define	YELLOW	"\033[0;33m"
# define	BLUE	"\033[0;34m"
# define	RED		"\033[0;31m"
# define	RESET	"\033[0m"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./btc <database_file>" << std::endl;
		return 1;
	}
	try
	{
		BitcoinExchange btc;
		btc.calculateValues(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
		return 1;
	}
	return 0;
}
