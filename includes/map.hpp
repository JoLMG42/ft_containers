/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:54:03 by jtaravel          #+#    #+#             */
/*   Updated: 2023/02/15 19:06:14 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP

#define MAP_HPP

#include "pair.hpp"
#include "RBT.hpp"

namespace ft
{

template< class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T>> >
	class map
	{
		public:
			typedef Key					key_type;
			typedef	T					mapped_type;
			typedef pair<const key_type, mapped_type>	value_type;
			typedef	Compare					key_compare;
			typedef	size_t					size_type;
			//typedef value_compare;
			typedef	Alloc					allocator_type;
			typedef	typename allocator_type::reference		reference;
			typedef	typename allocator_type::const_reference		const_reference;
			typedef	typename allocator_type::pointer			pointer;
			typedef	typename allocator_type::const_pointer		const_pointer;

			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{
				//RBT<key_type, value_compare>	_tree;
				_alloc = alloc;
				RBT<key_type, value_compare>	_tree({});
			}

			size_type	count(const key_type &k) const
			{
				if (_tree.search(k))
					return (1);
				return (0);
			}

			void	clear(void)
			{
				_tree.destroyAll();
					
			}

			bool	empty() const
			{
				if (size())
					return (false);
				return (true);
			}

			size_type	size(void) const
			{
				size_type s = _tree.countElem(_tree.getRoot(), 1);
				std::cout << "ssss: " << s << "\n";
				_tree.countElem(_tree.getRoot(), 0);
				return (s);
			}

			Alloc	get_allocator(void) const
			{
				return (_alloc);
			}

			size_type	max_size() const
			{
				return _alloc.max_size();
			}

			mapped_type &operator[](const key_type &k)
			{
				return searchRetVal(k);
			}
			//template <class Key, class T, class Compare, class Alloc>
				class value_compare
				{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
					protected:
						Compare comp;
						value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
					public:
						typedef bool result_type;
						typedef value_type first_argument_type;
						typedef value_type second_argument_type;
						bool operator() (const value_type& x, const value_type& y) const
						{
							return comp(x.first, y.first);
						}
				};
		//	template <class key_type, value_compare>
		//	RBT<key_type, value_compare>	getTree(void)
		//	{
		//		return _tree;
		//	}
		//private:
			//RBT<key_type, value_compare>	_tree;
			RBT<key_type, value_compare> _tree;
			Alloc	_alloc;
	};
}

#endif
