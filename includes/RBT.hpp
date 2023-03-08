/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:39:45 by jtaravel          #+#    #+#             */
/*   Updated: 2023/03/08 19:19:13 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP

#define RBT_HPP

#include <cstddef>
#include <iostream>
#include "pair.hpp"
#include "make_pair.hpp"
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
	typedef P		value_type;
	typedef	Compare       compare_type;
	typedef	Allocator	allocator_type;
	public:
	template <class V>
	struct 	Node
	{
		RBT_color	m_color;
		Node		*m_parent;
		Node		*m_left;
		Node		*m_right;
		V		key;
		value_type	*p;
	
		Node(value_type *v = value_type()):m_color(s_red), m_parent(0), m_left(0), m_right(0), p(v)
		{
		}
		
		/*Node(Node const &cpy):p(cpy.p)
		{
			m_color = cpy.m_color;
			m_parent = cpy.m_parent;
			m_left = cpy.m_left;
			m_right = cpy.m_right;
			key = cpy.key;
		}*/

	//	value_type	getpair(void)
	//	{
	//		return p;
	//	}
	};
	typedef typename allocator_type::template rebind<Node<T> >::other	Node_allocator;
	

	Node<T>	*getRoot(void) const
	{ return _root; }
	Node<T>	*getNULL(void) const
	{ return NULLnode; }

	void	leftRotate(Node<T> *node)
	{
		 Node<T> *tmp;

		 tmp = node->m_right;
		 node->m_right = tmp->m_left;
		 if(tmp && tmp->m_left != NULL)
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
		if (tmp && tmp->m_right != NULL)
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
	//		std::cout << "boucle while compteur\n";
			if (newN->m_parent == newN->m_parent->m_parent->m_left)
			{
	//			std::cout << "cas 1   ->  " << newN->key << "\n";
				tmp = newN->m_parent->m_parent->m_right;
				//if (newN->m_parent->m_parent->m_right->m_color == s_red)
				if (tmp && tmp->m_color == s_red)
				{
	//				std::cout << "casssss 1 --- 1   ->  " << newN->key << "\n";
					tmp->m_color = s_black;
					newN->m_parent->m_color = s_black;
					newN->m_parent->m_parent->m_color = s_red;
					newN = newN->m_parent->m_parent;
				}
				else
				{
	//				std::cout << "cas 1 --- 2   ->  " << newN->key << "\n";
					if (newN == newN->m_parent->m_right)
					{
	//					std::cout << "cas 1 --- 3   ->  " << newN->key << "\n";
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
	//			std::cout << "cas 2   ->  " << newN->key << "\n";
				tmp = newN->m_parent->m_parent->m_left;
				if (tmp && tmp->m_color == s_red)
				{
	//				std::cout << "cas 2 --- 1   ->  " << newN->key << "\n";
					tmp->m_color = s_black;
					newN->m_parent->m_color = s_black;
					newN->m_parent->m_parent->m_color = s_red;
					newN = newN->m_parent->m_parent;
				}
				else
				{
	//				std::cout << "cas 2 --- 2   ->  " << newN->key << "\n";
					if (newN == newN->m_parent->m_left)
					{
	//					std::cout << "cas 2 --- 3   ->  " << newN->key << "\n";
						newN = newN->m_parent;
						rightRotate(newN);
					}
					newN->m_parent->m_color = s_black;
					newN->m_parent->m_parent->m_color = s_red;
	//				std::cout << "NEWN PARENT: " << newN->m_parent->key << "\n";
	//				std::cout << "NEWN PARENT PARENT: " << newN->m_parent->m_parent->key << "\n";
					//std::cout << "NEWN PARENT PARENT PARENT: " << newN->m_parent->m_parent->m_parent->key << "\n";
					leftRotate(newN->m_parent->m_parent);
	//				std::cout << "APRES LEFT ROTATE DFANS FIX INSERT newN: " << newN->p.first << "\n";
	//				std::cout << "APRES LEFT ROTATE DFANS FIX INSERT newN right: " << newN-> m_parent->p.first << "\n";
	//				std::cout << "APRES LEFT ROTATE DFANS FIX INSERT newN left: " << newN->m_parent->m_left->p.first << "\n";

				}
			}
			if (newN == _root)
			{
	//			std::cout << "BREAK GROS WHILE\n";
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
		//_alloc.construct(tmp, Node<T>(v));
		//tmp->m_right = NULLnode;
		//tmp->m_left = NULLnode;
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
	//	std::cout << "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF: " << _root << "\n";
		Node<T>		*y = NULL;

	//	std::cout << "debut insert: " << newN->p.first << "\n";
	//	std::cout << "root debut insert: " << _root << "\n";
		while (x != NULL)
		{
	//		std::cout << "NEW: " << newN->p.second << "\n";
	//		std::cout << "X: " << x->p.first << "\n";
	//		std::cout << "X COLOR: " << x->m_color << "\n";
			y = x;
	//		std::cout << "Y: " << y->p.first << "\n";
	//		std::cout << "Y COLOR: " << y->m_color << "\n";
			if (newN->p && _comp(newN->p->first, x->p->first))
			{
				x = x->m_left;
			}
			else
				x = x->m_right;
		}
		//std::cout << "yyyy first: " << y->p.first << "\n";
		//std::cout << "yyyy second: " << y->p.second << "\n";
	//	std::cout << "SIZEEEEE: " << _size << "\n";
		newN->m_parent = y;
		if (_size == 0 || y == NULL)
		{
	//		std::cout << "ppppppp\n";
			newN->m_color = s_black;
			_root = newN;
			_root->m_color = s_black;
			//_root->m_right = NULLnode;
			//_root->m_left = NULLnode;
		}
		else if (newN->p && _comp(newN->p->first, y->p->first))   //else if (newN->key < y->key)
		{
			y->m_left = newN;
		}
		else if (newN->p && !_comp(newN->p->first, y->p->first))   //else if (newN->key > y->key)
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
		_size++;
		if (newN->m_parent == NULL)
			return;
		if (newN->m_parent->m_parent == NULL)
			return;
	//	std::cout << "NEWN PARENT COLOR FIN INSERT: " << newN->m_parent->m_parent->p.first << "\n";
	//	std::cout << "END INSERT NEW->first: " << newN->p.first << "\n";
	//	std::cout << "END INSERT NEW->second: " << newN->p.second << "\n";
		insertionFix(newN);
	}

	void	deletionFix(Node<T> *x)
	{
		//std::cout << "x in delete fix: " << x->key << "\n";
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
				else if (tmp->m_left && tmp->m_left->m_color == s_black)
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
		//std::cout << "SWAP x->parent : " << x->m_parent->p.first << "\n";
		//std::cout << "SWAP y->parent : " << y->m_parent->p.first << "\n";
		y->m_parent = x->m_parent;
	}

	Node<T>	*minTree(Node<T> *node)
	{
		if (node != NULLnode && node != NULL)
		{
			while (node->m_left != NULL)
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
	//	std::cout << "DEBUT DELETENODE ROOT VALUE: " << delN->p.first << "\n";
		Node<T> *tmp = NULLnode;
		Node<T> *x;
		Node<T> *y;
		while (delN != NULLnode && delN != NULL)
		{
			if (delN && delN->key == key)
				tmp = delN;
			if (delN && _comp(delN->p.first, key)) //delN->key < key)
				delN = delN->m_right;
			else
				delN = delN->m_left;
		}
	//	std::cout << "ooooo: " << tmp->key << "\n";
		if (tmp->key == key)
		{
			_size--;
			//std::cout << "FIND\n";
			y =  newNode(tmp->p);
			int y_color = y->m_color;
			if (tmp->m_left == NULL)
			{
			//	std::cout << "laaaaa\n";
				x = tmp->m_right;
				swap(tmp, tmp->m_right);
			}
			else if (tmp->m_right == NULL)
			{
			//	std::cout << "right NULL\n";
				x = tmp->m_left;
				swap(tmp, tmp->m_left);
			}
			else
			{
			//	std::cout << "Gros while dans delete\n";
				/*Node *test = tmp->m_right;
				while (test->m_left != NULLnode)
				{
					std::cout << "test\n";
					test = test->m_left;
				}
				y = test;*/
			//	std::cout << "y avant minTree: " << y->key << "\n";
				y = minTree(tmp->m_right);
				y_color = y->m_color;
			//	std::cout << "Y COLOR DANS DELETE: " << y_color << "\n";
				x = y->m_right;
			//	std::cout << "DEL/tmp debut gros while: " << tmp->key << "\n";
				//std::cout << "x debut gros while: " << x->key << "\n";
				//std::cout << "y debut gros while: " << y->key << "\n";
				//std::cout << "Parent de x debut gros while: " << x->m_parent->key << "\n";
				//std::cout << "Parent de y debut gros while: " << y->m_parent->key << "\n";
				if (y->m_parent == tmp)
				{
					//std::cout << "1111 if dans ELSE: x->m_parent: " << x->m_parent->key << "\n";
					x->m_parent = y;
					//std::cout << "2222 if dans ELSE: x->m_parent: " << x->m_parent->key << "\n";
				}
				else
				{
			//		std::cout << "SWAP petit else dans gros else\n";
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
			_alloc.destroy(y);
			_alloc.deallocate(y, 1);
			if (y_color == s_black)
			{
			//	std::cout << "go in fix deletion\n";
				deletionFix(x);
			}
			return (1);
		}
		else	
		{
			//std::cout << "NO find\n";
			return 0;
		}
	}

	int	search(const T &key) const
	{
		//std::cout << "key search: " << key << "\n";
		int	flag = 0;
		Node<T> *tmp = _root;
		while (tmp != NULLnode && tmp != NULL)
                {
                        if (tmp && tmp->key == key)
			{
				flag = 1;
			}
                        if (tmp && _comp(tmp->p.first, key))  //tmp->key < key)
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
		int	flag = 0;
		Node<T> *tmp = _root;
		while (tmp != NULLnode)
                {
                        if (tmp && !_comp(tmp->p.first, key)) //tmp->key > key)
				tmp = tmp->m_left;
			else if (tmp && _comp(tmp->p.first, key)) //tmp->key < key)
                                tmp = tmp->m_right;
                        else
			{
				flag = 1;
				break;
			}
                }
		if (flag == 1)
			return (tmp->key);
		return (0);
	}

	Node<T>	*searchRetNode(const T &key) const
	{
		int	flag = 0;
		Node<T> *tmp = _root;
		while (tmp != NULL && tmp->p && tmp != NULLnode)
                {
                        if (tmp && !_comp(tmp->p->first, key)) //tmp->key > key)
				tmp = tmp->m_left;
			else if (tmp && _comp(tmp->p->first, key)) //tmp->key < key)
                                tmp = tmp->m_right;
                        else
			{
				flag = 1;
				break ;
			}
                }
		if (flag == 1)
			return (tmp);
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
	//		std::cout << "MIIIIINNNNNNNNN\n";
			node = node->m_left;
		}
		//std::cout << "VALUEEEE DANS MIIIIN: " << _root->p->first << "\n";
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
		//	std::cout << "MAAAAAAAAAXXXXXXX: " << node->p.first << "\n";
		//	std::cout << "MAAAAAAAAAXXXXXXX 22222222222: " << node->m_parent->p.first << "\n";
		//	std::cout << "MAAAAAAAAAXXXXXXX 33333333333: " << node->m_right->p.first << "\n";
			node = node->m_right;
		}
		//std::cout << "VALUEEEE DANS MAXXXX: " << node->p.first << "\n";
		return (node->m_parent);
		//return (newNode(make_pair(node->p.first + 1, node->p.second)));
	}

	Node<T>	*maxD(Node<T> *node) const
	{
		if (_size == 0 || _size == 1)
			return _root;
		if (node == NULL)
			return (node);
		while (node && node->m_right != NULL && node != NULLnode && node->m_right != NULLnode)
		{
			/*std::cout << "MAAAAAAAAAXXXXXXX: " << node->p.first << "\n";
			std::cout << "MAAAAAAAAAXXXXXXX 22222222222: " << node->m_parent->p.first << "\n";
			std::cout << "MAAAAAAAAAXXXXXXX 33333333333: " << node->m_right->p.first << "\n";*/
			node = node->m_right;
		}
		//std::cout << "VALUEEEE DANS MAXXXX: " << node->p.first << "\n";
		return (node);
		//return (newNode(make_pair(node->p.first + 1, node->p.second)));
	}

	Node<T>	*maxNode(Node<T> *node)
	{
		if (node == NULL)
			return (0);
		while (node && node->m_right != NULL)
		{
			//std::cout << "MAAAAAAAAAXXXXXXX\n";
			node = node->m_right;
		}
		ft::pair<T, U> test = make_pair(_size, 0);
		Node<T> *tmp = newNode(test);
		tmp->m_parent = node;
		tmp->m_right = NULL;
		tmp->m_left = NULL;
		return (tmp);
		//return (newNode(make_pair(node->p.first + 1, node->p.second)));
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

		//Node<T>	*tmp_min = RBT_min(_root);
		Node<T>	*tmp_max = RetEnd(_root, end);

		//std::cout << "DANS DELETE END VALUE: " << tmp_max->p.first << "\n";
		//if (temp_min != 0)
		//	temp_min->_left = 0;
		if (tmp_max != 0)
			tmp_max->m_right = 0;


		/*Node<T>	*tmp = _root;
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
	
	void	setEndNode(Node<T> *end)
	{
		//Node<T> *tmp_min = RBT_min(_root);
		Node<T> *tmp_max = RetEnd(_root, end);

		//std::cout << "DANS SET END: " << tmp_max->p.first << "\n";
		/*if (tmp_min != 0)
		{
			tmp_min->_left = nodemin;
			nodemin->_father = temp_min;
		}*/
		if (tmp_max != 0)
		{
			tmp_max->m_right = end;
			end->m_parent = tmp_max;
			end->m_right = NULLnode;
		}


		/*Node<T>	*tmp = _root;
		
		while (tmp->m_right && tmp->m_right != NULLnode)
			tmp = tmp->m_right;
		std::cout << "NEW SET END::::::: " << tmp->p.first << "\n";
		_last = NULLnode;
		tmp->m_right = _last;
		_last->m_parent = tmp;*/
		//std::cout << "ALLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL: " << _last->m_parent->p.first << "\n";
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

	/*void	destroyTree(Node<T> *node)
	{
		if (!node || node == NULLnode)
			return ;
		destroyTree(node->m_left);
		destroyTree(node->m_right);
	}*/
	
	RBT(void)
	{
		//std::cout << "CONSTRUCTOR\n";
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
		//_last = newNode();
		//_last->m_left = NULLnode;
		//_last->m_right = NULLnode;
		//_last->m_color = s_black;
		//_last->m_parent = _root;
		//_root->m_right = _last;
		//_root = NULL;
		_size = 0;
		//_root->m_left = NULLnode;
		//_root->m_right = NULLnode;
	}

	~RBT(void)
	{
		//_alloc.destroy(NULLnode);
		//_alloc.deallocate(NULLnode, 1);
		//std::cout << "DESTRUCTOR\n";

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
	private:
		Node<T> *_root;
		Node<T> *_last;
		Node<T> *NULLnode;
		compare_type	_comp;
		Node_allocator	_alloc;
		allocator_type	_destroyer;
		size_t		_size;
};
}


#endif
