/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:39:45 by jtaravel          #+#    #+#             */
/*   Updated: 2023/02/07 18:58:20 by jtaravel         ###   ########.fr       */
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

struct	Node
{
	RBT_color	m_color;
	Node		*m_parent;
	Node		*m_left;
	Node		*m_right;
	int		key;
};

class	RBT
{
	private:
		Node *_root;
	public:
	
	Node	*getRoot(void)
	{ return _root; }
	void	initNode(Node *node)
	{
		node = new Node;
		node->m_parent = NULL;
		node->m_left = NULL;
		node->m_right = NULL;
		node->m_color = s_black;
		node = NULL;
	}
	
  void leftRotate(Node* x) {
    Node* y = x->m_right;
    x->m_right = y->m_left;
    if (y->m_left != NULL) {
      y->m_left->m_parent = x;
    }
    y->m_parent = x->m_parent;
    if (x->m_parent == nullptr) {
      this->_root = y;
    } else if (x == x->m_parent->m_left) {
      x->m_parent->m_left = y;
    } else {
      x->m_parent->m_right = y;
    }
    y->m_left = x;
    x->m_parent = y;
  }

  void rightRotate(Node* x) {
    Node* y = x->m_left;
    x->m_left = y->m_right;
    if (y->m_right != NULL) {
      y->m_right->m_parent = x;
    }
    y->m_parent = x->m_parent;
    if (x->m_parent == nullptr) {
      this->_root = y;
    } else if (x == x->m_parent->m_right) {
      x->m_parent->m_right = y;
    } else {
      x->m_parent->m_left = y;
    }
    y->m_right = x;
    x->m_parent = y;
  }

	void	insertionFix(Node *newN)
	{
    /*Node *u;
    while (k->m_parent->m_color == s_red) {
      if (k->m_parent == k->m_parent->m_parent->m_right) {
        u = k->m_parent->m_parent->m_left;
        if (u->m_color == s_red) {
          u->m_color = s_black;
          k->m_parent->m_color = s_black;
          k->m_parent->m_parent->m_color = s_red;
          k = k->m_parent->m_parent;
        } else {
          if (k == k->m_parent->m_left) {
            k = k->m_parent;
            rightRotate(k);
          }
          k->m_parent->m_color = s_black;
          k->m_parent->m_parent->m_color = s_red;
          leftRotate(k->m_parent->m_parent);
        }
      } else {
        u = k->m_parent->m_parent->m_right;

        if (u->m_color == s_red) {
          u->m_color = s_black;
          k->m_parent->m_color = s_black;
          k->m_parent->m_parent->m_color = s_red;
          k = k->m_parent->m_parent;
        } else {
          if (k == k->m_parent->m_right) {
            k = k->m_parent;
            leftRotate(k);
          }
          k->m_parent->m_color = s_black;
          k->m_parent->m_parent->m_color = s_red;
          rightRotate(k->m_parent->m_parent);
        }
      }
      if (k == _root) {
        break;
      }
    }
    _root->m_color = s_black;*/
		Node	*tmp;
		while(newN->m_parent->m_color == s_red)
		{
			if (newN->m_parent == newN->m_parent->m_parent->m_right)
			{
				tmp = newN->m_parent->m_parent->m_left;
				if (newN->m_parent->m_parent->m_color == s_red)
				{
					newN->m_parent->m_right->m_color = s_black;
					newN->m_parent->m_left->m_color = s_black;
					newN->m_parent->m_parent->m_color = s_red;
					newN = newN->m_parent->m_parent;
				}
				else if (newN == newN->m_parent->m_left)
				{
					newN = newN->m_parent;
					leftRotate(newN);
					newN->m_parent->m_color = s_black;
					newN->m_parent->m_parent->m_color = s_red;
					rightRotate(newN->m_parent->m_parent); 
				}
			}
			else
			{
				tmp = newN->m_parent->m_parent->m_right;
				if (tmp->m_color == s_black)
				{
					tmp->m_color = s_black;
					newN->m_parent->m_color = s_black;
					newN->m_parent->m_parent->m_color = s_red;
					newN = newN->m_parent->m_parent;
				}
				else if (newN == newN->m_parent->m_right)
				{
					newN = newN->m_parent;
					leftRotate(newN);
					newN->m_parent->m_color = s_black;
					newN->m_parent->m_parent->m_color = s_red;
					rightRotate(newN->m_parent->m_parent); 
				}
			}
			if (newN == _root)
				break ;
		}
		_root->m_color = s_black;
	}

	void	insertNode(int k)
	{
		Node	*newN = new Node;
		
		newN->key = k;
		newN->m_parent = nullptr;
		newN->m_left = NULL;
		newN->m_right = NULL;
		newN->m_color = s_red;
		Node 	*first = NULL;
		Node	*second = _root;

		while (first != NULL)
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
			_root = newN;
			_root->m_color = s_black;
		}
		else
		{
			Node	*tmp = _root;
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
				else if (tmp->m_right && k > tmp->key)
				{
					tmp = tmp->m_right;
				}
				else if (!tmp->m_right && k > tmp->key)
				{
					tmp->m_right = newN;
					break;
				}
			}
		}
		if (newN->m_parent == NULL)
			return;
		if (newN->m_parent->m_parent == NULL)
			return;
		insertionFix(newN);
	}

	void	deleteNode(Node *delN, int key)
	{
		Node *tmp;
		Node *first;
		Node *second;
		initNode(tmp);
		initNode(first);
		initNode(second);
		while (delN != NULL)
		{
			if (delN->key == key)
				tmp = delN;
			if (delN->key <= key)
				delN = delN->m_right;
			else
				delN = delN->m_left;
		}
		std::cout << "ooooo: " << tmp->m_right->key << "\n";
		if (tmp->key == key)
		{
			std::cout << "FIND\n";
			second = tmp;
			int second_color = second->m_color;
			if (tmp->m_left == NULL)
			{
				std::cout << "laaaaa\n";
				first = tmp->m_right;
				if (tmp->m_parent == NULL)
				{
					_root = tmp->m_right;
				}
				else if (tmp == tmp->m_parent->m_left)
				{
					tmp->m_parent->m_left = tmp->m_right;
				}
				else
				{
					tmp->m_parent->m_right = tmp->m_right;

				}
				tmp->m_right->m_parent = tmp->m_parent;
			}
			else if (tmp->m_right == NULL)
			{
				first = tmp->m_left;
				if (tmp->m_parent == NULL)
				{
					_root = tmp->m_left;
				}
				else if (tmp == tmp->m_parent->m_left)
				{
					tmp->m_parent->m_left = tmp->m_left;
				}
				else
					tmp->m_parent->m_left = tmp->m_right;
				tmp->m_left->m_parent = tmp->m_parent;


			}
			else
			{
				Node *test = tmp->m_right;
				while (tmp->m_left)
					tmp = tmp->m_left;
				second = tmp;
				second_color = second->m_color;
				first = second->m_right;
				if (second->m_parent == tmp)
				{
					first->m_parent = second;
				}
				else
				{
					if (second->m_parent == NULL)
					{
						_root = second->m_right;
					}
					else if (second == second->m_parent->m_left)
					{
						second->m_parent->m_left = second->m_right;
					}
					else
					{
						second->m_parent->m_left = second->m_left;
					}
					second->m_right->m_parent = second->m_parent;
					second->m_right = tmp->m_right;
					second->m_right->m_parent = second;
				}
				if (tmp->m_parent == NULL)
				{
					_root = second;
				}
				else if (tmp == tmp->m_parent->m_left)
				{
					tmp->m_parent->m_left = second;
				}
				else
				{
					tmp->m_parent->m_right = second;
				}
				second->m_parent = tmp->m_parent;
				second->m_left = tmp->m_left;
				second->m_left->m_parent = second;
				second->m_color = tmp->m_color;
			}
			delete tmp;
		}
		else	
		{
			std::cout << "NO find\n";
			return ;
		}

	}
};
}


#endif
