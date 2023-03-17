/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:54:03 by jtaravel          #+#    #+#             */
/*   Updated: 2023/03/16 17:28:08 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP

#define MAP_HPP

#include "pair.hpp"
#include "RBT.hpp"
#include "iterator_traits.hpp"
#include "make_pair.hpp"
#include "reverse_iterator.hpp"
#include <iomanip>
#include "equal.hpp"
#include "lexicographical_compare.hpp"

namespace ft
{

template< class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		template <class U, class V>
		class map_iterator
		{

			public:
				typedef U		value_type;
				typedef ptrdiff_t	difference_type;
				typedef U*		pointer;
				typedef U&		reference;
				typedef ft::bidirectional_iterator_tag  iterator_category;

				map_iterator(V *ptr = 0 , V *null = NULL): _ptr(ptr), _null(null)
				{
				}

				map_iterator(map_iterator const &cpy)
				{
					_null = cpy._null;
					_ptr = cpy._ptr;
				}
				~map_iterator(void)
				{
				}

				map_iterator	&operator=(map_iterator const &egal)
				{
					_ptr = egal._ptr;
					return *this;
				}
				pointer	operator->() const
				{
					return (_ptr->p);
				}

				map_iterator &operator++()
				{
					if (_ptr && _ptr->m_parent == NULL)
					{
						_ptr = _ptr->m_right;
						while (_ptr && _ptr != _null && _ptr->m_left != _null && _ptr->m_left != NULL)
							_ptr = _ptr->m_left;
						return *this;
					}
					if (_ptr->m_right != _null && _ptr->m_left != _null && !_ptr->m_parent)
						return *this;
					if (_ptr == NULL)
					{
						if (_ptr->m_parent == 0 || _ptr->m_parent->m_left == _ptr)
							return *this;
					}
					if (_ptr->m_right != NULL && _ptr->m_right != _null)
					{
						_ptr = _ptr->m_right;
						while (_ptr->m_left != NULL && _ptr->m_left != _null && _ptr != _null)
							_ptr = _ptr->m_left;
						return *this;

					}
					else if (_ptr->m_parent && _ptr == _ptr->m_parent->m_left)
						_ptr = _ptr->m_parent;
					else
					{
						while (_ptr->m_parent && _ptr == _ptr->m_parent->m_right && _ptr != _null)
							_ptr = _ptr->m_parent;
						_ptr = _ptr->m_parent;
						return *this;
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

				reference	operator*() const
				{
					return *(_ptr->p);
				}

				friend bool operator==(const map_iterator &lhs, const map_iterator &rhs)
				{
					return (lhs._ptr == rhs._ptr);
				}
				friend bool operator!=(const map_iterator &lhs, const map_iterator &rhs)
				{
					return (lhs._ptr != rhs._ptr);
				}

				operator	map_iterator<const value_type, V>() const
				{
					return map_iterator<const value_type, V>(_ptr);
				}

			private:
				V *_ptr;
				V *_null;

		};
		public:
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
			typedef	typename ft::RBT<key_type, mapped_type, value_type, key_compare, allocator_type>::template Node<key_type> Node;
			typedef map_iterator<value_type, Node>					iterator;
			typedef map_iterator<const value_type, Node>				const_iterator;
			typedef	ft::reverse_iterator<iterator>					reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>				const_reverse_iterator;
			typedef typename allocator_type::template rebind<Node>::other		Node_allocator;

         	 Node *makeNode(const value_type &v = value_type())
        	{
        	        Node *tmp = _nodeAlloc.allocate(1);
        	        value_type      *test;
        	         test = _alloc.allocate(1);
        	         _alloc.construct(test, v);
        	        _nodeAlloc.construct(tmp, test);
        	        return tmp;
        	}

	        Node *RetEnd(Node *node, Node *end)
	        {
	                if (node == 0)
	                        return (0);
	                while (node != _tree.getNULL() && node && node->m_right && node->m_right != _tree.getNULL() && node->m_right != end)
	                        node = node->m_right;
	                return (node);
	        }


	        void    setEnd(Node *end)
        	{
                	Node *tmp_max = RetEnd(_tree._root, end);
                	if (tmp_max != 0)
                	{
                	        tmp_max->m_right = end;
                	        end->m_parent = tmp_max;
                	        end->m_right = _tree.getNULL();
        	        }
	        }

	        void    deleteEnd(Node *end)
        	{
                	Node *tmp_max = RetEnd(_tree._root, end);
                	if (tmp_max != 0)
                	        tmp_max->m_right = 0;
        	}




			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _nodeAlloc(Node_allocator())
			{
				_alloc = alloc;
				_comp = comp;
				_end = makeNode();
				_size = 0;
				_ferase = 0;
			}

			map(const map& cpy)
			{
				_comp = cpy._comp;
				_alloc = cpy._alloc;
				_nodeAlloc = cpy._nodeAlloc;
				_end = makeNode();
				_size = 0;
				_ferase = 0;

				const_iterator first = cpy.begin();
				const_iterator last = cpy.end();
				deleteEnd(_end);
				while (first != last)
				{
					insert(*first);
					++first;
				}
				setEnd(_end);
			}

			void    destroyTree(Node *node)
			{
				if (!node || node == _tree.getNULL())
				{
					return ;
				}
				destroyTree(node->m_left);
				destroyTree(node->m_right);
				_alloc.destroy(node->p);
				_alloc.deallocate(node->p, 1);
			}

			~map(void)
			{
				_alloc.destroy(_end->p);
				_alloc.deallocate(_end->p, 1);
				_nodeAlloc.destroy(_end);
				_nodeAlloc.deallocate(_end, 1);
				deleteEnd(_end);
				_tree.destroyTOUT(_tree._root);
				_tree.destroyNODE(_tree.getNULL());
			}

			friend bool operator==(const map& lhs, const map& rhs)
			{
				if (lhs.size() == rhs.size())
					return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
				return (false);
			}
			friend bool operator!=(const map& lhs, const map& rhs)
			{
				return (!(lhs == rhs));
			}
			friend bool operator<(const map& lhs, const map& rhs)
			{
				return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
			}
			friend bool operator<=(const map& lhs, const map& rhs)
			{
				return (!(rhs < lhs));
			}
			friend bool operator>(const map& lhs, const map& rhs)
			{
				return (rhs < lhs);
			}
			friend bool operator>=(const map& lhs, const map& rhs)
			{
				return (!(lhs < rhs));
			}

			friend	void swap(map<Key, T, Compare,Alloc>& x, map<Key, T, Compare,Alloc>& y)
			{
				x.swap(y);	
			}

			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{
				_comp = comp;
				_alloc = alloc;
				_end = makeNode();
				_size = 0;
				_ferase = 0;
				_tree.deleteEndNode(_end);
				while (first != last)
				{
					insert(*first);
					first++;
				}
				_tree.setEndNode(_end);
			}

			iterator	begin(void)
			{
				if (_tree.minD(_tree.getRoot()) && _size > 0)
				{
					iterator tmp(_tree.minD(_tree.getRoot()), _tree.getNULL());
					return tmp;
				}
				return (this->end());
			}

			const_iterator	begin(void) const
			{
				if (_tree.minD(_tree.getRoot()) && _size > 0)
				{
					const_iterator tmp(_tree.minD(_tree.getRoot()), _tree.getNULL());
					return tmp;
				}
				return (this->end());
			}

			iterator end()
			{
				return (iterator(_end, _tree.getNULL()));
			}
			const_iterator end() const
			{
				return (const_iterator(_end, _tree.getNULL()));
			}

			reverse_iterator rbegin()
			{
				return reverse_iterator(_end);
			}

			const_reverse_iterator rbegin() const
			{
				return const_reverse_iterator(_end, _tree.getNULL());
			}

			reverse_iterator rend()
			{
				return reverse_iterator(_tree.minD(_tree.getRoot()));
			}

			const_reverse_iterator rend() const
			{
				return const_reverse_iterator(_tree.minD(_tree.getRoot()), _tree.getNULL());
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
				deleteEnd(_end);
				if (!_tree.search((*position).first))
				{
					setEnd(_end);
					return ;
				}
				Node	*tmp  = _tree.searchRetNode((*position).first);
				_tree.deleteNode(_tree.getRoot(), _tree.searchRetVal((*position).first));
				_alloc.destroy(tmp->p);
				_alloc.deallocate(tmp->p, 1);
				_nodeAlloc.destroy(tmp);
				_nodeAlloc.deallocate(tmp, 1);
				_size--;
				setEnd(_end);
			}

			size_type	erase(const key_type& k)
			{
				deleteEnd(_end);
				if (!_tree.search(k))
				{
					setEnd(_end);
					return (0);
				}
				Node	*tmp = _tree.searchRetNode(k);
				_tree.deleteNode(_tree.getRoot(), k);
				_alloc.destroy(tmp->p);
				_alloc.deallocate(tmp->p, 1);
				_nodeAlloc.destroy(tmp);
				_nodeAlloc.deallocate(tmp, 1);
				_size--;
				setEnd(_end);
				return (1);
			}

			void	erase(iterator first, iterator last)
			{
				int f = 0;
				if (first == begin() && last == end())
				{
					clear();
					return ;
				}
				if (last == this->end())
				{
					f = 1;
					last--;

				}
				deleteEnd(_end);
				if (f == 1)
				{
					while (first != last)
					{
						Node	*tmp = _tree.searchRetNode(((*first).first));
						if (!tmp)
						{
							setEnd(_end);
							return;
						}
						_tree.deleteNode(_tree._root, (*first).first);
						_size--;
						first++;
						_alloc.destroy(tmp->p);
						_alloc.deallocate(tmp->p, 1);
						_nodeAlloc.destroy(tmp);
						_nodeAlloc.deallocate(tmp, 1);
					}
					Node	*tmp = _tree.searchRetNode(((*first).first));
					if (!tmp)
					{
						setEnd(_end);
						return;
					}
					_tree.deleteNode(_tree._root, (*first).first);
					_size--;
					_alloc.destroy(tmp->p);
					_alloc.deallocate(tmp->p, 1);
					_nodeAlloc.destroy(tmp);
					_nodeAlloc.deallocate(tmp, 1);
				}
				else
				{
					last--;
					if (_ferase == 1)
						last--;
					Node	*tmp_first = _tree.searchRetNode(((*first).first));
					while (last != first)
					{
						Node	*tmp = _tree.searchRetNode(((*last).first));
						if (!tmp)
						{
							setEnd(_end);
							return;
						}
						_tree.deleteNode(_tree._root, (*last).first);
						--last;
						_size--;
						_alloc.destroy(tmp->p);
						_alloc.deallocate(tmp->p, 1);
						_nodeAlloc.destroy(tmp);
						_nodeAlloc.deallocate(tmp, 1);
					}
					_tree.deleteNode(_tree._root, tmp_first->p->first);
					_alloc.destroy(tmp_first->p);
					_alloc.deallocate(tmp_first->p, 1);
					_nodeAlloc.destroy(tmp_first);
					_nodeAlloc.deallocate(tmp_first, 1);
					_size--;
					_ferase = 0;
				}
				setEnd(_end);
			}

			pair<iterator, bool>	insert(const value_type &val)
			{
				deleteEnd(_end);
				if (_tree.searchRetNode(val.first) && _tree.getSize() > 0)
				{
					Node *tmp = _tree.searchRetNode(val.first);
					setEnd(_end);
					iterator it(tmp, _tree.getNULL());
					return (ft::make_pair<iterator, bool>(it, false));
				}
				_tree.insertNode(val);
				Node *tmp = _tree.searchRetNode(val.first);
				setEnd(_end);
				iterator it(tmp, _tree.getNULL());
				_size++;
				return (ft::make_pair<iterator, bool>(it, true));
			}

			iterator	insert(iterator position, const value_type& val)
			{
				(void)position;
				insert(val);
				deleteEnd(_end);
				Node *tmp = _tree.searchRetNode(val.first);
				setEnd(_end);
				return (iterator(tmp, _tree.getNULL()));
			}

			template <class InputIterator>
			void	insert(InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					insert(*first);
					++first;
				}
			}
			
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
				_ferase = 1;
				return first;
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
					return (iterator(_tree.searchRetNode(k), _tree.getNULL()));
				else
					return this->end();
			}

			const_iterator	find(const key_type& k) const
			{
				if (_tree.search(k))
					return (const_iterator(_tree.searchRetNode(k), _tree.getNULL()));
				else
					return this->end();
			}
			
			size_type	count(const key_type &k) const
			{
				if (_tree.search(k))
					return (1);
				return (0);
			}

			void	destroyAll(Node *node)
			{
				if (node == NULL || node == _tree.getNULL())
					return ;
				destroyAll(node->m_left);
				destroyAll(node->m_right);
			}

			void	clear(void)
			{
				_tree.deleteEndNode(_end);
				while (_tree.getSize() && _tree.getSize() != 3)
					erase(_tree.getRoot()->p->first);
				if (_tree.getSize() <= 3)
				{
					if (_tree._root->m_left)
						erase(_tree._root->m_left->p->first);
					if (_tree._root->m_right)
						erase(_tree._root->m_right->p->first);
					erase(_tree._root->p->first);
				}
				_size = 0;
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
				return _size;
			}

			Alloc	get_allocator(void) const
			{
				return (_alloc);
			}

			size_type	max_size() const
			{
				return _nodeAlloc.max_size();
			}

			mapped_type& operator[] (const key_type& k)
			{
				this->insert(ft::make_pair(k, mapped_type()));
				return (_tree.searchRetNode(k)->p->second);
			}

			class value_compare
			{
				public:
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
				return (value_compare());
			}

			void	recursiveAssignement(Node *node, const_iterator &first, const_iterator &last)
			{
				if (node == NULL)
				{
					return ;
				}
				recursiveAssignement(node->m_right, first, last);
				recursiveAssignement(node->m_left, first, last);

				while (first != last)
				{
					_tree.insertNode(*first);
					first++;
				}
			}

			map	&operator=(const map& egal)
			{
				_size = egal._size;
				deleteEnd(_end);
				
				map::const_iterator first = egal.begin();
				map::const_iterator last = egal.end();
				
				recursiveAssignement(_tree.getRoot(), first, last);
				clear();
				
				first = egal.begin();
				last = egal.end();
				while (first != last)
				{
					_tree.insertNode(*first);
					_size++;
					++first;
				}
				setEnd(_end);
				return *this;
			}

			void	swap(map& x)
			{
				Alloc	tmp_alloc = _alloc;
				Node_allocator	tmp_nodeAlloc = _nodeAlloc;
				size_type	tmp_size = _size;
				Node	*tmp_end = _end;
				RBT<key_type, mapped_type, value_type, key_compare>	tmp_tree = _tree;
				Node *tmp_NULLnode = _tree.NULLnode;

				_alloc = x._alloc;
				_nodeAlloc = x._nodeAlloc;
				_size = x._size;
				_end = x._end;
				_tree = x._tree;
				_tree.NULLnode = x._tree.NULLnode;
				
				x._tree = tmp_tree;
				x._alloc = tmp_alloc;
				x._nodeAlloc = tmp_nodeAlloc;
				x._size = tmp_size;
				x._end = tmp_end;
				x._tree.NULLnode = tmp_NULLnode;
			}

			RBT<key_type, mapped_type, value_type, key_compare, allocator_type>	_tree;
			Node_allocator	_nodeAlloc;
			Alloc	_alloc;
			Compare _comp;
			Node *_end;
			Node *_null;
			size_t	_size;
			size_t	_ferase;
	};
}

#endif
