/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:32:38 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/20 14:09:30 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_CLASS_HPP
# define HUMANA_CLASS_HPP

# include <string>
# include "Weapon.class.hpp"

class HumanA
{
	private:
		std::string const	_name;
		Weapon const		&_weapon;

	public:
		HumanA(std::string const name, Weapon const &weapon);
		~HumanA(void);

		void		attack(void) const;
};

#endif
