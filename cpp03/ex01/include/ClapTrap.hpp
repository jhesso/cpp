/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:12:46 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/27 16:33:29 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap
{
	protected:
		std::string		_name;
		unsigned int	_hp;
		unsigned int	_energy;
		unsigned int	_ad;

	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & src);
		~ClapTrap(void);

		ClapTrap &	operator=(ClapTrap const & src);

		std::string		getName(void) const;
		unsigned int	getHp(void) const;
		unsigned int	getEnergy(void) const;
		unsigned int	getAd(void) const;

		void	attack(const std::string & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
