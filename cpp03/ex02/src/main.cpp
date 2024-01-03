/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:11:37 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/27 17:53:15 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <climits>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void	printHp(ClapTrap const & trap)
{
	std::cout << "ClapTrap " << trap.getName() << " hp: " << trap.getHp() << std::endl;
}

void	scavPrintHp(ScavTrap const & trap)
{
	std::cout << "ScavTrap " << trap.getName() << " hp: " << trap.getHp() << std::endl;
}

void	fragPrintHp(FragTrap const & trap)
{
	std::cout << "FragTrap " << trap.getName() << " hp: " << trap.getHp() << std::endl;
}

void	printStats(FragTrap const & frag)
{
	std::cout	<< frag.getName() << std::endl
				<< "HP: " << frag.getHp() << std::endl
				<< "Energy: " << frag.getEnergy() << std::endl
				<< "AD: " << frag.getAd() << std::endl;
}

int	main(void)
{
	std::string	fragTrapName = "Frag-1.0";
	std::string	scavTrapName = "Scav-42";
	std::string	clapTrapName = "Trap-R2D2";

	FragTrap	frag(fragTrapName);
	ScavTrap	scav(scavTrapName);
	ClapTrap	clap(clapTrapName);

	fragPrintHp(frag);
	scavPrintHp(scav);
	printHp(clap);
	frag.highFivesGuys();
	clap.attack(scav.getName());
	scav.takeDamage(clap.getAd());
	scavPrintHp(scav);
	scav.attack(frag.getName());
	frag.takeDamage(scav.getAd());
	fragPrintHp(frag);
	frag.beRepaired(42);
	fragPrintHp(frag);
	scav.guardGate();
	scavPrintHp(scav);
	for (int i = 0; i < 21; i++)
	{
		frag.attack(scav.getName());
		scav.takeDamage(frag.getAd());
	}
	scavPrintHp(scav);
	scav.beRepaired(420);
	scavPrintHp(scav);
	frag.highFivesGuys();
	fragPrintHp(frag);
	frag.takeDamage(424242);
	fragPrintHp(frag);
	frag.highFivesGuys();

	FragTrap	copy(frag);
	fragPrintHp(copy);
	std::string	fName = "frag1";
	FragTrap	frag1(fName);
	printStats(frag1);
	frag1 = copy;
	printStats(frag1);

	return (0);
}
