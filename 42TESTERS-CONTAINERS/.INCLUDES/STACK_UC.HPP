/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:11:09 by jtaravel          #+#    #+#             */
/*   Updated: 2023/03/16 17:30:34 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP

#define STACK_HPP

#include "vector.hpp"

namespace ft
{

template <class T, class Container = ft::vector<T> >
class stack
{
	public:
		typedef T		value_type;
		typedef Container	container_type;
		typedef size_t		size_type;
		
		explicit stack (const container_type& ctnr = container_type())
		{
			_c = ctnr;
		}
		
		size_type size(void)
		{
			return (_c.size());
		}
		bool empty(void)
		{
			if (_c.size() == 0)
				return (true);
			else
				return (false);
		}
		void	push(const value_type &val)
		{
			_c.push_back(val);
		}
		value_type &top(void)
		{
			return ((_c.back()));
		}
		const value_type &top(void) const
		{
			return ((_c.back()));
		}
		void pop()
		{
			_c.pop_back();
		}

friend bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
	return (lhs._c == rhs._c);
}
friend bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
	return (lhs._c != rhs._c);
}
friend bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
	return (lhs._c < rhs._c);
}
friend bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
	return (lhs._c <= rhs._c);
}
friend bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
	return (lhs._c > rhs._c);
}
friend bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
	return (lhs._c >= rhs._c);
}
	private:
		container_type _c;

};

}

#endif
