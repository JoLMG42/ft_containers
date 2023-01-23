/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:06:21 by jtaravel          #+#    #+#             */
/*   Updated: 2023/01/23 15:27:17 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP

#define VECTOR_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "vector.hpp"
#include <iterator>

namespace ft
{

template <class Iterator>
class	vector_iterator
{
    public:
	typedef Iterator								iterator_type;
	typedef typename ft::iterator_traits<Iterator>::value_type          		value_type;
	typedef typename ft::iterator_traits<Iterator>::difference_type     		difference_type;
	typedef typename ft::iterator_traits<Iterator>::pointer             		pointer;
	typedef typename ft::iterator_traits<Iterator>::reference           		reference;
	typedef typename ft::iterator_traits<Iterator>::iterator_category   		iterator_category;
	
	vector_iterator(const Iterator *it)
	{	_it = it;	}
	private:
		Iterator _it;
	
};

}

#endif
