/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:38:48 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/29 11:47:26 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

int	main(void)
{
	Zombie* z;

	std::cout << "Creating zombie on the stack" << std::endl;
	randomChump("test");
	std::cout << "Creating zombie on the heap" << std::endl;
	z = newZombie("jhesso");
	delete(z);
	return (0);
}
