/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:11:37 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/22 19:25:47 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <climits>
#include "ClapTrap.hpp"

void	printHp(ClapTrap const & trap)
{
	std::cout << "ClapTrap " << trap.getName() << " hp: " << trap.getHp() << std::endl;
}

int	main(void)
{
	ClapTrap	trap0("trap-v1");
	ClapTrap	trap1("trap-v2");
	ClapTrap	limitless("limitless");

	printHp(trap0);
	printHp(trap1);
	for (int i = 0; i < 12; i++)
	{
		trap0.attack(trap1.getName());
		trap1.takeDamage(trap0.getAd());
	}
	printHp(trap1);
	trap1.attack(trap0.getName());
	trap0.beRepaired(10);
	printHp(trap0);
	trap1.takeDamage(3);
	printHp(trap1);
	trap1.beRepaired(1);
	printHp(trap1);
	trap1.takeDamage(7);
	printHp(trap1);
	trap1.takeDamage(1);
	printHp(trap1);
	trap1.beRepaired(42000);
	printHp(trap1);

	printHp(limitless);
	limitless.beRepaired(UINT_MAX);
	printHp(limitless);
	limitless.takeDamage(UINT_MAX - INT_MAX);
	printHp(limitless);
	limitless.takeDamage(UINT_MAX);
	printHp(limitless);

	return (0);
}
