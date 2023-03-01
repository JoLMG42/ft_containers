/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:34:21 by jtaravel          #+#    #+#             */
/*   Updated: 2023/03/01 16:29:27 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/map.hpp"
#include <list>
#include <map>

#define TESTED_NAMESPACE ft
#define T1 int
#define T2 int

typedef TESTED_NAMESPACE::map<T1, T2>::value_type T3;
typedef std::map<T1, T2>::value_type T4;

int	main(void)
{

	std::list<T4> lst1;
	lst1.push_back(T4(1, 1));
	lst1.push_back(T4(2, 2));
	lst1.push_back(T4(3, 3));
	lst1.push_back(T4(4, 4));
	lst1.push_back(T4(5, 5));


	std::list<T3> lst;
	lst.push_back(T3(1, 1));
	lst.push_back(T3(2, 2));
	lst.push_back(T3(3, 3));
	lst.push_back(T3(4, 4));
	lst.push_back(T3(5, 5));


	std::map<int, int> real(lst1.begin(), lst1.end());
	std::map<int, int>::iterator rl1 = real.begin();
	std::map<int, int>::iterator rl2 = real.end();

	ft::map<int, int> map(lst.begin(), lst.end());
	ft::map<int, int>::iterator it1 = map.begin();
	ft::map<int, int>::iterator it2 = map.end();


	std::cout << "REAL MAIN BEGIN: " << rl1->first << "\n";
	std::cout << "REAL MAIN END: " << rl2->first << "\n";


	std::cout << "MAIN BEGIN: " << it1->first << "\n";
	std::cout << "MAIN END: " << it2->first << "\n";


	while (rl1 != rl2)
	{
		std::cout << "LE VRAIII: " << rl1->first << "\n";
		rl1++;
	}

	while (it1 != it2)
	{
		std::cout << "A MOIIIII: " << it1->first << "\n";
		++it1;
	}
}
