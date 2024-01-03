/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:15:41 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/27 17:19:26 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

# define FRAGTRAP_DEFAULT_HP 100
# define FRAGTRAP_DEFAULT_ENERGY 100
# define FRAGTRAP_DEFAULT_AD 30

class FragTrap : public ClapTrap
{
	private:
		FragTrap(void);

	public:
		FragTrap(std::string & name);
		FragTrap(FragTrap const & src);
		~FragTrap(void);

		FragTrap &	operator=(FragTrap const & src);

		void	highFivesGuys(void);
};

#endif
