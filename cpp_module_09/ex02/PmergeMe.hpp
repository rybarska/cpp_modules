/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:06:40 by arybarsk          #+#    #+#             */
/*   Updated: 2025/02/24 18:06:43 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <exception>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <ctime>


class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &source);
		PmergeMe & operator = (const PmergeMe &source);
		~PmergeMe();

		int processInVec(int argc, char **argv);
		int processInDeq(int argc, char **argv);
	private:
		bool isArgcValid(int argc);
		bool isPositiveInt(const std::string &str, int &num);
		void getNextJacobstahl(int &k, int &JS);
		
		std::vector<int> inputVec;
		std::vector<int> resultVec;
		std::vector<std::vector< std::vector<int> > > vec3D;
		
		bool insertNumsIntoVec(int argc, char **argv, std::vector<int> &vec);
		void printNumsInVec(const std::vector<int> vec);
		void printVecsInVec(const std::vector< std::vector<int> > vec);
		void binarySearchSingleVec(std::vector<int> vec, int num, int &pos, int &counter);
		void binarySearchVecs(std::vector< std::vector<int> > vecOfVecs, int num, int &pos, int &counter);
		void mergeLastRowVec(std::vector<int> &inputVec, std::vector<int> &resultVec, std::vector<std::vector< std::vector<int> > > &vec3D, int &counter);
		void mergeFurtherVec(std::vector<std::vector< std::vector<int> > > &vec3D, size_t range, size_t *n, int &counter);
		void startMergingVec(std::vector<std::vector< std::vector<int> > > &vec3D, size_t range, size_t *n, int &counter);
		void segregateFurtherVec(std::vector<std::vector< std::vector<int> > > &vec3D, int &counter);
		void startSegregatingVec(std::vector<int> &vec, std::vector<std::vector< std::vector<int> > > &vec3D, int &counter);
		void doUnpairedLastRowVec(std::vector<int> &inputVec, std::vector<int> &resultVec, int pos, int &counter, bool &unpairedDone);
		void doUnpairedVec(std::vector< std::vector<int> > &vecOfVecs, std::vector<std::vector< std::vector<int> > > &vec3D, size_t range, size_t *n, int pos, int &counter, bool &unpairedDone);
		
		std::deque<int> inputDeq;
		std::deque<int> resultDeq;
		std::deque<std::deque< std::deque<int> > > deq3D;
		
		bool insertNumsIntoDeq(int argc, char **argv, std::deque<int> &deq);
		void printNumsInDeq(const std::deque<int> deq);
		void printDeqsInDeq(const std::deque< std::deque<int> > deq);
		void binarySearchSingleDeq(std::deque<int> deq, int num, int &pos, int &counter);
		void binarySearchDeqs(std::deque< std::deque<int> > deqOfDeqs, int num, int &pos, int &counter);
		void mergeLastRowDeq(std::deque<int> &inputDeq, std::deque<int> &resultDeq, std::deque<std::deque< std::deque<int> > > &deq3D, int &counter);
		void mergeFurtherDeq(std::deque<std::deque< std::deque<int> > > &deq3D, size_t range, size_t *n, int &counter);
		void startMergingDeq(std::deque<std::deque< std::deque<int> > > &deq3D, size_t range, size_t *n, int &counter);
		void segregateFurtherDeq(std::deque<std::deque< std::deque<int> > > &deq3D, int &counter);
		void startSegregatingDeq(std::deque<int> &deq, std::deque<std::deque< std::deque<int> > > &deq3D, int &counter);
		void doUnpairedLastRowDeq(std::deque<int> &inputDeq, std::deque<int> &resultDeq, int pos, int &counter, bool &unpairedDone);
		void doUnpairedDeq(std::deque< std::deque<int> > &deqOfDeqs, std::deque<std::deque< std::deque<int> > > &deq3D, size_t range, size_t *n, int pos, int &counter, bool &unpairedDone);
};


class tooManyArgsException: public std::exception
{
	public:
		const char* what() const throw();
};

#endif
