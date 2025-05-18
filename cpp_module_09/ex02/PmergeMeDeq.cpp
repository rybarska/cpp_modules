/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:06:50 by arybarsk          #+#    #+#             */
/*   Updated: 2025/02/24 18:06:52 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool PmergeMe::insertNumsIntoDeq(int argc, char **argv, std::deque<int> &deq)
{
	for (int i = 1; i < argc; i++)
	{
		int num;
		if (!isPositiveInt(argv[i], num))
		{
			std::cerr << "Error: invalid input: " << argv[i] << std::endl;
			return (false);
		}
		deq.push_back(num);
	}
	return (true);
}

void PmergeMe::printNumsInDeq(const std::deque<int> deq)
{
	for (size_t i = 0; i < deq.size(); i++)
	{
		std::cout << deq[i];
		if (i + 1 < deq.size())
			std::cout << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printDeqsInDeq(const std::deque< std::deque<int> > deq)
{
	for (size_t i = 0; i < deq.size(); i++)
	{
		std::cout << "{" ;
		for (size_t j = 0; j < deq[i].size(); j++)
		{
			std::cout << deq[i][j];
			if (j + 1 < deq[i].size())
				std::cout << " ";
		}
		std::cout << "}" ;
		if (i + 1 < deq.size())
			std::cout << ", ";
	}
	std::cout << std::endl;
}

void PmergeMe::binarySearchSingleDeq(std::deque<int> deq, int num, int &pos, int &counterD)
{
	size_t first = 0;
	size_t last = deq.size() - 1;
	if (deq.empty() || first > last)
		return ;
	while (first <= last)
	{
		size_t threshold = first + (last - first) / 2;
		counterD++;
		if (num == deq[threshold])
		{
			pos = threshold;
			return ;
		}
		else if (num < deq[threshold])
		{
			if (threshold == 0)
				break ;
			last = threshold - 1;
		}
		else
			first = threshold + 1;
	}
	pos = first;
}

void PmergeMe::binarySearchDeqs(std::deque< std::deque<int> > deqOfDeqs, int num, int &pos, int &counterD)
{
	if (deqOfDeqs.empty())
		return ;
	size_t first = 0;
	size_t last = deqOfDeqs.size() - 1;
	while (first <= last)
	{
		size_t threshold = first + (last - first) / 2;
		counterD++;
		if (!deqOfDeqs[threshold].empty() && num == deqOfDeqs[threshold].front())
		{
			pos = threshold;
			return ;
		}
		else if (!deqOfDeqs[threshold].empty() && num < deqOfDeqs[threshold].front())
		{
			if (threshold == 0)
				break ;
			last = threshold - 1;
		}
		else
			first = threshold + 1;
	}
	pos = first;
}

void PmergeMe::doUnpairedLastRowDeq(std::deque<int> &inputDeq, std::deque<int> &resultDeq, int pos, int &counter, bool &unpairedDone)
{
	binarySearchSingleDeq(resultDeq, inputDeq.back(), pos, counter);
	unpairedDone = true;
	if (static_cast<size_t>(pos) <= resultDeq.size())
		resultDeq.insert(resultDeq.begin() + pos, inputDeq.back());
}

void PmergeMe::doUnpairedDeq(std::deque< std::deque<int> > &deqOfDeqs, std::deque<std::deque< std::deque<int> > > &deq3D, size_t range, size_t *n, int pos, int &counter, bool &unpairedDone)
{
	binarySearchDeqs(deqOfDeqs, deq3D[range - *n].back().front(), pos, counter);
	unpairedDone = true;
	if (static_cast<size_t>(pos) <= deqOfDeqs.size())
		deqOfDeqs.insert(deqOfDeqs.begin() + pos, deq3D[range - *n].back());
}

void PmergeMe::mergeLastRowDeq(std::deque<int> &inputDeq, std::deque<int> &resultDeq, std::deque<std::deque< std::deque<int> > > &deq3D, int &counter)
{
	size_t span = deq3D.size();
	
	int JS = 1;
	int k = 1;
	size_t prevB = 0;
	size_t nextB = 0;
	int pos = 0;
	bool unpairedDone = false;
	
	resultDeq.push_back(inputDeq[deq3D.back().front().back()]);
	for (size_t i = 0; i < deq3D[span - 1].size(); i++)
		resultDeq.push_back(deq3D[span - 1][i].front());
	size_t sizeOfA = resultDeq.size() - 1;
	if (deq3D[span - 1].size() - 1 == 0 && inputDeq.size() % 2 != 0)
		doUnpairedLastRowDeq(inputDeq, resultDeq, pos, counter, unpairedDone);
	while (nextB < deq3D[span - 1].size() - 1)
	{
		getNextJacobstahl(k, JS);
		prevB = nextB;
		nextB = fmin(deq3D[span - 1].size() - 1, JS - 1);

		if (nextB == deq3D[span - 1].size() - 1 && static_cast<size_t>(JS) - 1 > nextB && inputDeq.size() % 2 != 0)
			doUnpairedLastRowDeq(inputDeq, resultDeq, pos, counter, unpairedDone);
		
		for (size_t i = nextB; i > prevB; i--)
		{
			size_t border = sizeOfA - i;
			std::deque<int> subDeq(resultDeq.begin(), resultDeq.end() - border);
			binarySearchSingleDeq(subDeq, inputDeq[deq3D.back()[i].back()], pos, counter);
			if (static_cast<size_t>(pos) <= resultDeq.size())
				resultDeq.insert(resultDeq.begin() + pos, inputDeq[deq3D.back()[i].back()]);
		}
	}
	if (!unpairedDone && inputDeq.size() % 2 != 0)
		doUnpairedLastRowDeq(inputDeq, resultDeq, pos, counter, unpairedDone);
}

void PmergeMe::mergeFurtherDeq(std::deque<std::deque< std::deque<int> > > &deq3D, size_t range, size_t *n, int &counter)
{
	(*n)++;
	std::deque< std::deque<int> > deqOfDeqs;
	size_t span = deq3D.size();
	
	int JS = 1;
	int k = 1;
	size_t prevB = 0;
	size_t nextB = 0;
	int pos = 0;
	bool unpairedDone = false;
	
	//insert the pair of first num, before you insert the num and the rest:
	deqOfDeqs.push_back(deq3D[range - *n][deq3D.back().front().back()]);
	deqOfDeqs.insert(deqOfDeqs.end(), deq3D[span - 1].begin(), deq3D[span - 1].end());
	size_t sizeOfA = deqOfDeqs.size() - 1;
	if (deq3D[span - 1].size() - 1 == 0 && deq3D[range - *n].size() % 2 != 0)
		doUnpairedDeq(deqOfDeqs, deq3D, range, n, pos, counter, unpairedDone);
	while (nextB < deq3D[span - 1].size() - 1)
	{
		getNextJacobstahl(k, JS);
		prevB = nextB;
		nextB = fmin(deq3D[span - 1].size() - 1, JS - 1);
	
		//pop the last indices:
		for (size_t i = 0; i < deqOfDeqs.size(); i++)
		{
			if (deqOfDeqs[i].size() > range - *n + 2)
				deqOfDeqs[i].pop_back();
		}
		
		if (nextB == deq3D[span - 1].size() - 1 && static_cast<size_t>(JS) - 1 > nextB && deq3D[range - *n].size() % 2 != 0)
			doUnpairedDeq(deqOfDeqs, deq3D, range, n, pos, counter, unpairedDone);
		
		for (size_t i = nextB; i > prevB; i--)
		{
			size_t border = sizeOfA - i;
			std::deque< std::deque<int> > subDeq(deqOfDeqs.begin(), deqOfDeqs.end() - border);
			binarySearchDeqs(subDeq, deq3D[range - *n][deq3D.back()[i].back()].front(), pos, counter);
			if (static_cast<size_t>(pos) <= deqOfDeqs.size())
				deqOfDeqs.insert(deqOfDeqs.begin() + pos, deq3D[range - *n][deq3D[span - 1][i].back()]);
		}
	}
	if (!unpairedDone && deq3D[range - *n].size() % 2 != 0)
		doUnpairedDeq(deqOfDeqs, deq3D, range, n, pos, counter, unpairedDone);
	deq3D.push_back(deqOfDeqs);
	
	if (range > *n)
		mergeFurtherDeq(deq3D, range, n, counter);
}

void PmergeMe::startMergingDeq(std::deque<std::deque< std::deque<int> > > &deq3D, size_t range, size_t *n, int &counterD)
{
	std::deque< std::deque<int> > deqOfDeqs;
	size_t newSize = deq3D[range - *n].size();

	deqOfDeqs.push_back(deq3D[range - *n][deq3D.back().back().back()]);
	deqOfDeqs.push_back(deq3D.back().back());
	deqOfDeqs.back().pop_back();

	if (newSize > 2)
	{
		 counterD++;
		 if (deq3D[range - *n].back().front() > deqOfDeqs.back().front())
		 	deqOfDeqs.push_back(deq3D[range - *n].back()); 	
		 else if (deq3D[range - *n].back().front() < deqOfDeqs.front().front())
		 	deqOfDeqs.insert(deqOfDeqs.begin(), deq3D[range - *n].back());
		 else
		 	deqOfDeqs.insert(deqOfDeqs.begin() + 1, deq3D[range - *n].back());
	}
	
	deq3D.push_back(deqOfDeqs);
	
	if (range > *n)
		mergeFurtherDeq(deq3D, range, n, counterD);
}

void PmergeMe::segregateFurtherDeq(std::deque<std::deque< std::deque<int> > > &deq3D, int &counterD)
{
	if (deq3D.empty() || deq3D[0].empty() || deq3D[0].size() <= 1
		|| deq3D[deq3D.size() - 1].size() <= 1)
		return ;
	
	std::deque< std::deque<int> > deqOfDeqs;
	size_t oldSize = deq3D.back().size();
	if (oldSize <= 1)
		return ;
	size_t newSize = oldSize / 2;
	
	for (size_t i = 0; i < newSize; i++)
		deqOfDeqs.push_back(std::deque<int>());
	
	size_t idxCount = 0;

	for (size_t i = 0; i < oldSize - 1; i += 2)
	{
		counterD++;
		if (deq3D.back()[i][0] < deq3D.back()[i + 1][0])
		{
			deqOfDeqs[idxCount].insert(deqOfDeqs[idxCount].end(), deq3D.back()[i + 1].begin(), deq3D.back()[i + 1].end());
			deqOfDeqs[idxCount].push_back(i);
		}
		else
		{
			deqOfDeqs[idxCount].insert(deqOfDeqs[idxCount].end(), deq3D.back()[i].begin(), deq3D[deq3D.size() - 1][i].end());
			deqOfDeqs[idxCount].push_back(i + 1);
		}
		idxCount++;
	}
	
	deq3D.push_back(deqOfDeqs);

	if (deqOfDeqs.size() > 1)
		segregateFurtherDeq(deq3D, counterD);
}

void PmergeMe::startSegregatingDeq(std::deque<int> &deq, std::deque<std::deque< std::deque<int> > > &deq3D, int &counterD)
{
	if (deq.size() <= 1)
		return ;
	
	std::deque< std::deque<int> > deqOfDeqs;
	
	for (size_t i = 0; i < deq.size() / 2; i++)
		deqOfDeqs.push_back(std::deque<int>());
	
	int idxCount = 0;
	
	for (size_t i = 0; i < deq.size() - 1; i += 2)
	{
		counterD++;
		if (deq[i] < deq[i + 1])
		{
			deqOfDeqs[idxCount].push_back(deq[i + 1]);
			deqOfDeqs[idxCount].push_back(i);
		}
		else
		{
			deqOfDeqs[idxCount].push_back(deq[i]);
			deqOfDeqs[idxCount].push_back(i + 1);
		}
		idxCount++;
	}
	
	deq3D.push_back(deqOfDeqs);
	
	if (deqOfDeqs.size() > 1)
		segregateFurtherDeq(deq3D, counterD);
}

int PmergeMe::processInDeq(int argc, char **argv)
{
	if (!isArgcValid(argc))
			return (1);
	
	if (!insertNumsIntoDeq(argc, argv, inputDeq))
		return (1);
	//std::cout << "Before: ";
	//printNumsInDeq(inputDeq);
	
	int counterD = 0;
	
	std::clock_t startDeq = clock();
	
	if (argc > 2)
	{
		startSegregatingDeq(inputDeq, deq3D, counterD);
		
		size_t range = deq3D.size();
		
		size_t n = 2;
		
		if (range >= n)
			startMergingDeq(deq3D, range, &n, counterD);
		//for (size_t i = 0; i < deq3D.size(); i++)
		//	printDeqsInDeq(deq3D[i]);
		
		mergeLastRowDeq(inputDeq, resultDeq, deq3D, counterD);
	}
	else
		resultDeq = inputDeq;
	
	std::clock_t endDeq = clock();
	double sortingTime = 1000.0 * (endDeq - startDeq) / CLOCKS_PER_SEC;
	
	//std::cout << "After: ";
	//printNumsInDeq(resultDeq);
	
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : " << sortingTime << " ms" << std::endl;
	
	//std::cout << "Comparisons for deque: " << counterD << std::endl;
	return (0);
}
