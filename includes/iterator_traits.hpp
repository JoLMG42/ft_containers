/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:16:54 by jtaravel          #+#    #+#             */
/*   Updated: 2023/01/30 13:08:18 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP

#define ITERATOR_TRAITS_HPP

#include <iostream>

namespace ft
{

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

template <class Iterator>
class iterator_traits
{
	typedef typename Iterator::iterator_category iterator_category;
	typedef typename Iterator::value_type        value_type;
	typedef typename Iterator::difference_type   difference_type;
	typedef typename Iterator::pointer           pointer;
	typedef typename Iterator::reference         reference;
};

template <class T>
class iterator_traits<T*>
{
	typedef random_access_iterator_tag iterator_category;
	typedef T                          value_type;
	typedef std::ptrdiff_t                  difference_type;
	typedef T*                         pointer;
	typedef T&                         reference;
};

template <class T>
class iterator_traits<const T*>
{
	typedef random_access_iterator_tag iterator_category;
	typedef T                          value_type;
	typedef std::ptrdiff_t                  difference_type;
	typedef const T*                         pointer;
	typedef const T&                         reference;
};
}
#endif
