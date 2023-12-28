/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:46:47 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/28 13:00:08 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int	main(void)
{
	Harl	harl;

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
