/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:46:47 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/29 12:30:57 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int	main(void)
{
	Harl	harl;

	std::cout << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl << std::endl;
	harl.complain("INFO");
	std::cout << std::endl << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl << std::endl;
	harl.complain("THIS IS NOT A FUNCTION");
	return (0);
}
