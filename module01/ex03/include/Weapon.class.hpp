/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:22:57 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/19 16:31:27 by jhesso           ###   ########.fr       */
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
		Weapon(void);
		Weapon(std::string type);
		~Weapon(void);

		std::string	getType(void);
		void		setType(std::string type);
};

#endif
