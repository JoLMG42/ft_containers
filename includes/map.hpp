/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:54:03 by jtaravel          #+#    #+#             */
/*   Updated: 2023/01/31 19:14:40 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP

#define MAP_HPP
namespace ft
{

template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T>> >
class map
{
	typedef Key					key_type;
	typedef	T					mapped_type;
	typedef pair<const key_type, mapped_type>	value_type;
	typedef	Compare					key_compare;
	//typedef value_compare;
	typedef	Alloc					allocator_type;
	typedef	allocator_type::reference		reference;
	typedef	allocator_type::const_reference		const_reference;
	typedef	allocator_type::pointer			pointer;
	typedef	allocator_type::const_pointer		const_pointer;

};

}

#endif

