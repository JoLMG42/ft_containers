/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:54:03 by jtaravel          #+#    #+#             */
/*   Updated: 2023/03/06 19:07:22 by jtaravel         ###   ########.fr       */
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

				map_iterator	&operator=(const V &egal)
				{
					//std::cout << "ICICICICICICIC: " << _ptr->m_right << "\n";
					std::cout << "OPERATOR=\n";
					_ptr = egal._ptr;
					return *this;
				}
				pointer	operator->() const
				{
					return &this->_ptr->p;
				}

				map_iterator &operator++()
				{
					if (_ptr == 0)
					{
						if (_ptr->m_parent == 0 || _ptr->m_parent->m_right == _ptr)
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
						while (_ptr->m_parent->m_right ==_ptr)
							_ptr = _ptr->m_parent;
						_ptr = _ptr->m_parent;
					}
					return *this;
				};

				map_iterator operator++(int)
				{
					map_iterator tmp(*this);
					++(*this);
					return tmp;
				}

				map_iterator &operator--()
				{
					if (!_ptr->m_right && !_ptr->m_left && !_ptr->m_parent)
						return *this;
					if (_ptr == NULL)
					{
						if (_ptr->m_parent == 0 || _ptr->m_parent->m_left == _ptr)
							return *this;
					}
					if (_ptr->m_left != NULL)
					{
						_ptr = _ptr->m_left;
						while (_ptr->m_right != 0)
							_ptr = _ptr->m_right;
					}
					else if (_ptr->m_parent->m_right == _ptr)
						_ptr = _ptr->m_parent;
					else
					{
						while (_ptr->m_parent->m_left ==_ptr)
							_ptr = _ptr->m_parent;
						_ptr = _ptr->m_parent;
					}
					return *this;
				};

				map_iterator operator--(int)
				{
					map_iterator tmp(*this);
					--(*this);
					return tmp;
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
			typedef ft::pair<const key_type, mapped_type>	value_type;
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
			typedef typename allocator_type::template rebind<Node>::other		Node_allocator;

  
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{
				_alloc = alloc;
				_comp = comp;
				_end = _tree.newNode();
				//_end = _nodeAlloc.allocate(1);
				//_nodeAlloc.construct(_end, value_type());
				//_tree.setEndNode();
				/*_last = _tree.newNode();
				_last->m_left = _tree.getNULL();
				_last->m_right = _tree.getNULL();
				_last->m_parent = _tree.getRoot();
				_tree.getRoot()->m_right = _last;*/
				//_tree.getRoot()->m_right = _last;
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
				_end = _tree.newNode();
				//_end = _tree.newNode();
				//_end = _nodeAlloc.allocate(1);
				//_nodeAlloc.construct(_end, value_type());
				/*_last = _tree.newNode();
				_last->m_left = _tree.getNULL();
				_last->m_right = _tree.getNULL();
				_last->m_parent = _tree.getRoot();
				_tree.getRoot()->m_right = _tree.getLast();*/
				while (first != last)
				{
					real_print(_tree.getRoot(), 0, _tree);
					insert(*first);
					std::cout << "CONSTRUCTOR RELOU: " << first->first << "\n";
					first++;
				}
				_tree.setEndNode(_end);
			}

			iterator	begin(void)
			{
				//_tree.deleteEndNode(_end);
				iterator tmp(_tree.minD(_tree.getRoot()));
				//_tree.setEndNode(_end);
				return tmp;
			}

			const_iterator	begin(void) const
			{
				const_iterator tmp(_tree.minD(_tree.getRoot()));
				return tmp;
			}

			iterator end()
			{
				//Node *tmp = _tree.maxNode(_tree.getRoot());
				//std::cout << "ENEDNENNEDNEDNEDNEDNEDNNED: " << tmp->p.first << "\n";
				//iterator it(tmp);
				//tmp->second = 0;
				return (iterator(_end));
			}
			const_iterator end() const
			{
				//const_iterator tmp(_tree.maxD(_tree.getRoot()));
				//tmp->second = 0;
				return (const_iterator(_end));
			}

			ft::pair<const_iterator,const_iterator>	equal_range(const key_type& k) const
			{
				return (ft::pair<const_iterator,const_iterator>(lower_bound(k), upper_bound(k)));
			}

			ft::pair<iterator,iterator>	equal_range(const key_type& k)
			{
				return (ft::pair<iterator,iterator>(lower_bound(k), upper_bound(k)));
			}

			void	erase(iterator position)
			{
				_tree.deleteEndNode(_end);
				_tree.deleteNode(_tree.getRoot(), _tree.searchRetVal(position->first));
				_tree.setEndNode(_end);

			}

			size_type	erase(const key_type& k)
			{
				std::cout << "PAS COMPRENDRE MOI ROOT->VALUE dans erase: " << _tree.getRoot()->p.first << "\n";
				_tree.deleteEndNode(_end);
				return (_tree.deleteNode(_tree.getRoot(), _tree.searchRetVal(k)));
				_tree.setEndNode(_end);
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
				std::cout << "AFFICHAGE AVANT DELETE END\n";
				//real_print(_tree.getRoot(), 0, _tree);
				//if (_tree.getSize() > 0)
				real_print(_tree.getRoot(), 0, _tree);
				_tree.deleteEndNode(_end);
				std::cout << "AFFICHAGE APRES DELETE END\n";
				real_print(_tree.getRoot(), 0, _tree);
				_tree.insertNode(val);
				std::cout << "AFFICHAGE APRES INSERT END\n";
				//real_print(_tree.getRoot(), 0, _tree);
				//std::cout << "insert val: " << val.first << "\n";
				//iterator tmp(_tree.searchRetNode(val.first));
				value_type	*tmp;
				tmp = _alloc.allocate(1);
				_alloc.construct(tmp, val);
				Node *node = _nodeAlloc.allocate(1);
				_nodeAlloc.construct(node, *tmp);
				_tree.setEndNode(_end);
				iterator it(node);
				return (make_pair<iterator, bool>(it, true));
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
				iterator first = this->begin();
				iterator last = this->end();

				while (first != last)
				{
					if (!_comp((*first).first, k))
						break ;
					first++;
				}
				return first;
			}

			const_iterator	lower_bound(const key_type& k) const
			{
				const_iterator first = this->begin();
				const_iterator last = this->end();

				while (first != last)
				{
					if (!_comp((*first).first, k))
						break ;
					first++;
				}
				return first;
			}

			iterator	upper_bound(const key_type& k)
			{
				iterator first = this->begin();
				iterator last = this->end();

				while (first != last)
				{
					if (_comp(k, (*first).first))
					{
						break ;
					}
					first++;
				}
				return first;
				/*if (_tree.search(k))
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
				return (0);*/

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
				const_iterator first = this->begin();
				const_iterator last = this->end();

				while (first != last)
				{
					if (_comp(k, (*first).first))
						break ;
					first++;
				}
				return first;
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

			map	&operator=(const map& egal)
			{
				_size = egal._size;
				_tree.deleteEndNode();
				Node *newN = NULL;

				map::const_iterator start = egal.begin();
				map::const_iterator fin = egal.end();

				//this->recursive_assignment(_base_tree, &new_base, x_first, x_last);

				value_type	*tmp_pair;
				Node		*tmp_node;
				while (start != fin)
				{
					tmp_pair = _alloc.allocate(1);
					_alloc.construct(tmp_pair, *start);
					tmp_node = _nodeAlloc.allocate(1);
					_nodeAlloc.construct(tmp_node, tmp_pair);
					++start;
					_tree.insertNode(tmp_node->p);
				}
				_tree.setRoot() = newN;
				_tree.setEndNode(_end);
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
			Node_allocator	_nodeAlloc;
			Alloc	_alloc;
			Compare _comp;
			Node *_end;
			size_t	_size;
	};
}

#endif
