/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:08:13 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/19 16:18:09 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string		brain = "HI THIS IS BRAIN";
	std::string*	brainPt = &brain;
	std::string&	brainRef = brain;

	std::cout	<< "memory address of brain: " << &brain << std::endl;
	std::cout	<< "memory address held by brainPt: " << brainPt << std::endl;
	std::cout	<< "memory address held by brainRef: " << &brainRef << std::endl;

	std::cout	<< std::endl << "value of brain: " << brain << std::endl;
	std::cout	<< "value pointed to by brainPt: " << *brainPt << std::endl;
	std::cout	<< "value pointed to by brainRef: " << brainRef << std::endl;
	return (0);
}
