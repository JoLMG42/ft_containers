/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:54:03 by jtaravel          #+#    #+#             */
/*   Updated: 2023/03/15 18:48:19 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP

#define SET_HPP

#include "pair.hpp"
#include "RBTset.hpp"
#include "iterator_traits.hpp"
#include "make_pair.hpp"
#include "reverse_iterator.hpp"
#include <iomanip>
#include "equal.hpp"
#include "lexicographical_compare.hpp"

namespace ft
{

template< class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	class set
	{
		template <class U, class V>
		class set_iterator
		{

			public:
				typedef U		value_type;
				typedef ptrdiff_t	difference_type;
				typedef U*		pointer;
				typedef U&		reference;
				typedef ft::bidirectional_iterator_tag  iterator_category;

				set_iterator(V *ptr = 0 , V *null = NULL): _ptr(ptr), _null(null)
				{
				}

				set_iterator(set_iterator const &cpy)
				{
					_null = cpy._null;
					_ptr = cpy._ptr;
				}
				~set_iterator(void)
				{
				}

				set_iterator	&operator=(set_iterator const &egal)
				{
					_ptr = egal._ptr;
					return *this;
				}
				pointer	operator->() const
				{
					return (_ptr->p);
				}

				set_iterator &operator++()
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

				set_iterator operator++(int)
				{
					set_iterator tmp(*this);
					++(*this);
					return tmp;
				}

				set_iterator &operator--()
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

				set_iterator operator--(int)
				{
					set_iterator tmp(*this);
					--(*this);
					return tmp;
				}

				reference	operator*() const
				{
					return *(_ptr->p);
				}

				friend bool operator==(const set_iterator &lhs, const set_iterator &rhs)
				{
					return (lhs._ptr == rhs._ptr);
				}
				friend bool operator!=(const set_iterator &lhs, const set_iterator &rhs)
				{
					return (lhs._ptr != rhs._ptr);
				}

				operator	set_iterator<const value_type, V>() const
				{
					return set_iterator<const value_type, V>(_ptr);
				}

			private:
				V *_ptr;
				V *_null;

		};
		public:
			typedef T					key_type;
			typedef	T					mapped_type;
			typedef T					value_type;
			typedef	Compare					key_compare;
			typedef	size_t					size_type;
			typedef	Alloc					allocator_type;
			typedef	typename allocator_type::reference		reference;
			typedef	typename allocator_type::const_reference		const_reference;
			typedef	typename allocator_type::pointer			pointer;
			typedef	typename allocator_type::const_pointer		const_pointer;
			typedef	typename ft::RBTset<key_type, key_compare, allocator_type>::template Node<key_type> Node;
			typedef set_iterator<const value_type, Node>				const_iterator;
			typedef	const_iterator							iterator;
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

                /*if (tmp_min != 0)
                {
                        tmp_min->_left = nodemin;
                        nodemin->_father = temp_min;
                }*/
                if (tmp_max != 0)
                {
                        tmp_max->m_right = end;
                        end->m_parent = tmp_max;
                        end->m_right = _tree.getNULL();
                }


                /*Node<T>       *tmp = _root;

                while (tmp->m_right && tmp->m_right != NULLnode)
                        tmp = tmp->m_right;
                std::cout << "NEW SET END::::::: " << tmp->p.first << "\n";
                _last = NULLnode;
                tmp->m_right = _last;
                _last->m_parent = tmp;*/
        }

	        void    deleteEnd(Node *end)
        {

                Node *tmp_max = RetEnd(_tree._root, end);

                if (tmp_max != 0)
                        tmp_max->m_right = 0;


                /*Node<T>       *tmp = _root;
                if (_size == 1)
                {
                        _root->m_right = NULL;
                        return ;
                }

                while (tmp->m_right && tmp->m_right != NULLnode)
                {
                        std::cout << "DANS WHILE DELETE END NODE tmp->m_right: " << tmp->p.first << "\n";
                        tmp = tmp->m_right;
                }
                std::cout << "APRES WHILE DELETE END NODE tmp->m_right: " << tmp->m_parent->p.first << "\n";
                std::cout << "APRES WHILE DELETE END NODE tmp->m_right: " << tmp->p.first << "\n";
                tmp->m_parent->m_right->m_right = NULL;*/
        }




			explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _nodeAlloc(Node_allocator())
			{
				_alloc = alloc;
				_comp = comp;
				_end = makeNode();
				_size = 0;
				_ferase = 0;
				/*_last = _tree.newNode();
				_last->m_left = _tree.getNULL();
				_last->m_right = _tree.getNULL();
				_last->m_parent = _tree.getRoot();
				_tree.getRoot()->m_right = _last;*/
			}

			set(const set& cpy)
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

			~set(void)
			{
				_alloc.destroy(_end->p);
				_alloc.deallocate(_end->p, 1);
				_nodeAlloc.destroy(_end);
				_nodeAlloc.deallocate(_end, 1);
				deleteEnd(_end);
				_tree.destroyTOUT(_tree._root);
				_tree.destroyNODE(_tree.getNULL());
			}

			friend bool operator==(const set& lhs, const set& rhs)
			{
				if (lhs.size() == rhs.size())
					return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
				return (false);
			}
			friend bool operator!=(const set& lhs, const set& rhs)
			{
				return (!(lhs == rhs));
			}
			friend bool operator<(const set& lhs, const set& rhs)
			{
				return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
			}
			friend bool operator<=(const set& lhs, const set& rhs)
			{
				return (!(rhs < lhs));
			}
			friend bool operator>(const set& lhs, const set& rhs)
			{
				return (rhs < lhs);
			}
			friend bool operator>=(const set& lhs, const set& rhs)
			{
				return (!(lhs < rhs));
			}

			friend	void swap(set<T, Compare,Alloc>& x, set<T, Compare,Alloc>& y)
			{
				x.swap(y);	
			}

			        void    real_print(Node *ptr, int space, RBTset<key_type, key_compare> test)
        {
                if (!ptr || ptr == test.getNULL())
                {
                        return;
                }
                space += 4;
                real_print(ptr->m_right, space, test);
                std::cout
                        << (ptr->m_color == ft::s_black ? "\033[90m" : "\033[31m") << std::setw(space)
                        << ptr->p->first << "\033[0m" << std::endl;
                real_print(ptr->m_left, space, test);
        }

			template <class InputIterator>
			set(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{
				_comp = comp;
				_alloc = alloc;
				_end = makeNode();
				_size = 0;
				_ferase = 0;
				/*_last = _tree.newNode();
				_last->m_left = _tree.getNULL();
				_last->m_right = _tree.getNULL();
				_last->m_parent = _tree.getRoot();
				_tree.getRoot()->m_right = _tree.getLast();*/
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
				if (!_tree.search((*position)))
				{
					setEnd(_end);
					return ;
				}
				Node	*tmp  = _tree.searchRetNode((*position));
				_tree.deleteNode(_tree.getRoot(), _tree.searchRetVal((*position)));
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
						Node	*tmp = _tree.searchRetNode(((*first)));
						if (!tmp)
						{
							setEnd(_end);
							return;
						}
						_tree.deleteNode(_tree._root, (*first));
						_size--;
						first++;
						_alloc.destroy(tmp->p);
						_alloc.deallocate(tmp->p, 1);
						_nodeAlloc.destroy(tmp);
						_nodeAlloc.deallocate(tmp, 1);
					}
					Node	*tmp = _tree.searchRetNode(((*first)));
					if (!tmp)
					{
						setEnd(_end);
						return;
					}
					_tree.deleteNode(_tree._root, (*first));
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
					Node	*tmp_first = _tree.searchRetNode(((*first)));
					while (last != first)
					{
						Node	*tmp = _tree.searchRetNode(((*last)));
						if (!tmp)
						{
							setEnd(_end);
							return;
						}
						_tree.deleteNode(_tree._root, (*last));
						--last;
						_size--;
						_alloc.destroy(tmp->p);
						_alloc.deallocate(tmp->p, 1);
						_nodeAlloc.destroy(tmp);
						_nodeAlloc.deallocate(tmp, 1);
					}
					_tree.deleteNode(_tree._root, *tmp_first->p);
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
				if (_tree.searchRetNode(val) && _tree.getSize() > 0)
				{
					Node *tmp = _tree.searchRetNode(val);
					setEnd(_end);
					iterator it(tmp, _tree.getNULL());
					return (ft::make_pair<iterator, bool>(it, false));
				}
				_tree.insertNode(val);
				Node *tmp = _tree.searchRetNode(val);
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
				Node *tmp = _tree.searchRetNode(val);
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
					if (!_comp((*first), k))
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
					if (!_comp((*first), k))
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
					if (_comp(k, (*first)))
					{
						break ;
					}
					first++;
				}
				_ferase = 1;
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
					if (_comp(k, (*first)))
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
				{
					erase(*_tree.getRoot()->p);
				}
				if (_tree.getSize() <= 3)
				{
					if (_tree._root->m_left)
						erase(*_tree._root->m_left->p);
					if (_tree._root->m_right)
						erase(*_tree._root->m_right->p);
					erase(*_tree._root->p);
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
						return comp(x, y);
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

			set	&operator=(const set& egal)
			{
				_size = egal._size;
				deleteEnd(_end);
				
				set::const_iterator first = egal.begin();
				set::const_iterator last = egal.end();
				
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

			void	swap(set& x)
			{
				Alloc	tmp_alloc = _alloc;
				Node_allocator	tmp_nodeAlloc = _nodeAlloc;
				size_type	tmp_size = _size;
				Node	*tmp_end = _end;
				RBTset<key_type, key_compare>	tmp_tree = _tree;
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

			RBTset<key_type, key_compare, allocator_type>	_tree;
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
