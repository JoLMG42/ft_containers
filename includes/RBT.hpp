/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:39:45 by jtaravel          #+#    #+#             */
/*   Updated: 2023/02/06 19:08:58 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP

#define RBT_HPP

#include <cstddef>

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
	void	initNode(Node *node, Node *parent)
	{
		node->m_parent = parent;
		node->m_left = NULL;
		node->m_right = NULL;
		node->m_color = s_black;
		node->key = 0;
	}
	
	void	insertNode(int k)
	{
		Node	*newN = new Node;
		
		newN->key = k;
		newN->m_parent = NULL;
		newN->m_left = NULL;
		newN->m_right = NULL;
		newN->m_color = s_red;
		if (_root == NULL)
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
	}
};




}

#endif
