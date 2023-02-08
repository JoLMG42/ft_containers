/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:39:45 by jtaravel          #+#    #+#             */
/*   Updated: 2023/02/08 19:19:00 by jtaravel         ###   ########.fr       */
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
	
	void	leftRotate(Node *node)
	{
		 Node *tmp;

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
	
	void	rightRotate(Node *node)
	{
		Node *tmp;

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

	void	insertionFix(Node *newN)
	{
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

	  /*void rbTransplant(Node *u, Node *v) {
    if (u->m_parent == nullptr) {
      _root = v;
    } else if (u == u->m_parent->m_left) {
      u->m_parent->m_left = v;
    } else {
      u->m_parent->m_right = v;
    }
    v->m_parent = u->m_parent;
  }

  Node *minimum(Node *node) {
    while (node->m_left != NULL) {
      node = node->m_left;
    }
    return node;
  }

	 void deleteNode(Node* node, int key) {
    Node* z = NULL;
    Node* x;
    Node *y;
    while (node != NULL) {
      if (node->key == key) {
        z = node;
      }

      if (node->key <= key) {
        node = node->m_right;
      } else {
        node = node->m_left;
      }
    }


    y = z;
    int y_original_color = y->m_color;
    if (z->m_left == NULL) {
      x = z->m_right;
      rbTransplant(z, z->m_right);
    } else if (z->m_right == NULL) {
      x = z->m_left;
      rbTransplant(z, z->m_left);
    } else {
      y = minimum(z->m_right);
      y_original_color = y->m_color;
      x = y->m_right;
      if (y->m_parent == z) {
        x->m_parent = y;
      } else {
        rbTransplant(y, y->m_right);
        y->m_right = z->m_right;
        y->m_right->m_parent = y;
      }

      rbTransplant(z, y);
      y->m_left = z->m_left;
      y->m_left->m_parent = y;
      y->m_color = z->m_color;
    }
    delete z;
    if (y_original_color == s_black) {
      deleteFix(x);
    }
  }

void deleteFix(Node* x) {
    Node* s;
    while (x != _root && x->m_color == s_black) {
      if (x == x->m_parent->m_left) {
        s = x->m_parent->m_right;
        if (s->m_color == s_red) {
          s->m_color = s_black;
          x->m_parent->m_color = s_red;
          leftRotate(x->m_parent);
          s = x->m_parent->m_right;
        }

        if (s->m_left->m_color == s_black && s->m_right->m_color == s_black) {
          s->m_color = s_red;
          x = x->m_parent;
        } else {
          if (s->m_right->m_color == s_black) {
            s->m_left->m_color = s_black;
            s->m_color = s_red;
            rightRotate(s);
            s = x->m_parent->m_right;
          }

          s->m_color = x->m_parent->m_color;
          x->m_parent->m_color = s_black;
          s->m_right->m_color = s_black;
          leftRotate(x->m_parent);
          x = _root;
        }
      } else {
        s = x->m_parent->m_left;
        if (s->m_color == s_red) {
          s->m_color = s_black;
          x->m_parent->m_color = s_red;
          rightRotate(x->m_parent);
          s = x->m_parent->m_left;
        }

        if (s->m_right->m_color == s_black && s->m_right->m_color == s_black) {
          s->m_color = s_red;
          x = x->m_parent;
        } else {
          if (s->m_left->m_color == s_black) {
            s->m_right->m_color = s_black;
            s->m_color = s_red;
            leftRotate(s);
            s = x->m_parent->m_left;
          }

          s->m_color = x->m_parent->m_color;
          x->m_parent->m_color = s_black;
          s->m_left->m_color = s_black;
          rightRotate(x->m_parent);
          x = _root;
        }
      }
    }
    x->m_color = s_black;
  }*/

	void	deletionFix(Node *first)
	{
		 Node *tmp;
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
		deletionFix(first);
	}
};
}


#endif
