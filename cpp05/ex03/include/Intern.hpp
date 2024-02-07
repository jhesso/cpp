/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 00:54:38 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/08 00:59:42 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		typedef struct	sFormList
		{
			std::string const & name;
			AForm *	(*function)(std::string const &);
		}	formList;

	public:
		Intern(void);
		Intern(Intern const & src);
		~Intern(void);

		Intern &	operator=(Intern const & src);

		AForm *	makeForm(std::string name, std::string target);

		class InvalidFormName : public std::exception
		{
			public:
				virtual const char *	what(void) const throw();
		};
};

#endif
