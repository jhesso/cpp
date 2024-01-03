/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:18:13 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/27 20:38:23 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class AAnimal
{
	protected:
		std::string	_type;

	public:
		AAnimal(void);
		AAnimal(AAnimal const & src);
		virtual ~AAnimal(void);

		AAnimal &			operator=(AAnimal const & src);

		virtual void		makeSound(void) const = 0;
};

#endif
