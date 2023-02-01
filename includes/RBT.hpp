/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:39:45 by jtaravel          #+#    #+#             */
/*   Updated: 2023/02/01 12:31:34 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP

#define RBT_HPP

namespace ft
{

enum	RBT_color
{
	s_red = false;
	s_black = true;
}

struct	Node
{
	RBT_color	m_color;
	Node		m_parent;
	Node		m_left;
	Node		m_right;
	int		key;
};

/*template <typename Val>
struct	RBT_node : public RBT_node_base
{
	typedef	RBT_node<Val>*	link_type;
	Val			m_value_field;
};

template <typename Tp>
struct	RBT_iterator
{
	typedef	Tp	value_type;
	typedef	Tp&	reference;
	typedef	Tp*	pointer;
	typedef	bidirectionnal_iterator_tag	iterator_category;
	typedef	ptrdiff_t			difference_type;
	typedef	RBT_iterator<Tp>		self;
	typedef	RBT_node_base::base_ptr		base_ptr;
	typedef	RBT_node<Tp>*			link_type;

};*/

template <typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc = allocator<Val> >
class	RBT
{


};

}

#endif
