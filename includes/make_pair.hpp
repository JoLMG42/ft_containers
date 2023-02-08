/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pair.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:33:56 by jtaravel          #+#    #+#             */
/*   Updated: 2023/01/31 18:56:00 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_PAIR_HPP

#define MAKE_PAIR_HPP

#include "pair.hpp"


template <class T1, class T2>
pair<T1,T2> make_pair (T1 x, T2 y)
{
	pair<T1, T2>(x, y);
}

#endif
