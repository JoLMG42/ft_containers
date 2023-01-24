/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:41:15 by jtaravel          #+#    #+#             */
/*   Updated: 2023/01/24 14:00:54 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP

#define REVERSE_ITERATOR_HPP

namespace ft
{

template <class Iterator>
class	reverse_iterator
{
	public:
		typedef		 Iterator			 iterator_type;
		typedef typename Iterator::value_type            value_type;
		typedef typename Iterator::difference_type       difference_type;
		typedef typename Iterator::iterator_category     iterator_category;
		typedef typename Iterator::pointer               pointer;
		typedef typename Iterator::reference             reference;

		reverse_iterator(void);
		reverse_iterator(iterator_type it);
		reverse_iterator(const reverse_iterator<Iterator> &cpy);
		iterator_type	 base(void) const;
		
		reference 	 &operator*(void) const;
		reference 	 &operator[](difference_type n) const;
		pointer		 operator->(void) const;
		reverse_iterator &operator--(void);
		reverse_iterator operator--(int);
		reverse_iterator &operator++(void);
		reverse_iterator operator++(int);
		reverse_iterator &operator-=(difference_type n);
		reverse_iterator &operator+=(difference_type n);
		reverse_iterator operator-(difference_type n) const;
		reverse_iterator operator+(difference_type n) const;
		
		private:
			Iterator	_it;
		

	
};

template <class Iterator>
bool    operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
template <class Iterator>
bool    operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
template <class Iterator>
bool    operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
template <class Iterator>
bool    operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
template <class Iterator>
bool    operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
template <class Iterator>
bool    operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
template <class Iterator>
reverse_iterator<Iterator>    operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it);
template <class Iterator>
reverse_iterator<Iterator>    operator-(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it);

}

#include "reverse_iterator.tpp"

#endif

