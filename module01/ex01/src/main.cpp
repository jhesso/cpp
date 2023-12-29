/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:14:11 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/29 11:54:21 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name);

int	main(void)
{
	int			N;
	std::string	name;
	Zombie*		zombies;

	name = "Zombie";
	N = 5;
	std::cout << "Allocating " << N << " zombies..." << std::endl;
	zombies = zombieHorde(N, name);
	std::cout << "Announcing the zombies..." << std::endl;
	for (int i = 0; i < N; i++)
		zombies[i].announce();
	delete[] zombies;
	return (0);
}
