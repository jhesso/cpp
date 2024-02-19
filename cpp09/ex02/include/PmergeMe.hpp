/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 23:37:24 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/20 01:00:44 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <vector>
# include <list>

class PmergeMe
{
	private:
		PmergeMe(void);
		PmergeMe(PmergeMe const & src);
		PmergeMe &	operator=(PmergeMe const & src);

		std::vector<int>	_vec;
		std::list<int>		_list;

		void	sort(char ** av);

		void	validateInput(char **av, std::vector<int> & vec);
		void	validateInput(char **av, std::list<int> & list);
		int		convertStringToInt(std::string str);
		void	checkDuplicates(int const nb, std::vector<int> const & vec);
		void	checkDuplicates(int const nb, std::list<int> const & list);
		void	printContainer(std::vector<int> const & container);
		void	printContainer(std::list<int> const & container);
		void	printTime(std::string type, std::chrono::duration<double, std::micro> time);

		void	sortVec(void);
		void	sortList(void);

	public:
		PmergeMe(char ** av);
		~PmergeMe(void);
};

#endif
