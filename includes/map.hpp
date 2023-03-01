/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:54:03 by jtaravel          #+#    #+#             */
/*   Updated: 2023/03/01 19:59:04 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP

#define MAP_HPP

#include "pair.hpp"
#include "RBT.hpp"
#include "iterator_traits.hpp"
#include "make_pair.hpp"
#include <iomanip>

namespace ft
{

template< class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		template <class U, class V>
		class map_iterator
		{
			typedef U		value_type;
			typedef ptrdiff_t	difference_type;
			typedef U*		pointer;
			typedef U&		reference;
			typedef ft::bidirectional_iterator_tag  iterator_category;

			public:
				map_iterator(V *ptr = 0): _ptr(ptr)
				{
				}

				V *operator=(const V &egal)
				{
					//std::cout << "ICICICICICICIC: " << _ptr->m_right << "\n";
					std::cout << "OPERATOR=\n";
					_ptr->_alloc.deallocate();
					_ptr->alloc.allocate(1);
					_ptr->p = egal.p;
					_ptr->_alloc = egal._alloc;
				}
				pointer	operator->() const
				{
					return &this->_ptr->p;
				}

				/*map_iterator &operator++()
					{
						if (_ptr != NULL)
						{
							if (_ptr->m_parent == NULL)
								return *this;
							if (_ptr->m_parent->m_right == _ptr)
								return *this;
						}
						if (_ptr->m_right != 0)
						{
							_ptr = _ptr->m_right;
							while (_ptr->m_left != 0)
								_ptr = _ptr->m_left;
						}
						else if (_ptr->m_parent->m_left ==_ptr)
							_ptr = _ptr->m_parent;
						else
						{
							while (_ptr->m_parent && _ptr->m_parent->m_right ==_ptr)
								_ptr = _ptr->m_parent;
							_ptr = _ptr->m_parent;
						}
						return *this;
					};

				map_iterator operator++(int)
				{
					map_iterator tmp(*this);++(*this);return tmp;
				}*/

				V	*operator--(int)
				{
					if (_ptr && _ptr->m_right)
					{
						V  *tmp = _ptr->m_right;
						while (tmp->m_left)
						{
							tmp = tmp->m_left;
						}
						_ptr = tmp;
						return tmp;
					}
					else if (_ptr)
					{
						V *tmp = _ptr->m_parent;
						while (tmp)
						{
							if (tmp->p.first > _ptr->p.first)
							{
								_ptr = tmp;
								return tmp;
							}
							tmp = tmp->m_parent;
						}
					}
					return (0);
				}

				V	*operator--()
				{
					if (_ptr->m_right)
					{
						V  *tmp = _ptr->m_right;
						while (tmp->m_left)
						{
							tmp = tmp->m_left;
						}
						_ptr = tmp;
						return tmp;
					}
					else
					{
						V *tmp = _ptr->m_parent;
						while (tmp)
						{
							if (tmp->p.first > _ptr->p.first)
							{
								_ptr = tmp;
								return tmp;
							}
							tmp = tmp->m_parent;
						}
					}
					return (0);
				}

				V	*operator++(int)
				{
					if (_ptr && _ptr->m_right)
					{
						V  *tmp = _ptr->m_right;
						while (tmp->m_left)
						{
							tmp = tmp->m_left;
						}
						_ptr = tmp;
						return tmp;
					}
					else if (_ptr)
					{
						V *tmp = _ptr->m_parent;
						while (tmp)
						{
							if (tmp->p.first > _ptr->p.first)
							{
								_ptr = tmp;
								return tmp;
							}
							tmp = tmp->m_parent;
						}
					}
					return (0);
				}

				V	*operator++()
				{
					if (_ptr->m_right)
					{
						V  *tmp = _ptr->m_right;
						while (tmp->m_left)
						{
							tmp = tmp->m_left;
						}
						_ptr = tmp;
						return tmp;
					}
					else
					{
						V *tmp = _ptr->m_parent;
						while (tmp)
						{
							if (tmp->p.first > _ptr->p.first)
							{
								_ptr = tmp;
								return tmp;
							}
							tmp = tmp->m_parent;
						}
					}
					return (0);
				}

				reference	operator*(void)
				{
					return _ptr->p;
				}

				friend bool operator==(const map_iterator &lhs, const map_iterator &rhs)
				{
					return (lhs._ptr == rhs._ptr);
				}
				friend bool operator!=(const map_iterator &lhs, const map_iterator &rhs)
				{
					return (lhs._ptr != rhs._ptr);
				}
				friend bool operator<=(const map_iterator &lhs, const map_iterator &rhs)
				{
					return (lhs._ptr <= rhs._ptr);
				}
				friend bool operator>=(const map_iterator &lhs, const map_iterator &rhs)
				{
					return (lhs._ptr >= rhs._ptr);
				}
				friend bool operator<(const map_iterator &lhs, const map_iterator &rhs)
				{
					return (lhs._ptr < rhs._ptr);
				}
				friend bool operator>(const map_iterator &lhs, const map_iterator &rhs)
				{
					return (lhs._ptr > rhs._ptr);
				}

				operator map_iterator<const U, V>()  const
				{
					return  map_iterator<const U, V>(_ptr);
				}

			private:
				V *_ptr;

		};
		public:
			//struct Node;
			typedef Key					key_type;
			typedef	T					mapped_type;
			typedef pair<const key_type, mapped_type>	value_type;
			typedef	Compare					key_compare;
			typedef	size_t					size_type;
			typedef	Alloc					allocator_type;
			typedef	typename allocator_type::reference		reference;
			typedef	typename allocator_type::const_reference		const_reference;
			typedef	typename allocator_type::pointer			pointer;
			typedef	typename allocator_type::const_pointer		const_pointer;
			//typedef RBT<key_type, mapped_type, value_type, key_compare, allocator_type> Node;
			typedef	typename RBT<key_type, mapped_type, value_type>::template Node<key_type> Node;
			typedef map_iterator<value_type, Node>					iterator;
			typedef map_iterator<const value_type, Node>				const_iterator;
  
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{
				_alloc = alloc;
				_comp = comp;
				//RBT<key_type, value_compare>	_tree({});
				//RBT<key_type, mapped_type, value_type, key_compare, allocator_type>	_tree({});
				//RBT _tree;
			}

			map(const map& x)
			{
				*this = x;
			}

			        void    real_print(Node *ptr, int space, RBT<key_type, mapped_type, value_type, key_compare> test)
        {
                if (!ptr || ptr == test.getNULL())
                {
                        return;
                }
                space += 4;
                real_print(ptr->m_right, space, test);
                std::cout
                        << (ptr->m_color == ft::s_black ? "\033[90m" : "\033[31m") << std::setw(space)
                        << ptr->p.first << "\033[0m" << std::endl;
                // getwchar();
                real_print(ptr->m_left, space, test);
        }

			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{
				_comp = comp;
				_alloc = alloc;
				while (first != last)
				{
					real_print(_tree.getRoot(), 0, _tree);
					insert(*first);
					std::cout << "CONSTRUCTOR RELOU: " << first->first << "\n";
					first++;
				}
			}

			iterator	begin(void)
			{
				iterator tmp(_tree.minD(_tree.getRoot()));
				return tmp;
			}

			const_iterator	begin(void) const
			{
				const_iterator tmp(_tree.minD(_tree.getRoot()));
				return tmp;
			}

			iterator end()
			{
				Node *tmp = _tree.maxNode(_tree.getRoot());
				//std::cout << "ENEDNENNEDNEDNEDNEDNEDNNED: " << tmp->p.first << "\n";
				iterator it(tmp);
				//tmp->second = 0;
				return (it);
			}
			const_iterator end() const
			{
				const_iterator tmp(_tree.maxD(_tree.getRoot()));
				//tmp->second = 0;
				return (tmp);
			}

			pair<const_iterator,const_iterator> equal_range (const key_type& k) const
			{
				///   FAIRE LE CAS OU CA TROUVE PAS ///
				return make_pair(const_iterator(_tree.searchRetNode(k)), const_iterator(_tree.searchRetNode(k))++);
			}

			pair<iterator,iterator>	equal_range (const key_type& k)
			{
				///   FAIRE LE CAS OU CA TROUVE PAS ///
				return make_pair(iterator(_tree.searchRetNode(k)), iterator(_tree.searchRetNode(k))++);
			}

			void	erase(iterator position)
			{
				_tree.deleteNode(_tree.getRoot(), _tree.searchRetVal(position->first));

			}

			size_type	erase(const key_type& k)
			{
				return (_tree.deleteNode(_tree.getRoot(), _tree.searchRetVal(k)));
			}

			void	erase(iterator first, iterator last)
			{
				while (first != last)
				{
					_tree.deleteNode(_tree.getRoot(), _tree.searchRetVal(first->first));
					first++;
				}
			}

			pair<iterator, bool>	insert(const value_type &val)
			{
				//	return (make_pair(iterator(val), false));
				_tree.insertNode(val);
				//std::cout << "insert val: " << val.first << "\n";
				iterator tmp(_tree.searchRetNode(val.first));
				return (make_pair<iterator, bool>(tmp, true));
				//return iterator(val);
			}

			/*iterator	insert(iterator position, const value_type& val)
			{
				_tree.insertNode(val);
				iterator tmp(_tree.searchRetNode(val.first));
				return tmp;
					
			}*/
			
			iterator	lower_bound(const key_type& k)
			{
				if (_tree.search(k))
				{
					Node *tmp = _tree.searchRetNode(k);
					iterator it(tmp);
					return it;
				}
				else
				{
					Node *tmp = _tree.maxD(_tree.getRoot());
					Node *tmp2 = _tree.minD(_tree.getRoot());
					if (tmp->p.first - k < tmp2->p.first - k)
						return (this->end());
					else
						return (this->begin());
				}
				return (0);
			}

			const_iterator	lower_bound(const key_type& k) const
			{
				if (_tree.search(k))
				{
					Node *tmp = _tree.searchRetNode(k);
					const_iterator it(tmp);
					return it;
				}
				else
				{
					Node *tmp = _tree.maxD(_tree.getRoot());
					Node *tmp2 = _tree.minD(_tree.getRoot());
					if (tmp->p.first - k < tmp2->p.first - k)
						return (this->end());
					else
						return (this->begin());
				}
				return (0);
			}

			iterator	upper_bound(const key_type& k)
			{
				if (_tree.search(k))
				{
					Node *tmp = _tree.searchRetNode(k);
					iterator it(tmp);
					return it;
				}
				else
				{
					Node *tmp = _tree.maxD(_tree.getRoot());
					Node *tmp2 = _tree.minD(_tree.getRoot());
					if (tmp->p.first - k < tmp2->p.first - k)
						return (this->end());
					else
						return (this->begin());
				}
				return (0);
				/*if (_tree.search(k))
				{
					Node *tmp = _tree.searchRetNode(k);
					if (tmp == _tree.maxD(_tree.getRoot()))
						return (this->end());
					else
						return (iterator(_tree.searchRetNode(k))++);
				}
				return (this->end());*/
			}

			const_iterator	upper_bound(const key_type& k) const
			{
				if (_tree.search(k))
				{
					Node *tmp = _tree.searchRetNode(k);
					const_iterator it(tmp);
					return it;
				}
				else
				{
					Node *tmp = _tree.maxD(_tree.getRoot());
					Node *tmp2 = _tree.minD(_tree.getRoot());
					if (tmp->p.first - k < tmp2->p.first - k)
						return (this->end());
					else
						return (this->begin());
				}
				return (0);
			}

			iterator	find(const key_type& k)
			{
				if (_tree.search(k))
					return (iterator(_tree.searchRetNode(k)));
				else
					return this->end();
			}

			const_iterator	find(const key_type& k) const
			{
				if (_tree.search(k))
					return (const_iterator(_tree.searchRetNode(k)));
				else
					return this->end();
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

			key_compare	key_comp() const
			{
				return _comp;
			}


			size_type	size(void) const
			{
				size_type s = _tree.countElem(_tree.getRoot(), 1);
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

			mapped_type& operator[] (const key_type& k)
			{
				ft::pair<iterator,bool> tmp = this->insert(ft::make_pair(k, mapped_type()));
				return ((*(tmp.first)).second);
			}

			//template <class Key, class T, class Compare, class Alloc>
			class value_compare
			{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
				protected:
					Compare comp;

					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};

			value_compare	value_comp()const
			{
				return (value_compare(_comp));
			}
			map & operator=(const map & egal)
			{
				_tree = egal._tree;
				return *this;
			}
		//	template <class key_type, value_compare>
		//	RBT<key_type, value_compare>	getTree(void)
		//	{
		//		return _tree;
		//	}
		//private:
			//RBT<key_type, value_compare>	_tree;
			RBT<key_type, mapped_type, value_type, key_compare>	_tree;
			//RBT _tree;
			//RBT<key_type, value_compare> _tree;
			Alloc	_alloc;
			Compare _comp;
	};
}

#endif
