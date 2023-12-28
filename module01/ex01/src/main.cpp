/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:14:11 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/28 12:49:56 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name);

int	main(void)
{
	int			N;
	std::string	name;
	Zombie*		zombies;

	name = "Zombie";
	N = 5;
	zombies = zombieHorde(N, name);
	for (int i = 0; i < N; i++)
		zombies[i].announce();
	delete[] zombies;
	return (0);
}
