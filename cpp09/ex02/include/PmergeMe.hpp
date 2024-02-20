/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 23:37:24 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/20 16:48:57 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <vector>
# include <chrono>
# include <deque>

class PmergeMe
{
	private:
		PmergeMe(void);
		PmergeMe(PmergeMe const & src);
		PmergeMe &	operator=(PmergeMe const & src);

		std::vector<int>	_vec;
		std::deque<int>		_deque;

		void	sort(char ** av);

		void	validateInput(char **av, std::vector<int> & vec);
		void	validateInput(char **av, std::deque<int> & deque);
		int		convertStringToInt(std::string str);
		void	checkDuplicates(int const nb, std::vector<int> const & vec);
		void	checkDuplicates(int const nb, std::deque<int> const & deque);
		void	printContainer(std::vector<int> const & container);
		void	printContainer(std::deque<int> const & container);
		void	printTime(std::string type, std::chrono::duration<double, std::micro> time);

		void	sortVec(void);
		std::vector<std::pair<int, int> >	makePairs(std::vector<int> & vec);
		void	sortPairs(std::vector<std::pair<int, int> > & pairs, int len);
		void	sortSequence(std::vector<std::pair<int, int>> & pairs, int straggler);

		void	sortDeque(void);
		std::deque<std::pair<int, int> >	makePairs(std::deque<int> & deque);
		void	sortPairs(std::deque<std::pair<int, int>> & pairs, int len);
		void	sortSequence(std::deque<std::pair<int, int>> & pairs, int straggler);

	public:
		PmergeMe(char ** av);
		~PmergeMe(void);
};

#endif
