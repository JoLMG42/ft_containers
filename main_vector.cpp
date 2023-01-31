/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:01:07 by jtaravel          #+#    #+#             */
/*   Updated: 2023/01/27 20:09:52 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "iterator_traits.hpp"
#include <iterator>
#include <iostream>
#include <vector>

int	main(void)
{
	srand(time(NULL));
	ft::vector<int>	ft(3, 1);
	ft::vector<int>	ft2(3);
	ft::vector<int>::iterator p = ft.begin();
	ft::vector<int>::iterator o = ft.end();
	ft::vector<int> ft3(p, o);
	std::vector<int> real(3, 1);

	std::cout << "---------- START push_back test ----------" << std::endl;
	std::cout << std::endl;
	std::cout << "REAL stats: " << std::endl;
	std::cout << "actual capacity for real: " << real.capacity() << std::endl;
	std::cout << "actual size for real: " << real.size() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "FT stats: " << std::endl;
	std::cout << "actual capacity for ft: " << ft.capacity() << std::endl;
	std::cout << "actual size for ft: " << ft.size() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "ADD number 2: " << std::endl;
	real.push_back(2);
	ft.push_back(2);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "REAL stats: " << std::endl;
	std::cout << "new capacity for real: " << real.capacity() << std::endl;
	std::cout << "new size for real: " << real.size() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "FT stats: " << std::endl;
	std::cout << "new capacity for ft: " << ft.capacity() << std::endl;
	std::cout << "new size for ft: " << ft.size() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < real.size(); ++i)
		std::cout << "REAL: " << real[i] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < ft.size(); ++i)
		std::cout << "FT: " << ft[i] << std::endl;
	std::cout << "---------- END push_back test ----------" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "---------- START pop_back test ----------" << std::endl;
	
	std::cout << "remove two last elements: " << std::endl;
	real.pop_back();
	ft.pop_back();
	real.pop_back();
	ft.pop_back();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "REAL stats: " << std::endl;
	std::cout << "new capacity for real: " << real.capacity() << std::endl;
	std::cout << "new size for real: " << real.size() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "FT stats: " << std::endl;
	std::cout << "new capacity for ft: " << ft.capacity() << std::endl;
	std::cout << "new size for ft: " << ft.size() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < real.size(); ++i)
		std::cout << "REAL: " << real[i] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < ft.size(); ++i)
		std::cout << "FT: " << ft[i] << std::endl;
	std::cout << "---------- END pop_back test ----------" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "---------- START clear test ----------" << std::endl;

	std::cout << "cleaning all elements: " << std::endl;
	real.clear();
	ft.clear();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "REAL stats: " << std::endl;
	std::cout << "new capacity for real: " << real.capacity() << std::endl;
	std::cout << "new size for real: " << real.size() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "FT stats: " << std::endl;
	std::cout << "new capacity for ft: " << ft.capacity() << std::endl;
	std::cout << "new size for ft: " << ft.size() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < real.size(); ++i)
		std::cout << "REAL: " << real[i] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < ft.size(); ++i)
		std::cout << "FT: " << ft[i] << std::endl;
	std::cout << "---------- END clear test ----------" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "---------- START push_back test 2 ----------" << std::endl;
	std::cout << std::endl;
	std::cout << "REAL stats: " << std::endl;
	std::cout << "actual capacity for real: " << real.capacity() << std::endl;
	std::cout << "actual size for real: " << real.size() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "FT stats: " << std::endl;
	std::cout << "actual capacity for ft: " << ft.capacity() << std::endl;
	std::cout << "actual size for ft: " << ft.size() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "ADD multiple numbers: " << std::endl;
	for (size_t i = 0; i < 10; ++i)
	{
		int nb = (rand() % (1000 + 1));
		real.push_back(nb);
		ft.push_back(nb);
	}
	real.push_back(999);
	ft.push_back(999);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "REAL stats: " << std::endl;
	std::cout << "new capacity for real: " << real.capacity() << std::endl;
	std::cout << "new size for real: " << real.size() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "FT stats: " << std::endl;
	std::cout << "new capacity for ft: " << ft.capacity() << std::endl;
	std::cout << "new size for ft: " << ft.size() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < real.size(); ++i)
		std::cout << "REAL: " << real[i] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < ft.size(); ++i)
		std::cout << "FT: " << ft[i] << std::endl;
	std::cout << "---------- END push_back test 2 ----------" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "---------- START resize test ----------" << std::endl;
	std::cout << std::endl;
	real.resize(3);
	ft.resize(3);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "REAL stats: " << std::endl;
	std::cout << "new capacity for real: " << real.capacity() << std::endl;
	std::cout << "new size for real: " << real.size() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "FT stats: " << std::endl;
	std::cout << "new capacity for ft: " << ft.capacity() << std::endl;
	std::cout << "new size for ft: " << ft.size() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < real.size(); ++i)
		std::cout << "REAL: " << real[i] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < ft.size(); ++i)
		std::cout << "FT: " << ft[i] << std::endl;
	std::cout << "---------- END resize test ----------" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "---------- START resize test 2 ----------" << std::endl;
	std::cout << std::endl;
	real.resize(20);
	ft.resize(20);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "REAL stats: " << std::endl;
	std::cout << "new capacity for real: " << real.capacity() << std::endl;
	std::cout << "new size for real: " << real.size() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "FT stats: " << std::endl;
	std::cout << "new capacity for ft: " << ft.capacity() << std::endl;
	std::cout << "new size for ft: " << ft.size() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < real.size(); ++i)
		std::cout << "REAL: " << real[i] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < ft.size(); ++i)
		std::cout << "FT: " << ft[i] << std::endl;
	std::cout << "---------- END resize test 2 ----------" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "---------- START max_size test ----------" << std::endl;
	std::cout << std::endl;
	std::cout << "REAL max_size: " << real.max_size() << std::endl;
	std::cout << "FT max_size: " << ft.max_size() << std::endl;
	std::cout << std::endl;
	std::cout << "---------- END max_size test ----------" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "---------- START swap && at test ----------" << std::endl;
	std::cout << std::endl;
	
	real.clear();
	ft.clear();
	ft::vector<int> tmp;
	for (size_t i = 0; i < 5; ++i)
	{
		tmp.push_back(1);
		ft.push_back(2);
	}
	for (size_t i = 0; i < tmp.size(); ++i)
		std::cout << "REAL: " << tmp.at(i) << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < ft.size(); ++i)
		std::cout << "FT: " << ft.at(i) << std::endl;
	std::cout << std::endl;
	std::cout << "SWAPPING !!!" << std::endl;
	ft.swap(tmp);
	std::cout << std::endl;
	for (size_t i = 0; i < tmp.size(); ++i)
		std::cout << "REAL: " << tmp.at(i) << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < ft.size(); ++i)
		std::cout << "FT: " << ft.at(i) << std::endl;
	std::cout << std::endl;
	try
	{
		std::cout << "Try to access index 999: " << ft.at(999) << std::endl;
	}
	catch(std::out_of_range e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "---------- END swap && at test ----------" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	
	std::cout << "---------- START front && back test ----------" << std::endl;
	std::cout << std::endl;

	ft.clear();
	for (size_t i = 0; i < 5; ++i)
	{
		int nb = (rand() % (1000 + 1));
		real.push_back(nb);
		ft.push_back(nb);
	}
	for (size_t i = 0; i < real.size(); ++i)
		std::cout << "REAL: " << real[i] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < ft.size(); ++i)
		std::cout << "FT: " << ft[i] << std::endl;
	std::cout << std::endl;
	std::cout << "REAL FRONT: " << real.front() << std::endl;
	std::cout << std::endl;
	std::cout << "FT FRONT: " << real.front() << std::endl;
	std::cout << std::endl;
	std::cout << "REAL BACK: " << real.back() << std::endl;
	std::cout << std::endl;
	std::cout << "FT BACK: " << real.back() << std::endl;

	std::cout << std::endl;
	std::cout << "---------- END front && back test ----------" << std::endl;
	
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	
	std::cout << "---------- START empty test ----------" << std::endl;
	std::cout << std::endl;

	for (size_t i = 0; i < real.size(); ++i)
		std::cout << "REAL: " << real[i] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < ft.size(); ++i)
		std::cout << "FT: " << ft[i] << std::endl;
	std::cout << std::endl;
	std::cout << "REAL empty: " << real.empty() << std::endl;
	std::cout << std::endl;
	std::cout << "FT empty: " << real.empty() << std::endl;
	std::cout << std::endl;
	std::cout << "CLEANING: " << std::endl;
	real.clear();
	ft.clear();
	std::cout << std::endl;
	std::cout << "REAL empty: " << real.empty() << std::endl;
	std::cout << std::endl;
	std::cout << "FT empty: " << real.empty() << std::endl;
	
	std::cout << std::endl;
	std::cout << "---------- END empty test ----------" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "---------- START ITERATOR TEST ----------" << std::endl;
	std::cout << std::endl;

	std::vector<int> toto(1, 1);
	ft::vector<int> lala(1, 1);
	for (size_t i = 0; i < 10; ++i)
	{
		int nb = (rand() % (1000 + 1));
		toto.push_back(nb);
		lala.push_back(nb);
	}
	//std::vector<int>::iterator rit = toto.begin();
	//ft::vector<int>::iterator ftit = lala.begin();
	for (size_t i = 0; i < toto.size(); ++i)
		std::cout << "REAL: " << toto[i] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < lala.size(); ++i)
		std::cout << "FT: " << lala[i] << std::endl;
	std::cout << std::endl;
	std::cout << "begin(): " << std::endl;
	std::cout << "REAL: " << *toto.begin() << std::endl;
	std::cout << "FT: " << *lala.begin() << std::endl;
	std::cout << std::endl;
	std::cout << "end(): " << std::endl;
	std::cout << "REAL: " << *toto.end() << std::endl;
	std::cout << "FT: " << *lala.end() << std::endl;
	std::cout << std::endl;
	std::cout << "rbegin(): " << std::endl;
	std::cout << "REAL: " << *toto.rbegin() << std::endl;
	std::cout << "FT: " << *lala.rbegin() << std::endl;
	std::cout << std::endl;
	std::cout << "rend(): " << std::endl;
	std::cout << "REAL: " << *(toto.rend() + 1) << std::endl;
	std::cout << "FT: " << *(lala.rend() + 1) << std::endl;
	std::cout << std::endl;
	std::cout << "insert() 999 at 3 position: " << std::endl;
	toto.insert(toto.begin() + 2, 999);
	lala.insert(lala.begin() + 2, 999);
	std::cout << std::endl;
	for (size_t i = 0; i < toto.size(); ++i)
		std::cout << "REAL: " << toto[i] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < lala.size(); ++i)
		std::cout << "FT: " << lala[i] << std::endl;
	std::cout << std::endl;
	std::cout << "erase() the second element: " << std::endl;
	toto.erase(toto.begin() + 1);
	lala.erase(lala.begin() + 1);
	std::cout << std::endl;
	for (size_t i = 0; i < toto.size(); ++i)
		std::cout << "REAL: " << toto[i] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < lala.size(); ++i)
		std::cout << "FT: " << lala[i] << std::endl;
	std::cout << std::endl;
	std::cout << "erase() 2 to 8 elements: " << std::endl;
	toto.erase(toto.begin() + 1, toto.begin() + 8);
	lala.erase(lala.begin() + 1, lala.begin() + 8);
	std::cout << std::endl;
	for (size_t i = 0; i < toto.size(); ++i)
		std::cout << "REAL: " << toto[i] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < lala.size(); ++i)
		std::cout << "FT: " << lala[i] << std::endl;
	std::cout << std::endl;
	std::cout << "insert() 999 2 to 8 positions: " << std::endl;
	toto.insert(toto.begin() + 2, 8, 999);
	lala.insert(lala.begin() + 2, 8, 999);
	std::cout << std::endl;
	for (size_t i = 0; i < toto.size(); ++i)
		std::cout << "REAL: " << toto[i] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < lala.size(); ++i)
		std::cout << "FT: " << lala[i] << std::endl;
	std::cout << std::endl;
	std::cout << "assign() 1111 for 5 elements: " << std::endl;
	toto.assign(5, 1111);
	lala.assign(5, 1111);
	std::cout << std::endl;
	for (size_t i = 0; i < toto.size(); ++i)
		std::cout << "REAL: " << toto[i] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < lala.size(); ++i)
		std::cout << "FT: " << lala[i] << std::endl;
	std::cout << std::endl;
	std::vector<int>::iterator b = toto.begin();
	std::vector<int>::iterator e = toto.end();
	std::vector<int> test(b, e);
	ft::vector<int>::iterator b1 = lala.begin();
	ft::vector<int>::iterator e1 = lala.end();
	ft::vector<int> test1(b1, e1);
	std::cout << std::endl;
	for (size_t i = 0; i < test.size(); ++i)
		std::cout << "REAL: " << test[i] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < test1.size(); ++i)
		std::cout << "FT: " << test1[i] << std::endl;
	std::cout << std::endl;

	*b = *b - 1;
	test.assign(b, e);
	*b1 = *b1 - 1;
	test1.assign(b1, e1);
	std::cout << std::endl;
	for (size_t i = 0; i < test.size(); ++i)
		std::cout << "REAL: " << test[i] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < test1.size(); ++i)
		std::cout << "FT: " << test1[i] << std::endl;
	std::cout << std::endl;
	test.insert(test.begin(), b, e);
	test1.insert(test1.begin(), b1, e1);
	std::cout << std::endl;
	for (size_t i = 0; i < test.size(); ++i)
		std::cout << "REAL: " << test[i] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < test1.size(); ++i)
		std::cout << "FT: " << test1[i] << std::endl;
	std::cout << std::endl;

}
