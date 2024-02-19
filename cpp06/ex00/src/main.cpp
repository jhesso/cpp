/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:33:34 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/19 15:49:07 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./converter <scalar_to_convert>" << std::endl
					<< "Valid scalars to convert: int, float, double or char" << std::endl;
		return 1;
	}
	try
	{
		// ScalarConverter converter;
		ScalarConverter::convert(av[1]);
		// std::cout << converter << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Could not convert: " << e.what() << std::endl;
	}
	return 0;
}
