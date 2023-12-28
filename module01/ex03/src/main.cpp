/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:53:21 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/28 12:54:08 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void)
{
	Weapon	club("crude spiked club");
	HumanA	bob("Bob", club);
	HumanB	jim("Jim");
	Weapon	sword("katana");
	Weapon	empty("");

	bob.attack();
	jim.attack();
	club.setType("some other type of club");
	jim.setWeapon(sword);
	bob.attack();
	jim.attack();
	return (0);
}
