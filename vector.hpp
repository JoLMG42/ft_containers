/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:28:54 by jtaravel          #+#    #+#             */
/*   Updated: 2023/01/19 19:13:39 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP

#define VECTOR_HPP

#include <memory>

namespace ft
{

template < class T, class Alloc = std::allocator<T> >

class vector
{
	public:
		typedef	T	value_type;
		typedef	Alloc	allocator_type;
		typedef	size_t	size_type;

		vector(const allocator_type& alloc = allocator_type());
		vector(size_type n, const value_type & val);
		vector(const vector & cpy);
		~vector();


		T & operator[](size_type idx)
			{ return (_tab[idx]);}
		T & operator[](size_type idx) const
			{ return (_tab[idx]);}

		size_type	size(void) const;
		size_type	max_size(void) const;
		size_type	capacity(void) const;
		Alloc		get_allocator(void) const;
		void		newCapacity(size_type n);
		void	push_back(const value_type &val);
		void	pop_back(void);
		void	clear(void);
		void	resize(size_type n, const value_type & val = T());
		void	reserve(size_type n);
		void	swap(vector<T, Alloc>& x);
		T &	at(size_type idx) const;
		T &	front(void) const;
		T &	back(void) const;
		bool	empty(void) const;

	private:
		value_type	*_tab;
		size_type	_size;
		size_type	_capacity;
		allocator_type	_alloc;
};
}

#include "vector.tpp"

#endif
