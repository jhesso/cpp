/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:25:34 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/27 17:00:59 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

# define SCAVTRAP_DEFAULT_HP 100
# define SCAVTRAP_DEFAULT_ENERGY 50
# define SCAVTRAP_DEFAULT_AD 20

class ScavTrap : public ClapTrap
{
	private:
		ScavTrap(void);

	public:
		ScavTrap(std::string & name);
		ScavTrap(ScavTrap const & src);
		~ScavTrap(void);

		ScavTrap &	operator=(ScavTrap const & src);

		void		attack(std::string const & target);
		void		guardGate(void);
};

#endif
