/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:12:14 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/20 14:14:29 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_CLASS_HPP
# define HUMAN_B_CLASS_HPP

# include <string>
# include "Weapon.class.hpp"

class HumanB
{
	private:
		std::string const	_name;
		Weapon				*_weapon;

	public:
		HumanB(std::string const name);
		~HumanB(void);
		void	attack(void) const;
		void	setWeapon(Weapon &weapon);
};

#endif
