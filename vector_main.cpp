/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_main.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:01:07 by jtaravel          #+#    #+#             */
/*   Updated: 2023/03/17 18:02:50 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/vector.hpp"
#include "includes/reverse_iterator.hpp"
#include "includes/iterator_traits.hpp"
#include <iterator>
#include <iostream>
#include <vector>
#include <stdio.h>


#if STD
	#define NAME_SPACE std
#else
	#define NAME_SPACE ft
#endif

#define TESTED_TYPE int

int	main(void)
{
	srand(time(NULL));
	NAME_SPACE::vector<int>	ft(3, 1);
	NAME_SPACE::vector<int>	ft2(3);
	NAME_SPACE::vector<int>::const_iterator o = ft.begin();
	NAME_SPACE::vector<int>::const_reverse_iterator p(o);

	std::cout << "---------- START push_back test ----------" << std::endl;
	std::cout << std::endl;
	std::cout << "FT stats: " << std::endl;
	std::cout << "actual capacity for ft: " << ft.capacity() << std::endl;
	std::cout << "actual size for ft: " << ft.size() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "ADD number 2: " << std::endl;
	ft.push_back(2);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "FT stats: " << std::endl;
	std::cout << "new capacity for ft: " << ft.capacity() << std::endl;
	std::cout << "new size for ft: " << ft.size() << std::endl;
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
	ft.pop_back();
	ft.pop_back();
	 std::cout << std::endl;
	std::cout << "FT stats: " << std::endl;
	std::cout << "new capacity for ft: " << ft.capacity() << std::endl;
	std::cout << "new size for ft: " << ft.size() << std::endl;
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
	ft.clear();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "FT stats: " << std::endl;
	std::cout << "new capacity for ft: " << ft.capacity() << std::endl;
	std::cout << "new size for ft: " << ft.size() << std::endl;
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
	std::cout << "FT stats: " << std::endl;
	std::cout << "actual capacity for ft: " << ft.capacity() << std::endl;
	std::cout << "actual size for ft: " << ft.size() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "ADD multiple numbers: " << std::endl;
	for (size_t i = 0; i < 10; ++i)
	{
		int nb = (rand() % (1000 + 1));
		ft.push_back(nb);
	}
	ft.push_back(999);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "FT stats: " << std::endl;
	std::cout << "new capacity for ft: " << ft.capacity() << std::endl;
	std::cout << "new size for ft: " << ft.size() << std::endl;
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
	ft.resize(3);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "FT stats: " << std::endl;
	std::cout << "new capacity for ft: " << ft.capacity() << std::endl;
	std::cout << "new size for ft: " << ft.size() << std::endl;
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
	ft.resize(20);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "FT stats: " << std::endl;
	std::cout << "new capacity for ft: " << ft.capacity() << std::endl;
	std::cout << "new size for ft: " << ft.size() << std::endl;
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
	std::cout << "FT max_size: " << ft.max_size() << std::endl;
	std::cout << std::endl;
	std::cout << "---------- END max_size test ----------" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "---------- START swap && at test ----------" << std::endl;
	std::cout << std::endl;
	
	ft.clear();
	NAME_SPACE::vector<int> tmp;
	for (size_t i = 0; i < 5; ++i)
	{
		tmp.push_back(1);
		ft.push_back(2);
	}
	for (size_t i = 0; i < tmp.size(); ++i)
		std::cout << "TMP: " << tmp.at(i) << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < ft.size(); ++i)
		std::cout << "FT: " << ft.at(i) << std::endl;
	std::cout << std::endl;
	std::cout << "SWAPPING !!!" << std::endl;
	ft.swap(tmp);
	std::cout << std::endl;
	for (size_t i = 0; i < tmp.size(); ++i)
		std::cout << "TMP: " << tmp.at(i) << std::endl;
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
		ft.push_back(nb);
	}
	for (size_t i = 0; i < ft.size(); ++i)
		std::cout << "FT: " << ft[i] << std::endl;
	std::cout << std::endl;
	std::cout << "FT FRONT: " << ft.front() << std::endl;
	std::cout << std::endl;
	std::cout << "FT BACK: " << ft.back() << std::endl;

	std::cout << std::endl;
	std::cout << "---------- END front && back test ----------" << std::endl;
	
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	
	std::cout << "---------- START empty test ----------" << std::endl;
	std::cout << std::endl;

	for (size_t i = 0; i < ft.size(); ++i)
		std::cout << "FT: " << ft[i] << std::endl;
	std::cout << std::endl;
	std::cout << "FT empty: " << ft.empty() << std::endl;
	std::cout << std::endl;
	std::cout << "CLEANING: " << std::endl;
	ft.clear();
	std::cout << std::endl;
	std::cout << "FT empty: " << ft.empty() << std::endl;
	
	std::cout << std::endl;
	std::cout << "---------- END empty test ----------" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "---------- START ITERATOR TEST ----------" << std::endl;
	std::cout << std::endl;

	NAME_SPACE::vector<int> lala(1, 1);
	for (size_t i = 0; i < 10; ++i)
	{
		int nb = (rand() % (1000 + 1));
		lala.push_back(nb);
	}
	for (size_t i = 0; i < lala.size(); ++i)
		std::cout << "FT: " << lala[i] << std::endl;
	std::cout << std::endl;
	std::cout << "begin(): " << std::endl;
	std::cout << "FT: " << *lala.begin() << std::endl;
	std::cout << std::endl;
	std::cout << "end(): " << std::endl;
	std::cout << "FT: " << *lala.end() << std::endl;
	std::cout << std::endl;
	std::cout << "rbegin(): " << std::endl;
	std::cout << "FT: " << *lala.rbegin() << std::endl;
	std::cout << std::endl;
	std::cout << "rend(): " << std::endl;
	std::cout << "FT: " << *(lala.rend() + 1) << std::endl;
	std::cout << std::endl;
	std::cout << "insert() 999 at 3 position: " << std::endl;
	lala.insert(lala.begin() + 2, 999);
	std::cout << std::endl;
	for (size_t i = 0; i < lala.size(); ++i)
		std::cout << "FT: " << lala[i] << std::endl;
	std::cout << std::endl;
	std::cout << "erase() the second element: " << std::endl;
	lala.erase(lala.begin() + 1);
	std::cout << std::endl;
	for (size_t i = 0; i < lala.size(); ++i)
		std::cout << "FT: " << lala[i] << std::endl;
	std::cout << std::endl;
	std::cout << "erase() 2 to 8 elements: " << std::endl;
	lala.erase(lala.begin() + 1, lala.begin() + 8);
	std::cout << std::endl;
	for (size_t i = 0; i < lala.size(); ++i)
		std::cout << "FT: " << lala[i] << std::endl;
	std::cout << std::endl;
	std::cout << "insert() 999 2 to 8 positions: " << std::endl;
	lala.insert(lala.begin() + 2, 8, 999);
	std::cout << std::endl;
	for (size_t i = 0; i < lala.size(); ++i)
		std::cout << "FT: " << lala[i] << std::endl;
	std::cout << std::endl;
	std::cout << "assign() 1111 for 5 elements: " << std::endl;
	lala.assign(5, 1111);
	std::cout << std::endl;

}
