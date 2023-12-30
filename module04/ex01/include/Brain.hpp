/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:18:16 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/30 19:52:12 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain
{

	public:
		Brain(void);
		Brain(Brain const & src);
		~Brain(void);

		Brain &	operator=(Brain const & src);

		std::string const &	getIdea(int index) const;
		void				setIdea(int index, std::string const & idea);

		static int const	nbIdeas = 100;

	private:
		std::string	_ideas[nbIdeas];
};

#endif
