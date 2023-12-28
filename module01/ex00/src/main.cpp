/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:38:48 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/28 12:11:55 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

int	main(void)
{
	Zombie* z;

	randomChump("test");
	z = newZombie("jhesso");
	delete(z);
	return (0);
}
