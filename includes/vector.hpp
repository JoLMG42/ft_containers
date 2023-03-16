/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:28:54 by jtaravel          #+#    #+#             */
/*   Updated: 2023/03/16 17:29:51 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP

#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <iterator>
#include <cstddef>
#include <cstdlib>
#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "equal.hpp"
#include "lexicographical_compare.hpp"

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
				vector_iterator(vector_iterator const &cpy)
				{  _ptr = cpy._ptr; }
				reference operator*(void) const
				{ return (*_ptr); }
				pointer operator->() const
				{ return _ptr; }
				reference operator[](difference_type n) const
				{ return _ptr[n]; }
				vector_iterator operator=(vector_iterator const & egal)
				{ _ptr = egal._ptr; return *this; }
				vector_iterator &operator++()
				{ _ptr++; return *this; }
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
				friend difference_type operator-(vector_iterator const& lhs, vector_iterator const &rhs)
				{ return (lhs._ptr - rhs._ptr); }
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

				operator vector_iterator<const value_type>() const
				{
					return vector_iterator<const value_type>(_ptr);
				}



		        private:
		                pointer	_ptr;
	
		};

	public:
		typedef	T	value_type;
		typedef	Alloc	allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef	std::size_t	size_type;
		typedef typename allocator_type::pointer	pointer;
		typedef typename allocator_type::const_pointer	const_pointer;
		typedef vector_iterator<T> iterator;
		typedef vector_iterator<const T> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

		explicit vector(const allocator_type& alloc = allocator_type());
		explicit vector(size_type n, const value_type & val = value_type());
		template<class InputIterator>
		vector(typename ft::enable_if<!ft::is_integral<InputIterator>::value , InputIterator>::type first, InputIterator last, const allocator_type& alloc = allocator_type())
		{
			(void)last;
			_alloc = alloc;
			size_t i = 0;
			InputIterator tmp(first);
			while (tmp != last)
			{
				i++;
				tmp++;
			}
			_size = i;
			_capacity = _size;
			_tab = _alloc.allocate(_capacity);
			for (size_type i = 0; i < _size; ++i)
			{
				_alloc.construct(&_tab[i], *first);
				first++;
			}
		}
		vector(const vector & cpy);
		~vector();

		T & operator[](size_type idx)
			{ return (_tab[idx]);}
		T & operator[](size_type idx) const
			{ return (_tab[idx]);}

		vector & operator=(const vector & egal)
			{
				if (egal._tab)
				{
					for (size_t i = 0; i < _size; i++)
						_alloc.destroy(&_tab[i]);
					_alloc.deallocate(_tab, _capacity);
					_size = egal._size; _capacity = egal._capacity; _alloc = egal._alloc;
					_tab = _alloc.allocate(_capacity);
					for (size_t i = 0; i < _size; i++)
						_alloc.construct(&_tab[i], egal._tab[i]);
				}
				return *this; }

		friend bool operator==(const vector& lhs, const vector& rhs)
		{
			if (lhs.size() == rhs.size())
				return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
			return (false);
		}
		friend bool operator!=(const vector& lhs, const vector& rhs)
		{
			return (!(lhs == rhs));
		}
		friend bool operator<(const vector& lhs, const vector& rhs)
		{
			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}
		friend bool operator<=(const vector& lhs, const vector& rhs)
		{
			return (!(rhs < lhs));
		}
		friend bool operator>(const vector& lhs, const vector& rhs)
		{
			return (rhs < lhs);
		}
		friend bool operator>=(const vector& lhs, const vector& rhs)
		{
			return (!(lhs < rhs));
		}
	
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
		void	assign(size_type n, const value_type& val);
		T &	at(size_type idx) const;
		T &	at(size_type idx);
		T &	front(void);
		T &	back(void);
		bool	empty(void) const;

		const_reference	back(void) const
		{ return (_tab[_size - 1]); }
		const_reference	front(void) const
		{ return (_tab[0]); }


		iterator begin(void)
		{ return (iterator(&_tab[0])); }
		iterator end(void)
		{ return (iterator(_tab + _size)); }
		const_iterator begin(void) const
		{ return (const_iterator(&_tab[0])); }
		const_iterator end(void) const
		{ return (const_iterator(_tab + _size)); }
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
			while (first != last)
			{
				erase(first);
				last--;
			}
			return (first);
		}
		iterator insert (iterator position, const value_type& val)
		{
			if (position == this->end())
			{
				iterator tmp(position);
				push_back(val);
				return (iterator(this->end()) - 1);
			}
			else
			{
				size_t pos;
				if (position.operator->() == this->begin().operator->())
					pos = position - begin();
				else
					pos = position - this->begin();
				if (_capacity < _size + 1)
					reserve(_capacity + 1);
				_size++;
				for(size_t i = _size - 1; i > pos; i--)
				{
					_alloc.construct(&_tab[i], _tab[i - 1]);
					_alloc.destroy(&_tab[i - 1]);
				}
				_alloc.construct(&_tab[pos], val);
				return (iterator(_tab + pos));
			}
			return (position);
		}
		void insert (iterator position, size_type n, const value_type& val)
		{
			size_t pos = position - this->begin();
			while (n)
			{
				insert(&_tab[pos], val);
				pos++;
				n--;
			}
		}
		template <class InputIterator>
		void insert(iterator position, InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last)
		{
			size_t pos = position - this->begin();
			while (first != last)
			{
				insert(_tab + pos, *first);
				pos++;
				first++;
			}
		}
		template <class InputIterator>
		void assign(typename ft::enable_if<!ft::is_integral<InputIterator>::value , InputIterator>::type first, InputIterator last)
		{
			clear();
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}
		void	realloc(size_t newcapa)
		{
			T *tmp = _alloc.allocate(newcapa);
			for (size_type j = 0; j < _size - 1; ++j)
                	        _alloc.construct(&tmp[j], _tab[j]);
			for (size_type j = 0; j < _size - 1; ++j)
                	        _alloc.destroy(_tab + j);
			_alloc.deallocate(_tab, _capacity);
			_tab = tmp;
			_capacity = newcapa;

		}
	private:
		value_type	*_tab;
		size_type	_size;
		size_type	_capacity;
		allocator_type	_alloc;
};
template <class T, class Alloc>
void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
{
	x.swap(y);
}



}

#include "vector.tpp"

#endif
