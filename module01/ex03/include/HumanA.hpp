/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:32:38 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/29 12:07:13 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "Weapon.hpp"

class HumanA
{
	private:
		std::string const	_name;
		Weapon const &		_weapon;

	public:
		HumanA(std::string const name, Weapon const &weapon);
		~HumanA(void);

		void		attack(void) const;
};

#endif
