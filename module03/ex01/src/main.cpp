/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:11:37 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/27 17:10:31 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <climits>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void	printHp(ClapTrap const & trap)
{
	std::cout << "ClapTrap " << trap.getName() << " hp: " << trap.getHp() << std::endl;
}

void	scavPrintHp(ScavTrap const & trap)
{
	std::cout << "ScavTrap " << trap.getName() << " hp: " << trap.getHp() << std::endl;
}


int	main(void)
{
	std::string	name0 = "scav-v1";
	std::string	name1 = "scav-v2";

	ClapTrap	trap0("trap-v1");
	ScavTrap	scav0(name0);
	ScavTrap	scav1(name1);

	printHp(trap0);
	scavPrintHp(scav0);
	trap0.attack(scav0.getName());
	scav0.takeDamage(trap0.getAd());
	scavPrintHp(scav0);
	scav0.attack(trap0.getName());
	trap0.takeDamage(scav0.getAd());
	printHp(trap0);
	trap0.beRepaired(42);
	printHp(trap0);
	scav0.guardGate();
	scavPrintHp(scav0);
	for (int i = 0; i < 21; i++)
		scav0.beRepaired(42);
	scavPrintHp(scav0);
	scavPrintHp(scav1);
	scav0.attack(scav1.getName());
	scav1.takeDamage(scav0.getAd());
	scavPrintHp(scav1);
	scav1.attack(scav0.getName());
	scav0.takeDamage(scav1.getAd());
	scavPrintHp(scav0);
	scav1.guardGate();
	scav0.takeDamage(50000);
	scavPrintHp(scav0);
	scav0.beRepaired(42);
	scavPrintHp(scav0);
	scav1.beRepaired(4242424242);
	scavPrintHp(scav1);
	scav1.attack(scav1.getName());
	scav1.takeDamage(scav1.getAd());
	scavPrintHp(scav1);

	return (0);
}
