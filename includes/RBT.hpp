/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:39:45 by jtaravel          #+#    #+#             */
/*   Updated: 2023/02/22 19:18:30 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP

#define RBT_HPP

#include <cstddef>
#include <iostream>
#include "pair.hpp"
//#include "map.hpp"

namespace ft
{

enum	RBT_color
{
	s_red = false,
	s_black = true
};



template <class T, class U, typename P, class Compare = std::less<T>, class Allocator = std::allocator<P> >
class	RBT
{
	typedef ft::pair<const T, U>       value_type;
	typedef	Compare       compare_type;
	typedef	Allocator	allocator_type;
	public:
	template <class V>
	struct	Node
	{
		RBT_color	m_color;
		Node		*m_parent;
		Node		*m_left;
		Node		*m_right;
		V		key;
		value_type	p;
	
		Node(const value_type &v = value_type()):key(v.second), m_color(s_black), m_parent(NULL), m_right(NULL), m_left(NULL), p(v)
		{
		}
	};
	typedef typename allocator_type::template rebind<Node<T>>::other	Node_allocator;
	

	Node<T>	*getRoot(void) const
	{ return _root; }
	Node<T>	*getNULL(void) const
	{ return NULLnode; }
	void	initNode(Node<T> *node)
	{
		node = new Node<T>;
		node->m_parent = NULL;
		node->m_left = NULL;
		node->m_right = NULL;
		node->m_color = s_black;
		node = NULL;
	}

	void	ft_test(void)
	{
		std::cout << "salut\n";
		//std::cout << "TTTTTTTT: " << P->second;
	}

	void	leftRotate(Node<T> *node)
	{
		 Node<T> *tmp;

		 tmp = node->m_right;
		 node->m_right = tmp->m_left;
		 if(tmp->m_left != NULL)
		 {
			 tmp->m_left->m_parent = node;
		 }
		 tmp->m_parent = node->m_parent;
		 if (node->m_parent == NULL)
		 {
			 _root = tmp;
		 }
		 else if (node == node->m_parent->m_left)
		 {
			 node->m_parent->m_left = tmp;
		 }
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
		if (tmp->m_right != NULL)
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
				std::cout << "cas 1   ->  " << newN->key << "\n";
				tmp = newN->m_parent->m_parent->m_right;
				//if (newN->m_parent->m_parent->m_right->m_color == s_red)
				if (tmp && tmp->m_color == s_red)
				{
					std::cout << "cas 1 --- 1   ->  " << newN->key << "\n";
					tmp->m_color = s_black;
					newN->m_parent->m_color = s_black;
					//newN->m_parent->m_right->m_color = s_black;
					//newN->m_parent->m_left->m_color = s_black;
					newN->m_parent->m_parent->m_color = s_red;
					newN = newN->m_parent->m_parent;
				}
				else
				{
					std::cout << "cas 1 --- 2   ->  " << newN->key << "\n";
					if (newN == newN->m_parent->m_right)
					{
						std::cout << "cas 1 --- 3   ->  " << newN->key << "\n";
						newN = newN->m_parent;
						leftRotate(newN);
					}
				//else
				//{
					newN->m_parent->m_color = s_black;
					newN->m_parent->m_parent->m_color = s_red;
					rightRotate(newN->m_parent->m_parent); 
				}
			}
			else
			{
				std::cout << "cas 2   ->  " << newN->key << "\n";
				tmp = newN->m_parent->m_parent->m_left;
				if (tmp && tmp->m_color == s_red)
				{
					std::cout << "cas 2 --- 1   ->  " << newN->key << "\n";
					tmp->m_color = s_black;
					newN->m_parent->m_color = s_black;
					newN->m_parent->m_parent->m_color = s_red;
					newN = newN->m_parent->m_parent;
				}
				else
				{
					std::cout << "cas 2 --- 2   ->  " << newN->key << "\n";
					if (newN == newN->m_parent->m_left)
					{
						std::cout << "cas 2 --- 3   ->  " << newN->key << "\n";
						newN = newN->m_parent;
						rightRotate(newN);
					}
					newN->m_parent->m_color = s_black;
					newN->m_parent->m_parent->m_color = s_red;
					leftRotate(newN->m_parent->m_parent); 
				}
			}
			if (newN == _root)
				break ;
		}
		_root->m_color = s_black;
	}

	Node<T> *newNode(const value_type& v = value_type())
	{
		Node<T> *tmp = _alloc.allocate(1);
		_alloc.construct(tmp, Node<T>(v));
		return tmp;
	}

	void	insertNode(const value_type &node)
	{
		Node<T>	*newN = newNode(node);
		
		/*newN->key = k;*/
		//newN->m_parent = nullptr;
		newN->m_left = NULL;
		newN->m_right = NULL;
		newN->m_color = s_red;

		Node<T> 	*x = _root;
		Node<T>		*y = nullptr;

		std::cout << "debut insert: " << newN->p.first << "\n";
		std::cout << "root debut insert: " << _root->p.first << "\n";
		while (x != NULL)
		{
			y = x;
			std::cout << "NEW: " << newN->p.first << "\n";
			std::cout << "X: " << x->p.first << "\n";
			if (_comp(newN->p.first, x->p.first))
			{
				x = x->m_left;
			}
			else
				x = x->m_right;
		}
		std::cout << "yyyy: " << y->p.first << "\n";
		newN->m_parent = y;
		if (y == NULLnode)
		{
			std::cout << "ppppppp\n";
			newN->m_color = s_black;
			_root = newN;
			_root->m_color = s_black;
		}
		else if (newN->key < y->key)
		{
			y->m_left = newN;
		}
		else if (newN->key > y->key)
			y->m_right = newN;
		else
		{
			 y->m_right = newN;
			 newN->m_left = NULLnode;
			 newN->m_right = NULLnode;
			 newN->m_color = s_red;
		}
			/*Node<T>	*tmp = _root;
			while (1)
			{
				if (tmp->m_left && k < tmp->key)
				{
					tmp = tmp->m_left;
				}
				else if (!tmp->m_left && k < tmp->key)
				{
					tmp->m_left = newN;
					break;
				}
				if (tmp->m_right && k > tmp->key)
				{
					tmp = tmp->m_right;
				}
				else if (!tmp->m_right && k > tmp->key)
				{
					tmp->m_right = newN;
					break;
				}
			}
		}*/
		if (newN->m_parent == NULL)
			return;
		if (newN->m_parent->m_parent == NULL)
			return;
		insertionFix(newN);
	}

	void	deletionFix(Node<T> *x)
	{
		std::cout << "x in delete fix: " << x->key << "\n";
		 Node<T> *tmp;
		 while (x != _root  && x->m_color == s_black)	 
		 {
			 if (x == x->m_parent->m_left)
			 {
				tmp = x->m_parent->m_right;
				if (x->m_parent->m_right->m_color == s_red)
				{
					tmp->m_color = s_black;
					x->m_parent->m_color = s_red;
					leftRotate(x->m_parent);
					tmp = x->m_parent->m_left;
				}
				if (tmp->m_left->m_color == s_black && tmp->m_right->m_color == s_black)
				{
					tmp->m_color = s_red;
					x = x->m_parent;
				}
				else if (tmp->m_right->m_color == s_black)
				{
					tmp->m_left->m_color = s_black;
					tmp->m_color = s_red;
					rightRotate(tmp);
					tmp = x->m_parent->m_right;
				}
				//else
				//{
					tmp->m_color = x->m_parent->m_color;
					x->m_parent->m_color = s_black;
					tmp->m_right->m_color = s_black;
					leftRotate(x->m_parent);
					x = _root;
				//}
			 }
			 else if (x == x->m_parent->m_right)
			 {
				tmp = x->m_parent->m_left;
				if (x->m_parent->m_left->m_color == s_red)
				{
					tmp->m_color = s_black;
					x->m_parent->m_color = s_red;
					leftRotate(x->m_parent);
					tmp = x->m_parent->m_right;
				}
				if (tmp->m_right->m_color == s_black && tmp->m_left->m_color == s_black)
				{
					tmp->m_color = s_red;
					x = x->m_parent;
				}
				else if (tmp->m_left->m_color == s_black)
				{
					tmp->m_right->m_color = s_black;
					tmp->m_color = s_red;
					rightRotate(tmp);
					tmp = x->m_parent->m_left;
				}
					tmp->m_color = x->m_parent->m_color;
					x->m_parent->m_color = s_black;
					tmp->m_left->m_color = s_black;
					leftRotate(x->m_parent);
					x = _root;
			 }
		 }
		 x->m_color = s_black;
	}

	void	swap(Node<T> *x, Node<T> *y)
	{
		std::cout << "Swap x: " << x->key << "\n";
		std::cout << "Swap y: " << y->key << "\n";
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
		while (node->m_left != NULLnode)
			node = node->m_left;
		return (node);
	}

	Node<T>	*maxTree(Node<T> *node)
	{
		while (node->m_right != NULLnode)
			node = node->m_right;
		return (node);
	}
	
	void	deleteNode(Node<T> *delN, T const &key)
	{
		Node<T> *tmp = NULLnode;
		Node<T> *x;
		Node<T> *y;
		while (delN != NULLnode)
		{
			if (delN->key == key)
				tmp = delN;
			if (delN->key <= key)
				delN = delN->m_right;
			else
				delN = delN->m_left;
		}
		std::cout << "ooooo: " << tmp->key << "\n";
		if (tmp->key == key)
		{
			std::cout << "FIND\n";
			y = tmp;
			int y_color = y->m_color;
			if (tmp->m_left == NULLnode)
			{
				std::cout << "laaaaa\n";
				x = tmp->m_right;
				swap(tmp, tmp->m_right);
			}
			else if (tmp->m_right == NULLnode)
			{
				std::cout << "right NULL\n";
				x = tmp->m_left;
				swap(tmp, tmp->m_left);
			}
			else
			{
				std::cout << "Gros while dans delete\n";
				/*Node *test = tmp->m_right;
				while (test->m_left != NULLnode)
				{
					std::cout << "test\n";
					test = test->m_left;
				}
				y = test;*/
				std::cout << "y avant minTree: " << y->key << "\n";
				y = minTree(tmp->m_right);
				y_color = y->m_color;
				x = y->m_right;
				std::cout << "DEL/tmp debut gros while: " << tmp->key << "\n";
				std::cout << "x debut gros while: " << x->key << "\n";
				std::cout << "y debut gros while: " << y->key << "\n";
				std::cout << "Parent de x debut gros while: " << x->m_parent->key << "\n";
				std::cout << "Parent de y debut gros while: " << y->m_parent->key << "\n";
				if (y->m_parent == tmp)
				{
					std::cout << "1111 if dans ELSE: x->m_parent: " << x->m_parent->key << "\n";
					x->m_parent = y;
					std::cout << "2222 if dans ELSE: x->m_parent: " << x->m_parent->key << "\n";
				}
				else
				{
					std::cout << "SWAP petit else dans gros else\n";
					swap(y, y->m_right);
					y->m_right = tmp->m_right;
					y->m_right->m_parent = y;
				}
				swap(tmp, y);
				y->m_left = tmp->m_left;
				y->m_left->m_parent = y;
				y->m_color = tmp->m_color;
			}
			delete tmp;
			if (y_color == s_black)
			{
				std::cout << "go in fix deletion\n";
				deletionFix(x);
			}
		}
		else	
		{
			std::cout << "NO find\n";
			return ;
		}
	}

	int	search(const T &key) const
	{
		std::cout << "key search: " << key << "\n";
		int	flag = 0;
		Node<T> *tmp = _root;
		while (tmp != NULL)
                {
                        if (tmp && tmp->key == key)
			{
				flag = 1;
			}
                        if (tmp && tmp->key <= key)
                                tmp = tmp->m_right;
                        else
                                tmp = tmp->m_left;
                }
		if (flag == 1)
			return (1);
		return (0);
	}

	T	searchRetVal(const T &key) const
	{
		std::cout << "key search: " << key << "\n";
		int	flag = 0;
		Node<T> *tmp = _root;
		while (tmp != NULLnode)
                {
                        if (tmp->key == key)
			{
				flag = 1;
			}
                        if (tmp->key <= key)
                                tmp = tmp->m_right;
                        else
                                tmp = tmp->m_left;
                }
		if (flag == 1)
			return (tmp->key);
		return (0);
	}

	Node<T>	*minD(Node<T> *node)
	{
		while (node->m_left != NULL)
			node = node->m_left;
		return (node);
	}

	Node<T>	*maxD(Node<T> *node)
	{
		while (node->m_right != NULLnode)
			node = node->m_right;
		return (node);
	}

	void	destroyAll(void)
	{
		_root = minD(_root->m_left);
		_root = NULLnode;
		//_root = maxD(_root->m_right);
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
	
	RBT(void)
	{
		NULLnode = newNode();
		NULLnode->m_color = s_black;
		NULLnode->m_left = NULL;
		NULLnode->m_right = NULL;
		_root = newNode();
		_root->m_color = s_black;
		_root->m_left = NULLnode;
		_root->m_right = NULLnode;
		std::cout << "salut\n";
	}
	private:
		Node<T> *_root;
		Node<T> *NULLnode;
		compare_type	_comp;
		Node_allocator	_alloc;
};
}


#endif
