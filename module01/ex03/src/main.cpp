/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:53:21 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/19 16:55:38 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.class.hpp"
#include "HumanA.class.hpp"
#include "HumanB.class.hpp"

int	main(void)
{
	Weapon club("crude spiked club");
	HumanA bob("Bob", club);

	bob.attack();
	club.setType("some other type of club");
	bob.attack();
	return (0);
}
