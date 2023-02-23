/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_main.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:38:12 by jtaravel          #+#    #+#             */
/*   Updated: 2023/02/23 19:27:10 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include "includes/map.hpp"
#include <iostream>
#include "includes/pair.hpp"
#include "includes/make_pair.hpp"

int	main(void)
{
	std::map<int, int> real;
	real.insert(std::make_pair(1, 8));
	real.insert(std::make_pair(2, 9));
	real.insert(std::make_pair(3, 10));
	real.insert(std::make_pair(4, 11));
	real.insert(std::make_pair(0, 3));
	std::cout << "real begin test (first): " << real.begin()->first << "\n";
	std::cout << "real begin test (second): " << real.begin()->second << "\n";
	ft::map<int, int> ft;
	ft.insert(ft::make_pair(1, 8));
	ft.insert(ft::make_pair(2, 9));
	ft.insert(ft::make_pair(3, 10));
	ft.insert(ft::make_pair(4, 11));
	ft.insert(ft::make_pair(0, 3));
	//std::cout << "ft begin test (first): " << ft.begin().first << "\n";
	//std::cout << "ft begin test (second): " << ft.begin().second << "\n";
}

