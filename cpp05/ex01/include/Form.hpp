/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:54:34 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/07 23:11:35 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		bool				_signed = false;
		int const			_signGrade;
		int const			_executeGrade;

	public:
		Form(void);
		Form(Form const & src);
		Form(std::string const & name, int const signGrade, int const executeGrade);
		~Form(void);

		Form &	operator=(Form const & src);

		std::string const &	getName(void) const;
		bool				getSigned(void) const;
		int					getSignGrade(void) const;
		int					getExecuteGrade(void) const;

		void	beSigned(Bureaucrat const & b);

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
};

std::ostream &	operator<<(std::ostream & os, Form const & Form);

#endif
