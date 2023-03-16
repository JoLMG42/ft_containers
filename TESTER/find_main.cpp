/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2023/03/15 06:53:59 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42TESTERS-CONTAINERS/test_utils.hpp"
#include "includes/map.hpp"
#include <map>

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;

template <class Key, class T>
void	print(map<Key, T>& lst)
{
	for (typename map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
		cout << it->first << " => " << it->second << '\n';
}

int main ()
{
  map<char,int> mymap;
  map<char,int>::iterator it;

  mymap['a']=50;
  mymap['b']=100;
  mymap['c']=150;
  mymap['d']=200;

  it = mymap.find('b');
  if (it != mymap.end())
    mymap.erase (it);

  // print content:
  cout << "elements in mymap:" << '\n';
  cout << "a => " << mymap.find('a')->second << '\n';
  cout << "c => " << mymap.find('c')->second << '\n';
  cout << "d => " << mymap.find('d')->second << '\n';

  return 0;
}
