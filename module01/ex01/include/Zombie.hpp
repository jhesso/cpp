/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:39:03 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/28 12:46:57 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	private:
		std::string	_name;

		std::string	_getName(void);

	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);

		void		announce(void);
		void		setName(std::string name);
};

#endif
