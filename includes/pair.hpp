/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:27:32 by jtaravel          #+#    #+#             */
/*   Updated: 2023/02/22 16:30:58 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP

#define PAIR_HPP

namespace ft
{

template <class T1, class T2>
struct pair
{
	public:
		typedef T1	first_type;
		typedef T2	second_type;

		first_type	first;
		second_type	second;

		pair(void): first(first_type())
		{
			second = second_type();
		}
		template<class U, class V>
		pair (const pair<U, V> &cpy):first(cpy.first)
		{
			second = cpy.second;
		}
		pair (const first_type& a, const second_type& b):first(a)
		{
			second = b;
		}

		pair& operator= (const pair &egal)
		{
			first = egal.first;
			second = egal.swdecond;
			return (*this);
		}

};

template <class T1, class T2>
bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
	return (lhs.first == rhs.first && lhs.second == rhs.second);
}
template <class T1, class T2>
bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
	return !(lhs==rhs);
}
template <class T1, class T2>
bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
	return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);
}
template <class T1, class T2>
bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
	return !(rhs<lhs);
}
template <class T1, class T2>
bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
	return rhs<lhs;
}
template <class T1, class T2>
bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
	return !(lhs<rhs);
}

}

#endif
