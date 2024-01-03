/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:22:57 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/28 12:53:12 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

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
