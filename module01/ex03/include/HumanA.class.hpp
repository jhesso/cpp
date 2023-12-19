/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:32:38 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/19 16:48:31 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_CLASS_HPP
# define HUMANA_CLASS_HPP

# include <string>
# include <iostream>
# include "Weapon.class.hpp"

class HumanA
{
	private:
		std::string	_name;
		Weapon	_weapon;

	public:
		HumanA(std::string name, Weapon weapon);
		~HumanA(void);

		void		attack(void);
		void		setWeapon(Weapon weapon);
		std::string	getName(void);
		Weapon		getWeapon(void);
};

#endif
