/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:34:55 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/07 21:43:49 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(Bureaucrat const & src);
		Bureaucrat(std::string const & name, int grade);
		~Bureaucrat(void);

		Bureaucrat &	operator=(Bureaucrat const & src);

		std::string const &	getName(void) const;
		int					getGrade(void) const;

		void	setGrade(const int grade);

		void	incGrade(void);
		void	incGrade(int grade);
		void	decGrade(void);
		void	decGrade(int grade);

		static int const	highestGrade = 1;
		static int const	lowestGrade = 150;

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *	what(void) const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *	what(void) const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat & bureaucrat);

#endif
