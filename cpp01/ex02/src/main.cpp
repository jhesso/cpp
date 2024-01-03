/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:08:13 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/29 12:03:29 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string		brain = "HI THIS IS BRAIN";
	std::string*	stringPTR = &brain;
	std::string&	stringREF = brain;

	std::cout	<< "memory address of brain: " << &brain << std::endl;
	std::cout	<< "memory address held by stringPTR :" << stringPTR << std::endl;
	std::cout	<< "memory address held by stringREF :" << &stringREF << std::endl;

	std::cout	<< std::endl << "value of brain: " << brain << std::endl;
	std::cout	<< "value pointed to by stringPTR :" << *stringPTR << std::endl;
	std::cout	<< "value pointed to by stringREF :" << stringREF << std::endl;
	return (0);
}
