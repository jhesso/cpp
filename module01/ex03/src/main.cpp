/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:53:21 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/20 14:28:57 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.class.hpp"
#include "HumanA.class.hpp"
#include "HumanB.class.hpp"

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
