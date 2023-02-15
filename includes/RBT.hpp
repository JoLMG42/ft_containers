/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:39:45 by jtaravel          #+#    #+#             */
/*   Updated: 2023/02/15 18:27:27 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP

#define RBT_HPP

#include <cstddef>
#include <iostream>

namespace ft
{

enum	RBT_color
{
	s_red = false,
	s_black = true
};

template <class T>
struct	Node
{
	RBT_color	m_color;
	Node		*m_parent;
	Node		*m_left;
	Node		*m_right;
	T		key;
};

template <class T, class compare>
class	RBT
{
	private:
		Node<T> *_root;
		Node<T> *NULLnode;
	public:
	

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
		if (tmp->m_left != NULL)
		{
			tmp->m_left->m_parent = node;
		}
		tmp->m_parent = node->m_parent;
		if (node->m_parent == NULL)
		{
			_root = tmp;
		}
		else if (node == node->m_parent->m_right)
		{
			node->m_parent->m_left = tmp;
		}
		else
			node->m_parent->m_right = tmp;
		tmp->m_left = node;
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
				if (newN->m_parent->m_parent->m_left->m_color == s_red)
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
					newN->m_parent->m_color = s_black;
					newN->m_parent->m_parent->m_color = s_red;
					rightRotate(newN->m_parent->m_parent); 
				}
			}
			else
			{
				std::cout << "cas 2   ->  " << newN->key << "\n";
				tmp = newN->m_parent->m_parent->m_left;
				if (tmp->m_color == s_red)
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

	void	insertNode(T const &k)
	{
		Node<T>	*newN = new Node<T>;
		
		newN->key = k;
		newN->m_parent = nullptr;
		newN->m_left = NULLnode;
		newN->m_right = NULLnode;
		newN->m_color = s_red;

		Node<T> 	*first = _root;
		Node<T>		*second = nullptr;

		while (first != NULLnode)
		{
			second = first;
			if (newN->key < first->key)
			{
				first = first->m_left;
			}
			else
				first = first->m_right;
		}
		newN->m_parent = second;
		if (second == NULL)
		{
			newN->m_color = s_black;
			_root = newN;
			_root->m_color = s_black;
		}
		else if (newN->key < second->key)
		{
			second->m_left = newN;
		}
		else if (newN->key > second->key)
			second->m_right = newN;
		else
		{
			 second->m_right = newN;
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

	void	deletionFix(Node<T> *first)
	{
		std::cout << "first in delete fix: " << first->key << "\n";
		 Node<T> *tmp;
		 while (first != _root  && first->m_color == s_black)	 
		 {
			 if (first == first->m_parent->m_left)
			 {
				tmp = first->m_parent->m_right;
				if (first->m_parent->m_right->m_color == s_red)
				{
					tmp->m_color = s_black;
					first->m_parent->m_color = s_red;
					leftRotate(first->m_parent);
					tmp = first->m_parent->m_left;
				}
				if (tmp->m_left->m_color == s_black && tmp->m_right->m_color == s_black)
				{
					tmp->m_color = s_red;
					first = first->m_parent;
				}
				else if (tmp->m_right->m_color == s_black)
				{
					tmp->m_left->m_color = s_black;
					tmp->m_color = s_red;
					rightRotate(tmp);
					tmp = first->m_parent->m_right;
				}
				//else
				//{
					tmp->m_color = first->m_parent->m_color;
					first->m_parent->m_color = s_black;
					tmp->m_right->m_color = s_black;
					leftRotate(first->m_parent);
					first = _root;
				//}
			 }
			 else if (first == first->m_parent->m_right)
			 {
				tmp = first->m_parent->m_left;
				if (first->m_parent->m_left->m_color == s_red)
				{
					tmp->m_color = s_black;
					first->m_parent->m_color = s_red;
					leftRotate(first->m_parent);
					tmp = first->m_parent->m_right;
				}
				if (tmp->m_right->m_color == s_black && tmp->m_left->m_color == s_black)
				{
					tmp->m_color = s_red;
					first = first->m_parent;
				}
				else if (tmp->m_left->m_color == s_black)
				{
					tmp->m_right->m_color = s_black;
					tmp->m_color = s_red;
					rightRotate(tmp);
					tmp = first->m_parent->m_left;
				}
					tmp->m_color = first->m_parent->m_color;
					first->m_parent->m_color = s_black;
					tmp->m_left->m_color = s_black;
					leftRotate(first->m_parent);
					first = _root;
			 }
		 }
		 first->m_color = s_black;
	}

	void	swap(Node<T> *first, Node<T> *second)
	{
		std::cout << "Swap first: " << first->key << "\n";
		std::cout << "Swap second: " << second->key << "\n";
		if (first->m_parent == NULL)
		{
			_root = second;
		}
		else if (first == first->m_parent->m_left)
		{
			first->m_parent->m_left = second;
		}
		else
		{
			first->m_parent->m_right = second;
		}
		second->m_parent = first->m_parent;
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
		Node<T> *first;
		Node<T> *second;
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
			second = tmp;
			int second_color = second->m_color;
			if (tmp->m_left == NULLnode)
			{
				std::cout << "laaaaa\n";
				first = tmp->m_right;
				swap(tmp, tmp->m_right);
			}
			else if (tmp->m_right == NULLnode)
			{
				std::cout << "right NULL\n";
				first = tmp->m_left;
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
				second = test;*/
				std::cout << "Second avant minTree: " << second->key << "\n";
				second = minTree(tmp->m_right);
				second_color = second->m_color;
				first = second->m_right;
				std::cout << "DEL/tmp debut gros while: " << tmp->key << "\n";
				std::cout << "First debut gros while: " << first->key << "\n";
				std::cout << "Second debut gros while: " << second->key << "\n";
				std::cout << "Parent de first debut gros while: " << first->m_parent->key << "\n";
				std::cout << "Parent de second debut gros while: " << second->m_parent->key << "\n";
				if (second->m_parent == tmp)
				{
					std::cout << "1111 if dans ELSE: first->m_parent: " << first->m_parent->key << "\n";
					first->m_parent = second;
					std::cout << "2222 if dans ELSE: first->m_parent: " << first->m_parent->key << "\n";
				}
				else
				{
					std::cout << "SWAP petit else dans gros else\n";
					swap(second, second->m_right);
					second->m_right = tmp->m_right;
					second->m_right->m_parent = second;
				}
				swap(tmp, second);
				second->m_left = tmp->m_left;
				second->m_left->m_parent = second;
				second->m_color = tmp->m_color;
			}
			delete tmp;
			if (second_color == s_black)
			{
				std::cout << "go in fix deletion\n";
				deletionFix(first);
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
		while (node->m_left != NULLnode)
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
		NULLnode = new Node<T>;
		NULLnode->m_color = s_black;
		NULLnode->m_left = NULL;
		NULLnode->m_right = NULL;
		_root = NULLnode;
	}
};
}


#endif
