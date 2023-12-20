/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:22:57 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/20 14:03:53 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_CLASS_HPP
# define WEAPON_CLASS_HPP

# include <string>

class Weapon
{
	private:
		std::string	_type;

	public:
		Weapon(std::string const type);
		~Weapon(void);

		std::string const	&getType(void) const;
		void				setType(std::string const type);
};

#endif
