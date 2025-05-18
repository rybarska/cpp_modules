/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVec.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 19:38:43 by arybarsk          #+#    #+#             */
/*   Updated: 2025/03/22 19:38:49 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool PmergeMe::insertNumsIntoVec(int argc, char **argv, std::vector<int> &vec)
{
	for (int i = 1; i < argc; i++)
	{
		int num;
		if (!isPositiveInt(argv[i], num))
		{
			std::cerr << "Error: invalid input: " << argv[i] << std::endl;
			return (false);
		}
		vec.push_back(num);
	}
	return (true);
}

void PmergeMe::printNumsInVec(const std::vector<int> vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i];
		if (i + 1 < vec.size())
			std::cout << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printVecsInVec(const std::vector< std::vector<int> > vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << "{" ;
		for (size_t j = 0; j < vec[i].size(); j++)
		{
			std::cout << vec[i][j];
			if (j + 1 < vec[i].size())
				std::cout << " ";
		}
		std::cout << "}" ;
		if (i + 1 < vec.size())
			std::cout << ", ";
	}
	std::cout << std::endl;
}

void PmergeMe::binarySearchSingleVec(std::vector<int> vec, int num, int &pos, int &counter)
{
	size_t first = 0;
	size_t last = vec.size() - 1;
	if (vec.empty() || first > last)
		return ;
	while (first <= last)
	{
		size_t threshold = first + (last - first) / 2;
		counter++;
		if (num == vec[threshold])
		{
			pos = threshold;
			return ;
		}
		else if (num < vec[threshold])
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

void PmergeMe::binarySearchVecs(std::vector< std::vector<int> > vecOfVecs, int num, int &pos, int &counter)
{
	if (vecOfVecs.empty())
		return ;
	size_t first = 0;
	size_t last = vecOfVecs.size() - 1;
	while (first <= last)
	{
		size_t threshold = first + (last - first) / 2;
		counter++;
		if (!vecOfVecs[threshold].empty() && num == vecOfVecs[threshold].front())
		{
			pos = threshold;
			return ;
		}
		else if (!vecOfVecs[threshold].empty() && num < vecOfVecs[threshold].front())
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

void PmergeMe::doUnpairedLastRowVec(std::vector<int> &inputVec, std::vector<int> &resultVec, int pos, int &counter, bool &unpairedDone)
{
	binarySearchSingleVec(resultVec, inputVec.back(), pos, counter);
	unpairedDone = true;
	if (static_cast<size_t>(pos) <= resultVec.size())
		resultVec.insert(resultVec.begin() + pos, inputVec.back());
}

void PmergeMe::doUnpairedVec(std::vector< std::vector<int> > &vecOfVecs, std::vector<std::vector< std::vector<int> > > &vec3D, size_t range, size_t *n, int pos, int &counter, bool &unpairedDone)
{
	binarySearchVecs(vecOfVecs, vec3D[range - *n].back().front(), pos, counter);
	unpairedDone = true;
	if (static_cast<size_t>(pos) <= vecOfVecs.size())
		vecOfVecs.insert(vecOfVecs.begin() + pos, vec3D[range - *n].back());
}

void PmergeMe::mergeLastRowVec(std::vector<int> &inputVec, std::vector<int> &resultVec, std::vector<std::vector< std::vector<int> > > &vec3D, int &counter)
{
	size_t span = vec3D.size();
	
	int JS = 1;
	int k = 1;
	size_t prevB = 0;
	size_t nextB = 0;
	int pos = 0;
	bool unpairedDone = false;
	
	resultVec.push_back(inputVec[vec3D.back().front().back()]);
	for (size_t i = 0; i < vec3D[span - 1].size(); i++)
		resultVec.push_back(vec3D[span - 1][i].front());
	size_t sizeOfA = resultVec.size() - 1;
	if (vec3D[span - 1].size() - 1 == 0 && inputVec.size() % 2 != 0)
		doUnpairedLastRowVec(inputVec, resultVec, pos, counter, unpairedDone);
	while (nextB < vec3D[span - 1].size() - 1)
	{
		getNextJacobstahl(k, JS);
		prevB = nextB;
		nextB = fmin(vec3D[span - 1].size() - 1, JS - 1);

		if (nextB == vec3D[span - 1].size() - 1 && static_cast<size_t>(JS) - 1 > nextB && inputVec.size() % 2 != 0)
			doUnpairedLastRowVec(inputVec, resultVec, pos, counter, unpairedDone);
		
		for (size_t i = nextB; i > prevB; i--)
		{
			size_t border = sizeOfA - i;
			std::vector<int> subVec(resultVec.begin(), resultVec.end() - border);
			binarySearchSingleVec(subVec, inputVec[vec3D.back()[i].back()], pos, counter);
			if (static_cast<size_t>(pos) <= resultVec.size())
				resultVec.insert(resultVec.begin() + pos, inputVec[vec3D.back()[i].back()]);
		}
	}
	if (!unpairedDone && inputVec.size() % 2 != 0)
		doUnpairedLastRowVec(inputVec, resultVec, pos, counter, unpairedDone);
}

void PmergeMe::mergeFurtherVec(std::vector<std::vector< std::vector<int> > > &vec3D, size_t range, size_t *n, int &counter)
{
	(*n)++;
	std::vector< std::vector<int> > vecOfVecs;
	size_t span = vec3D.size();
	
	int JS = 1;
	int k = 1;
	size_t prevB = 0;
	size_t nextB = 0;
	int pos = 0;
	bool unpairedDone = false;
	
	//insert the pair of first num, before you insert the num and the rest:
	vecOfVecs.push_back(vec3D[range - *n][vec3D.back().front().back()]);
	vecOfVecs.insert(vecOfVecs.end(), vec3D[span - 1].begin(), vec3D[span - 1].end());
	size_t sizeOfA = vecOfVecs.size() - 1;
	if (vec3D[span - 1].size() - 1 == 0 && vec3D[range - *n].size() % 2 != 0)
		doUnpairedVec(vecOfVecs, vec3D, range, n, pos, counter, unpairedDone);
	while (nextB < vec3D[span - 1].size() - 1)
	{
		getNextJacobstahl(k, JS);
		prevB = nextB;
		nextB = fmin(vec3D[span - 1].size() - 1, JS - 1);
	
		//pop the last indices:
		for (size_t i = 0; i < vecOfVecs.size(); i++)
		{
			if (vecOfVecs[i].size() > range - *n + 2)
				vecOfVecs[i].pop_back();
		}
		
		if (nextB == vec3D[span - 1].size() - 1 && static_cast<size_t>(JS) - 1 > nextB && vec3D[range - *n].size() % 2 != 0)
			doUnpairedVec(vecOfVecs, vec3D, range, n, pos, counter, unpairedDone);
		
		for (size_t i = nextB; i > prevB; i--)
		{
			size_t border = sizeOfA - i;
			std::vector< std::vector<int> > subVec(vecOfVecs.begin(), vecOfVecs.end() - border);
			binarySearchVecs(subVec, vec3D[range - *n][vec3D.back()[i].back()].front(), pos, counter);
			if (static_cast<size_t>(pos) <= vecOfVecs.size())
				vecOfVecs.insert(vecOfVecs.begin() + pos, vec3D[range - *n][vec3D[span - 1][i].back()]);
		}
	}
	if (!unpairedDone && vec3D[range - *n].size() % 2 != 0)
		doUnpairedVec(vecOfVecs, vec3D, range, n, pos, counter, unpairedDone);
	vec3D.push_back(vecOfVecs);
	
	if (range > *n)
		mergeFurtherVec(vec3D, range, n, counter);
}

void PmergeMe::startMergingVec(std::vector<std::vector< std::vector<int> > > &vec3D, size_t range, size_t *n, int &counter)
{
	std::vector< std::vector<int> > vecOfVecs;
	size_t newSize = vec3D[range - *n].size();

	vecOfVecs.push_back(vec3D[range - *n][vec3D.back().back().back()]);
	vecOfVecs.push_back(vec3D.back().back());
	vecOfVecs.back().pop_back();

	if (newSize > 2)
	{
		 counter++;
		 if (vec3D[range - *n].back().front() > vecOfVecs.back().front())
		 	vecOfVecs.push_back(vec3D[range - *n].back()); 	
		 else if (vec3D[range - *n].back().front() < vecOfVecs.front().front())
		 	vecOfVecs.insert(vecOfVecs.begin(), vec3D[range - *n].back());
		 else
		 	vecOfVecs.insert(vecOfVecs.begin() + 1, vec3D[range - *n].back());
	}
	
	vec3D.push_back(vecOfVecs);
	
	if (range > *n)
		mergeFurtherVec(vec3D, range, n, counter);
}

void PmergeMe::segregateFurtherVec(std::vector<std::vector< std::vector<int> > > &vec3D, int &counter)
{
	if (vec3D.empty() || vec3D[0].empty() || vec3D[0].size() <= 1
		|| vec3D[vec3D.size() - 1].size() <= 1)
		return ;
	
	std::vector< std::vector<int> > vecOfVecs;
	size_t oldSize = vec3D.back().size();
	if (oldSize <= 1)
		return ;
	size_t newSize = oldSize / 2;
	
	vecOfVecs.reserve(newSize);
	
	for (size_t i = 0; i < newSize; i++)
		vecOfVecs.push_back(std::vector<int>());
	
	size_t idxCount = 0;

	for (size_t i = 0; i < oldSize - 1; i += 2)
	{
		counter++;
		if (vec3D.back()[i][0] < vec3D.back()[i + 1][0])
		{
			vecOfVecs[idxCount].insert(vecOfVecs[idxCount].end(), vec3D.back()[i + 1].begin(), vec3D.back()[i + 1].end());
			vecOfVecs[idxCount].push_back(i);
		}
		else
		{
			vecOfVecs[idxCount].insert(vecOfVecs[idxCount].end(), vec3D.back()[i].begin(), vec3D[vec3D.size() - 1][i].end());
			vecOfVecs[idxCount].push_back(i + 1);
		}
		idxCount++;
	}
	
	vec3D.push_back(vecOfVecs);

	if (vecOfVecs.size() > 1)
		segregateFurtherVec(vec3D, counter);
}

void PmergeMe::startSegregatingVec(std::vector<int> &vec, std::vector<std::vector< std::vector<int> > > &vec3D, int &counter)
{
	if (vec.size() <= 1)
		return ;
	
	std::vector< std::vector<int> > vecOfVecs;
	
	for (size_t i = 0; i < vec.size() / 2; i++)
		vecOfVecs.push_back(std::vector<int>());
	
	int idxCount = 0;
	
	for (size_t i = 0; i < vec.size() - 1; i += 2)
	{
		counter++;
		if (vec[i] < vec[i + 1])
		{
			vecOfVecs[idxCount].push_back(vec[i + 1]);
			vecOfVecs[idxCount].push_back(i);
		}
		else
		{
			vecOfVecs[idxCount].push_back(vec[i]);
			vecOfVecs[idxCount].push_back(i + 1);
		}
		idxCount++;
	}
	
	vec3D.push_back(vecOfVecs);
	
	if (vecOfVecs.size() > 1)
		segregateFurtherVec(vec3D, counter);
}

int PmergeMe::processInVec(int argc, char **argv)
{
	if (!isArgcValid(argc))
			return (1);
	
	if (!insertNumsIntoVec(argc, argv, inputVec))
		return (1);
	std::cout << "Before: ";
	printNumsInVec(inputVec);
	
	int counter = 0;
	
	std::clock_t start = clock();
	
	if (argc > 2)
	{
		startSegregatingVec(inputVec, vec3D, counter);
		
		size_t range = vec3D.size();
		
		size_t n = 2;
		
		if (range >= n)
			startMergingVec(vec3D, range, &n, counter);
		//for (size_t i = 0; i < vec3D.size(); i++)
		//	printVecsInVec(vec3D[i]);
		
		mergeLastRowVec(inputVec, resultVec, vec3D, counter);
	}
	else
		resultVec = inputVec;
	
	std::clock_t end = clock();
	double sortingTime = 1000.0 * (end - start) / CLOCKS_PER_SEC;
	
	std::cout << "After: ";
	printNumsInVec(resultVec);
	
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << sortingTime << " ms" << std::endl;
	
	//std::cout << "Comparisons for vector: " << counter << std::endl;
	return (0);
}
