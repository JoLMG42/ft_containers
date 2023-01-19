/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:01:07 by jtaravel          #+#    #+#             */
/*   Updated: 2023/01/19 19:15:28 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <iostream>
#include <vector>

int	main(void)
{
	srand(time(NULL));
	ft::vector<int>	ft(3, 1);
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
	
}
