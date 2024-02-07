/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:54:34 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/08 00:20:55 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		bool				_signed = false;
		int const			_signGrade;
		int const			_executeGrade;

	protected:
		virtual void	beExecuted(void) const = 0;

	public:
		AForm(void);
		AForm(AForm const & src);
		AForm(std::string const & name, int const signGrade, int const executeGrade);
		virtual ~AForm(void);

		AForm &	operator=(AForm const & src);

		std::string const &	getName(void) const;
		bool				getSigned(void) const;
		int					getSignGrade(void) const;
		int					getExecuteGrade(void) const;

		void	beSigned(Bureaucrat const & b);
		void	execute(Bureaucrat const & b) const;

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

		class AlreadySignedException: public std::exception
		{
			public:
				virtual const char *	what(void) const throw();
		};

		class NotSignedException: public std::exception
		{
			public:
				virtual const char *	what(void) const throw();
		};
};

std::ostream &	operator<<(std::ostream & os, AForm const & Form);

#endif
