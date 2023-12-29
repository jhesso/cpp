/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:12:14 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/29 12:07:21 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include <string>
# include "Weapon.hpp"

class HumanB
{
	private:
		std::string const	_name;
		Weapon *			_weapon;

	public:
		HumanB(std::string const name);
		~HumanB(void);
		void	attack(void) const;
		void	setWeapon(Weapon &weapon);
};

#endif
