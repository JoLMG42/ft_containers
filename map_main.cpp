/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_main.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:38:12 by jtaravel          #+#    #+#             */
/*   Updated: 2023/03/10 19:29:55 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include "includes/map.hpp"
#include <iostream>
#include <iomanip>
#include "includes/pair.hpp"
#include "includes/make_pair.hpp"

	void	real_print(ft::RBT<ft::map<int, int>::key_type, ft::map<int, int>::mapped_type, ft::map<int, int>::value_type, ft::map<int, int>::key_compare>::Node<int> *ptr, int space, ft::RBT<ft::map<int, int>::key_type, ft::map<int, int>::mapped_type, ft::map<int, int>::value_type, ft::map<int, int>::key_compare> test)
	{
		if (!ptr || ptr == test.getNULL())
		{
			return;
	 	} 
		space += 4;
		real_print(ptr->m_right, space, test);
		std::cout
			<< (ptr->m_color == ft::s_black ? "\033[90m" : "\033[31m") << std::setw(space)
			<< ptr->p->first << "\033[0m" << std::endl;
		// getwchar();
		real_print(ptr->m_left, space, test);
	}

int	main(void)
{
	std::map<int, int> real;
	real.insert(std::make_pair(5, 8));
	real.insert(std::make_pair(1, 3));
	real.insert(std::make_pair(7, 10));
	real.insert(std::make_pair(3, 9));
	real.insert(std::make_pair(4, 11));
	real.insert(std::make_pair(54, 110));
	std::cout << "real begin test (first): " << real.begin()->first << "\n";
	std::cout << "real begin test (second): " << real.begin()->second << "\n";
	ft::map<int, int> ft;
	ft.insert(ft::make_pair(5, 8));
	ft.insert(ft::make_pair(1, 3));
	ft.insert(ft::make_pair(7, 10));
	ft.insert(ft::make_pair(3, 9));
	ft.insert(ft::make_pair(4, 11));
	ft.insert(ft::make_pair(54, 110));
	std::cout << "ft begin test (first): " << ft.begin()->first << "\n";
	std::cout << "ft begin test (second): " << ft.begin()->second << "\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";

	std::map<int,int>::iterator E = real.end();
	ft::map<int,int>::iterator E2 = ft.end();

	E--;
	E2--;

	std::cout << "real end test (first): " << real.end()->first << "\n";
	std::cout << "real end test (second): " << real.end()->second << "\n";
	std::cout << "ft end test (first): " << ft.end()->first << "\n";
	std::cout << "ft end test (second): " << ft.end()->second << "\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "real E (first): " << E->first << "\n";
	std::cout << "real E (second): " << E->second << "\n";
	std::cout << "ft E2 (first): " << E2->first << "\n";
	std::cout << "ft E2 (second): " << E2->second << "\n";
	std::cout << "\n";
	std::cout << "\n";

 	//ft._tree.deleteEndNode(NULL);
//	real_print(ft._tree.getRoot(), 0, ft._tree);

	std::cout << "real equal_range test (first): " << real.equal_range(7).first->first << "\n";
	std::cout << "real equal_range test (first): " << real.equal_range(7).first->second << "\n";
	std::cout << "real equal_range test (first): " << real.equal_range(7).second->first << "\n";
	std::cout << "real equal_range test (first): " << real.equal_range(7).second->second << "\n";
	std::cout << "ft equal_range test (first): " << ft.equal_range(7).first->first << "\n";
	std::cout << "ft equal_range test (first): " << ft.equal_range(7).first->second << "\n";
	std::cout << "ft equal_range test (first): " << ft.equal_range(7).second->first << "\n";
	std::cout << "ft equal_range test (first): " << ft.equal_range(7).second->second << "\n";
	
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";

	std::map<int,int>::iterator it = real.begin();
	ft::map<int,int>::iterator my = ft.begin();
	std::cout << "test: " << it->first << "\n";
	it++;
	it++;
	++it;
	it++;
	it++;
	std::cout << "test ++ : " << it->first << "\n";
	std::cout << "test: " << my->first << "\n";
	my++;
	my++;
	++my;
	my++;
	my++;
	std::cout << "test ++ : " << my->first << "\n";

	it = real.begin();
	it++;
	my = ft.begin();
	my++;
	std::cout << "it = " << it->first << "\n";
	std::cout << "my = " << my->first << "\n";
	std::cout << "Erase it and my\n";
//	real_print(ft._tree.getRoot(), 0, ft._tree);
	std::cout << "PAS COMPRENDRE MOI ROOT->VALUE: " << ft._tree.getRoot() << "\n";
//	real.erase(4);
//	ft.erase(4);
//	real_print(ft._tree.getRoot(), 0, ft._tree);
	it = real.begin();
	my = ft.begin();
	std::cout << "it = " << it->first << "\n";
	std::cout << "my = " << my->first << "\n";
	
	//real.insert(std::make_pair(1, 8));
	//ft.insert(ft::make_pair(1, 8));
	//real.erase(real.begin(), real.end());
	//ft.erase(ft.begin(), ft.end());
	//real_print(ft._tree.getRoot(), 0, ft._tree);

	std::map<int,int>::iterator itlow,itup;
	itlow = real.lower_bound(10000);
	std::cout << "real test lower first: " << itlow->first << "\n";
	std::cout << "real test lower second: " << itlow->second << "\n";
	itlow = real.upper_bound(-10);
	std::cout << "real test upper first: " << itlow->first << "\n";
	std::cout << "real test upper second: " << itlow->second << "\n";

	ft::map<int,int>::iterator itlow2,itup2;
	itlow2 = ft.lower_bound(10000);
	std::cout << "ft test lower first: " << itlow2->first << "\n";
	std::cout << "ft test lower second: " << itlow2->second << "\n";
	itlow2 = ft.upper_bound(-10);
	std::cout << "ft test upper first: " << itlow2->first << "\n";
	std::cout << "ft test upper second: " << itlow2->second << "\n";

	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";

	ft::map<int, int>::iterator pa = ft.begin();
	ft::map<int, int>::iterator po = ft.begin();
	ft::map<int, int>::iterator la = ft.end();

	pa++;

	ft.insert(pa, ft::make_pair(6, 6));
	ft.insert(pa, ft::make_pair(7, 7));
	ft.insert(pa, ft::make_pair(8, 8));
	ft.insert(pa, ft::make_pair(9, 9));
	ft.insert(pa, ft::make_pair(16, 16));
	ft.insert(pa, ft::make_pair(26, 26));
	ft.insert(pa, ft::make_pair(36, 36));
	ft.insert(pa, ft::make_pair(46, 46));
	ft.insert(pa, ft::make_pair(243, 243));
	while (po != la)
	{
		std::cout << "TEST: " << po->second << "\n";
		po++;
	}

	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	po = ft.begin();
	la = ft.end();

	ft[243] = 24;
	//real_print(ft._tree.getRoot(), 0, ft._tree);
	ft.erase(26);

	while (po != la)
	{
		std::cout << "first: " << po->first <<  " second: " << po->second << "\n";
		po++;
	}

	//real_print(ft._tree.getRoot(), 0, ft._tree);

	ft::map<int, int> cpy;
	cpy = ft;
	ft::map<int, int>::iterator s1 = cpy.begin();
	ft::map<int, int>::iterator f1 = cpy.end();


	while (s1 != f1)
	{
		std::cout << "first: " << s1->first <<  " second: " << s1->second << "\n";
		s1++;
	}
	//real_print(cpy._tree.getRoot(), 0, cpy._tree);
	std::cout << "Fin du main\n";
	//ft.clear();
	//real_print(ft._tree.getRoot(), 0, ft._tree);

}
