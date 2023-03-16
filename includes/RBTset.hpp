/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTset.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:39:45 by jtaravel          #+#    #+#             */
/*   Updated: 2023/03/15 18:46:17 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTset_HPP

#define RBTset_HPP

#include <cstddef>
#include <iostream>
#include <iomanip>
#include "pair.hpp"
#include "make_pair.hpp"

namespace ft
{

enum	RBTset_color
{
	s_red = false,
	s_black = true
};

template <class T, class Compare = std::less<T>, class Allocator = std::allocator<T> >
class	RBTset
{
	typedef T		value_type;
	typedef	Compare       compare_type;
	typedef	Allocator	allocator_type;
	public:
	template <class V>
	struct 	Node
	{
		RBTset_color	m_color;
		Node		*m_parent;
		Node		*m_left;
		Node		*m_right;
		V		key;
		value_type	*p;
	
		Node(value_type *v = value_type()):m_color(s_red), m_parent(0), m_left(0), m_right(0), p(v)
		{
		}
		~Node(void)
		{
		}
		
		Node(Node const &cpy):p(cpy.p)
		{
			m_color = cpy.m_color;
			m_parent = cpy.m_parent;
			m_left = cpy.m_left;
			m_right = cpy.m_right;
			key = cpy.key;
		}

	};
	typedef typename allocator_type::template rebind<Node<T> >::other	Node_allocator;
	

	Node<T>	*getRoot(void) const
	{ return _root; }
	Node<T>	*getNULL(void) const
	{ return NULLnode; }

	void	leftRotate(Node<T> *node)
	{
		 Node<T> *tmp;

		 if (!node->m_right)
			 node->m_right = NULLnode;
		 tmp = node->m_right;
		 node->m_right = tmp->m_left;
		 if(tmp->m_left != NULL && tmp->m_left != NULLnode)
		 {
			 tmp->m_left->m_parent = node;
		 }
		 tmp->m_parent = node->m_parent;
		 if (node->m_parent == NULL)
			 _root = tmp;
		 else if (node == node->m_parent->m_left)
			 node->m_parent->m_left = tmp;
		 else
			 node->m_parent->m_right = tmp;
		 tmp->m_left = node;
		 node->m_parent = tmp;


	}
	
	void	rightRotate(Node<T> *node)
	{
		Node<T> *tmp;


		tmp = node->m_left;
		node->m_left = tmp->m_right;
		if (tmp && tmp->m_right != NULL && tmp->m_right != NULLnode)
		{
			tmp->m_right->m_parent = node;
		}
		tmp->m_parent = node->m_parent;
		if (node->m_parent == NULL)
		{
			_root = tmp;
		}
		else if (node == node->m_parent->m_right)
		{
			node->m_parent->m_right = tmp;
		}
		else
			node->m_parent->m_left = tmp;
		tmp->m_right = node;
		node->m_parent = tmp;
	}

	void	insertionFix(Node<T> *newN)
	{
		Node<T>	*tmp;
		
		while(newN->m_parent->m_color == s_red)
		{
			if (newN->m_parent == newN->m_parent->m_parent->m_left)
			{
				tmp = newN->m_parent->m_parent->m_right;
				if (tmp && tmp->m_color == s_red)
				{
					tmp->m_color = s_black;
					newN->m_parent->m_color = s_black;
					newN->m_parent->m_parent->m_color = s_red;
					newN = newN->m_parent->m_parent;
				}
				else
				{
					if (newN == newN->m_parent->m_right)
					{
						newN = newN->m_parent;
						leftRotate(newN);
					}
					newN->m_parent->m_color = s_black;
					newN->m_parent->m_parent->m_color = s_red;
					rightRotate(newN->m_parent->m_parent); 
				}
			}
			else
			{
				tmp = newN->m_parent->m_parent->m_left;
				if (tmp && tmp->m_color == s_red)
				{
					tmp->m_color = s_black;
					newN->m_parent->m_color = s_black;
					newN->m_parent->m_parent->m_color = s_red;
					newN = newN->m_parent->m_parent;
				}
				else
				{
					if (newN == newN->m_parent->m_left)
					{
						newN = newN->m_parent;
						rightRotate(newN);
					}
					newN->m_parent->m_color = s_black;
					newN->m_parent->m_parent->m_color = s_red;
					leftRotate(newN->m_parent->m_parent);

				}
			}
			if (newN == _root)
			{
				break ;
			}
		}
		_root->m_color = s_black;
	}

	Node<T> *newNode(const value_type &v = value_type())
	{
		Node<T> *tmp = _alloc.allocate(1);
		value_type	*test;
		 test = _destroyer.allocate(1);
		 _destroyer.construct(test, v);
		_alloc.construct(tmp, test);
		return tmp;
	}

	void	insertNode(const value_type &node)
	{
		Node<T>	*newN = newNode(node);
		
		if (_root)
			_root->m_parent = NULL;
		/*newN->key = k;*/
		newN->m_parent = NULL;
		newN->m_left = NULL;
		newN->m_right = NULL;
		newN->m_color = s_red;

		Node<T> 	*x = _root;
		Node<T>		*y = NULL;

		while (x != NULL && x != NULLnode)
		{
			y = x;
			if (newN->p && *newN->p == *x->p && _size > 0)
				return ;
			if (newN->p && _comp(*newN->p, *x->p))
			{
				x = x->m_left;
			}
			else
				x = x->m_right;
		}
		newN->m_parent = y;
		if (_size == 0 || y == NULL)
		{
			if (_c == 0)
				destroyNODE(_root);
			_c = 1;
			newN->m_color = s_black;
			_root = newN;
			_root->m_color = s_black;
			_root->m_parent = NULL;
		}
		else if (newN->p && _comp(*newN->p, *y->p))
		{
			y->m_left = newN;
		}
		else if (newN->p && _comp(*y->p, *newN->p))
		{
			y->m_right = newN;
		}
		else
		{
			 y->m_right = newN;
			 newN->m_left = NULLnode;
			 newN->m_right = NULLnode;
			 newN->m_color = s_red;
		}
		_size++;
		if (newN->m_parent == NULL)
		{
			return;
		}
		if (newN->m_parent->m_parent == NULL)
		{
			return;
		}
		insertionFix(newN);
	}

	void	deletionFix(Node<T> *x)
	{
		
		 Node<T> *tmp;
		 while (x && x != _root && x->m_color == s_black)	 
		 {
			 if (x == x->m_parent->m_left)
			 {
				tmp = x->m_parent->m_right;
				if (!tmp)
					tmp = NULLnode;
				if (tmp && tmp->m_color == s_red)
				{
					tmp->m_color = s_black;
					x->m_parent->m_color = s_red;
					leftRotate(x->m_parent);
					tmp = x->m_parent->m_right;
				}
				if (tmp && tmp->m_right && tmp->m_left && tmp->m_left->m_color == s_black && tmp->m_right->m_color == s_black)
				{
					tmp->m_color = s_red;
					x = x->m_parent;
				}
				else
				{
					if (tmp && tmp->m_right && tmp->m_left && tmp->m_right->m_color == s_black)
					{
						tmp->m_left->m_color = s_black;
						tmp->m_color = s_red;
						rightRotate(tmp);
						tmp = x->m_parent->m_right;
					}
					tmp->m_color = x->m_parent->m_color;
					x->m_parent->m_color = s_black;
					if (!tmp->m_right)
						tmp->m_right = NULLnode;
					tmp->m_right->m_color = s_black;
					leftRotate(x->m_parent);
					x = _root;
				}
			 }
			else
			{
				tmp = x->m_parent->m_left;
				if (!tmp)
					tmp = NULLnode;
				if (tmp->m_color == s_red)
				{
					tmp->m_color = s_black;
					x->m_parent->m_color = s_red;
					rightRotate(x->m_parent);
					tmp = x->m_parent->m_left;
				}
				if (tmp->m_left && tmp->m_right && tmp->m_right->m_color == s_black && tmp->m_left->m_color == s_black)
				{
					tmp->m_color = s_red;
					x = x->m_parent;
				}
				else
				{
					if (tmp->m_left && tmp->m_left->m_color == s_black)
					{
						tmp->m_right->m_color = s_black;
						tmp->m_color = s_red;
						leftRotate(tmp);
						tmp = x->m_parent->m_left;
					}
					tmp->m_color = x->m_parent->m_color;
					x->m_parent->m_color = s_black;
					if (!tmp->m_left)
						tmp->m_left = NULLnode;
					tmp->m_left->m_color = s_black;
					rightRotate(x->m_parent);
					x = _root;
				}
			 }
		 }
		 if (x)
		 	x->m_color = s_black;
	}

	void	SetCorrect(Node<T> *node)
	{
		if (node == NULL || node == NULLnode)
			return ;
		if (node->m_left && node->m_left != NULLnode && node->m_left->m_parent != node)
			std::cout << "SOUCIS A GAUCHE\n";
		if (node->m_right && node->m_right != NULLnode && node->m_right->m_parent != node)
			std::cout << "SOUCIS A DROITE\n";
		SetCorrect(node->m_left);	
		SetCorrect(node->m_right);	
	}

	void	swap(Node<T> *x, Node<T> *y)
	{
		if (y == NULL)
			y = NULLnode;
		if (x->m_parent == NULL)
		{
			_root = y;
		}
		else if (x == x->m_parent->m_left)
		{
			x->m_parent->m_left = y;
		}
		else
		{
			x->m_parent->m_right = y;
		}
		y->m_parent = x->m_parent;
	}

	Node<T>	*minTree(Node<T> *node)
	{
		if (node != NULLnode && node != NULL)
		{
			while (node->m_left != NULL && node->m_left != NULLnode)
				node = node->m_left;
		}
		return (node);
	}

	Node<T>	*maxTree(Node<T> *node)
	{
		while (node && node != NULLnode && node->m_right != NULLnode)
			node = node->m_right;
		return (node);
	}

	int	deleteNode(Node<T> *delN, T const &key)
	{
	(void)delN;
		Node<T> *tmp = NULLnode;
		Node<T> *x;
		tmp = searchRetNode(key);
		Node<T> *y;
		if (tmp && *tmp->p == key)
		{
			_size--;
			y = tmp;
			int y_color = y->m_color;
			if (tmp->p == _root->p && _size == 2 && _root->m_left && _root->m_right)
			{
				_root = tmp->m_left;
				_root->m_parent = NULL;
				_root->m_left = NULL;
				_root->m_right = tmp->m_right;
				return (1);
			}
			if (tmp->m_parent && (tmp->m_left == NULL || tmp->m_left == NULLnode) && (tmp->m_right == NULL || tmp->m_right == NULLnode))
			{
				if (tmp == tmp->m_parent->m_left)
					tmp->m_parent->m_left = NULL;
				else
					tmp->m_parent->m_right = NULL;
				return 1;
			}
			if (tmp->m_left == NULL || tmp->m_left == NULLnode)
			{
				x = tmp->m_right;
				swap(tmp, tmp->m_right);
			}
			else if (tmp->m_right == NULL || tmp->m_right == NULLnode)
			{
				x = tmp->m_left;
				swap(tmp, tmp->m_left);
			}
			else
			{
				y = minTree(tmp->m_right);
				y_color = y->m_color;
				x = y;
				if (y->m_parent == tmp)
				{
					x->m_parent = y;
				}
				else
				{
					swap(y, y->m_right);
					y->m_right = tmp->m_right;
					y->m_right->m_parent = y;
				}
				swap(tmp, y);
				y->m_left = tmp->m_left;
				y->m_left->m_parent = y;
				y->m_color = tmp->m_color;
			}
			if (y_color == s_black)
			{
				deletionFix(x);
			}
			return (1);
		}
		else	
		{
			return 0;
		}
	}

	int	search(const T &key) const
	{
		Node<T> *tmp = _root;
		while (tmp != NULLnode && tmp != NULL && tmp)
                {
			if (*tmp->p == key)
				return 1;
			if (*tmp->p > key)
                                tmp = tmp->m_left;
                        else
                                tmp = tmp->m_right;
                }
		return (0);
	}

	T	searchRetVal(const T &key) const
	{
		Node<T> *tmp = _root;
		while (tmp && tmp != NULLnode)
                {
			if (*tmp->p == key)
				return *tmp->p;
			if (*tmp->p > key)
				tmp = tmp->m_left;
			else
                                tmp = tmp->m_right;
                }
		return (0);
	}

	Node<T>	*searchRetNode(const T &key) const
	{
		Node<T> *tmp = _root;
		while (tmp != NULL && tmp->p && tmp != NULLnode)
                {
			if (tmp && _comp(*tmp->p, key))
                               tmp = tmp->m_right;
			else if (tmp && _comp(key, *tmp->p ))
				tmp = tmp->m_left;
			else
				break ;
                }
		if (tmp && *tmp->p == key)
			return tmp;
		return (0);
	}

	Node<T>	*minD(Node<T> *node) const
	{
		if (node == NULL || _size == 0)
		{
			return (0);
		}
		while (node && node->m_left != NULL && node != NULLnode)
		{
			node = node->m_left;
		}
		return (node);
	}

	Node<T>	*maxDendUpdate(Node<T> *node) const
	{
		if (_size == 0 || _size == 1)
			return _root;
		if (node == NULL)
			return (node);
		while (node && node->m_right != NULL && node != NULLnode && node->m_right != NULLnode)
		{
			node = node->m_right;
		}
		return (node->m_parent);
	}

	Node<T>	*maxD(Node<T> *node) const
	{
		if (_size == 0 || _size == 1)
			return _root;
		if (node == NULL)
			return (node);
		while (node && node->m_right != NULL && node != NULLnode && node->m_right != NULLnode)
		{
			node = node->m_right;
		}
		return (node);
	}
	Node<T>	*RetEnd(Node<T> *node, Node<T> *end)
	{
		if (node == 0)
			return (0);
		while (node != NULLnode && node && node->m_right && node->m_right != NULLnode && node->m_right != end)
			node = node->m_right;
		return (node);
	}


	void	deleteEndNode(Node<T> *end)
	{

		Node<T>	*tmp_max = RetEnd(_root, end);

		if (tmp_max != 0)
			tmp_max->m_right = 0;
	}
	
	void	setEndNode(Node<T> *end)
	{
		Node<T> *tmp_max = RetEnd(_root, end);
		if (tmp_max != 0)
		{
			tmp_max->m_right = end;
			end->m_parent = tmp_max;
			end->m_right = NULLnode;
		}
	}

	void	setNullNode(Node<T> *node)
	{
		if (node && _size > 0)
		{
			if (!node->m_left || node->m_left == NULLnode)
			{
				std::cout << "gauche null: " << node->p << "\n";
				node->m_left = NULLnode;
			}
			else
				setNullNode(node->m_left);
			if (!node->m_right || node->m_right == NULLnode)
			{
				std::cout << "droit null: " << node->p << "\n";
				node->m_right = NULLnode;
			}
			else
				setNullNode(node->m_right);
		}
		return ;
	}

	size_t	countElem(Node<T> *node, int mode) const
	{
		Node<T>	*tmp = node;
		static size_t	c;
		
		if (mode == 0)
		{
			c = 0;
			return 0;
		}
                if (!tmp || tmp == NULLnode)
                        return c;
		c++;
                countElem(tmp->m_right, 1);
                countElem(tmp->m_left, 1);
		return (c);
	}

	RBTset(void)
	{
		NULLnode = newNode();
		NULLnode->m_color = s_black;
		NULLnode->m_parent = NULL;
		NULLnode->m_left = NULL;
		NULLnode->m_right = NULL;
		_root = newNode();
		_root->m_parent = NULL;
		_root->m_left = NULLnode;
		_root->m_right = NULLnode;
		_root->m_color = s_black;
		_size = 0;
		_c = 0;
	}

	void	destroyNODE(Node<T> *node)
	{
		_destroyer.destroy(node->p);
		_destroyer.deallocate(node->p, 1);
		_alloc.destroy(node);
		_alloc.deallocate(node, 1);
	}

	void	destroyTOUT(Node<T> *node)
	{
		if (!node || node == NULLnode)
			return ;
		destroyTOUT(node->m_left);
		destroyTOUT(node->m_right);
		_destroyer.destroy(node->p);
		_destroyer.deallocate(node->p, 1);
		_alloc.destroy(node);
		_alloc.deallocate(node, 1);
	}

	~RBTset(void)
	{

	}

	Node<T>	*getLast(void)
	{
		return _last;
	}
	
	size_t	getSize(void) const
	{
		return _size;
	}

	void	setRoot(Node<T> *root)
	{
		_root = root;
	}

		Node<T> *_root;
		Node<T> *NULLnode;
	private:
		Node<T> *_last;
		compare_type	_comp;
		Node_allocator	_alloc;
		allocator_type	_destroyer;
		size_t		_size;
		size_t		_c;
};
}


#endif
