/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:28:54 by jtaravel          #+#    #+#             */
/*   Updated: 2023/01/25 20:01:41 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP

#define VECTOR_HPP

#include <memory>
#include <iterator>
#include <cstddef>
#include <iostream>
#include <cstdlib>
#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"

namespace ft
{

template < class T, class Alloc = std::allocator<T> >
class vector
{
	public:
		template <class U>
		class   vector_iterator
		{
    			public:
				typedef U value_type;
				typedef ptrdiff_t difference_type;
				typedef U* pointer;
				typedef U& reference;
				typedef ft::random_access_iterator_tag iterator_category;
			        vector_iterator(pointer ptr = 0):_ptr(ptr) {};
				vector_iterator(vector_iterator const &copy)
				{ _ptr = copy._ptr; }
				reference operator*(void) const
				{ return (*_ptr); }
				pointer operator->() const
				{ return _ptr; }
				reference operator[](difference_type n) const
				{ return _ptr[n]; }
				vector_iterator operator=(vector_iterator const & egal)
				{ _ptr = egal._ptr; return *this; }
				vector_iterator &operator++()
				{ _ptr++;return *this; }
				vector_iterator operator++(int)
				{ vector_iterator tmp(*this); _ptr++; return tmp; }
				vector_iterator &operator--()
				{ _ptr--;return *this; }
				vector_iterator operator--(int)
				{ vector_iterator tmp(*this); _ptr--; return tmp; }
				vector_iterator operator-(difference_type n) const
				{ vector_iterator tmp(*this); tmp._ptr = tmp._ptr - n; return (tmp); }
				vector_iterator &operator+=(difference_type n)
				{ _ptr = _ptr + n; return (*this); }
				vector_iterator &operator-=(difference_type n)
				{ _ptr -= n; return (*this); }
				difference_type operator-(vector_iterator const& b) const
				{ return (_ptr - b._ptr); }
				friend vector_iterator operator+(vector_iterator const& lhs, difference_type n)
				{ vector_iterator tmp(lhs); tmp._ptr += n;return (tmp); }
				friend vector_iterator operator+(difference_type n, vector_iterator const& lhs)
				{ vector_iterator tmp(lhs); tmp._ptr += n; return (tmp); }

				friend bool operator==(const vector_iterator &lhs, const vector_iterator &rhs)
				{ return lhs._ptr == rhs._ptr; }
				friend bool operator!=(const vector_iterator &lhs, const vector_iterator &rhs)
				{ return lhs._ptr != rhs._ptr; }
				friend bool operator>=(const vector_iterator &lhs, const vector_iterator &rhs)
				{ return lhs._ptr >= rhs._ptr; }
				friend bool operator<=(const vector_iterator &lhs, const vector_iterator &rhs)
				{ return lhs._ptr <= rhs._ptr; }
				friend bool operator>(const vector_iterator &lhs, const vector_iterator &rhs)
				{ return lhs._ptr > rhs._ptr; }
				friend bool operator<(const vector_iterator &lhs, const vector_iterator &rhs)
				{ return lhs._ptr < rhs._ptr; }
		        private:
		                pointer	_ptr;
	
		};

	public:
		typedef	T	value_type;
		typedef	Alloc	allocator_type;
		typedef	std::size_t	size_type;

		vector(const allocator_type& alloc = allocator_type());
		vector(size_type n, const value_type & val);
		vector(const vector & cpy);
		~vector();


		T & operator[](size_type idx)
			{ return (_tab[idx]);}
		T & operator[](size_type idx) const
			{ return (_tab[idx]);}
		T & operator=(const vector & egal)
			{ _tab = egal._tab; _size = egal._size; _capacity = egal._capacity; _alloc = egal._alloc;
				return *this;}
	
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
		typedef vector_iterator<T> iterator;
		typedef vector_iterator<const T> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

		iterator begin(void)
		{ return (iterator(&_tab[0])); }
		iterator end(void)
		{ return (iterator(&_tab[_size])); }
		reverse_iterator rbegin(void)
		{ return (reverse_iterator(&_tab[_size])); }
		const_reverse_iterator rbegin(void) const
		{ return (const_reverse_iterator(&_tab[_size])); }
		reverse_iterator rend(void)
		{ return (reverse_iterator(&_tab[0])); }
		const_reverse_iterator rend(void) const
		{ return (const_reverse_iterator(&_tab[0])); }
		iterator erase (iterator position)
		{
			_size--;
			iterator end = this->end();
			iterator tmp(position);
			_alloc.destroy(position.operator->());
			while (tmp != end)
			{
				_alloc.construct(tmp.operator->(), *(tmp + 1));
				tmp++;
				_alloc.destroy(tmp.operator->());
			}
			return (position);
		}
		iterator erase (iterator first, iterator last)
		{
			//iterator begin = this->begin();
		//	iterator end = this->end();
			iterator tmp1(first);
			int i = 0;
			while (tmp1 != last)
			{
				i++;
				_alloc.destroy(tmp1.operator->());
				tmp1++;
			}
			tmp1 = first;
			while (tmp1 != this->end())
			{
			//	std::cout << "TMP: " << *tmp1 << "\n";
				_alloc.construct(tmp1.operator->(), *(tmp1 + i));
				tmp1++;
				_alloc.destroy(tmp1.operator->());
			}
			_size -= i;
			//first = tmp1;
			return (first);
		}
		iterator insert (iterator position, const value_type& val)
		{
			_size++;
			iterator beg = this->begin();
			_alloc.construct(beg.operator->(), *beg);
			size_t pos = position - this->begin();
			size_t j = 0;
			for (size_t i = 0; i < pos; i++)
			{
				std::cout << "BEG boucle: " << *beg << "\n";
				_alloc.construct(&_tab[i], _tab[i - 1]);
				_alloc.destroy(&_tab[i - 1]);
				j = i;
			}
			//_alloc.destroy(beg..operator->());
			//_alloc.destroy(beg.operator->());
			//beg--;

			_alloc.construct(&_tab[j], val);
			/*while (beg != this->end())
			{
				value = *beg;
				_alloc.construct(beg.operator->(), value);
				beg++;
				//_alloc.construct(beg.operator->(), value);
				std::cout << "BEG boucle 2222: " << *beg << "\n";
		//		value = *beg;
				//_alloc.construct(beg.operator->(), *(beg));
				//_alloc.destroy(beg.operator->());
			}*/
			return (position);
		}

	private:
		value_type	*_tab;
		size_type	_size;
		size_type	_capacity;
		allocator_type	_alloc;


};

}

#include "vector.tpp"

#endif
