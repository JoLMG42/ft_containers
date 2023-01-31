/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:04:20 by jtaravel          #+#    #+#             */
/*   Updated: 2023/01/26 17:05:27 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP

#define IS_INTEGRAL_HPP

#include <iostream>
#include <cstddef>

namespace ft
{

/*template <class T> struct is_integral : public false_type {};
template <class T> struct is_integral<const T> : public is_integral<T> {};
template <class T> struct is_integral<volatile T> : public is_integral<T>{};
template <class T> struct is_integral<volatile const T> : public is_integral<T>{};*/

	template<class T, T v>
	struct integral_constant
	{
		typedef T value_type;
		typedef integral_constant<T,v> type;

		static const T value = v;

		operator T()
		{
			return v;
		}
	};

typedef integral_constant<bool,true> true_type;
typedef integral_constant<bool,false> false_type;
template<typename> struct is_integral: false_type {};

template<> struct is_integral<unsigned char> : public true_type {};
template<> struct is_integral<unsigned short int> : public true_type{};
template<> struct is_integral<unsigned int> : public true_type{};
template<> struct is_integral<unsigned long int> : public true_type{};
//template<> struct is_integral<unsigned long long int> : public true_type{};
template<> struct is_integral<signed char> : public true_type{};
template<> struct is_integral<short> : public true_type{};
template<> struct is_integral<int> : public true_type{};
template<> struct is_integral<long int> : public true_type{};
//template<> struct is_integral<long long int> : public true_type{};
template<> struct is_integral<char> : public true_type{};
template<> struct is_integral<bool> : public true_type{};
template<> struct is_integral<wchar_t> : public true_type{};

template<> struct is_integral<const unsigned char> : public true_type {};
template<> struct is_integral<const unsigned short int> : public true_type{};
template<> struct is_integral<const unsigned int> : public true_type{};
template<> struct is_integral<const unsigned long int> : public true_type{};
//template<> struct is_integral<const unsigned long long int> : public true_type{};
template<> struct is_integral<const signed char> : public true_type{};
template<> struct is_integral<const short> : public true_type{};
template<> struct is_integral<const int> : public true_type{};
template<> struct is_integral<const long int> : public true_type{};
//template<> struct is_integral<const long long int> : public true_type{};
template<> struct is_integral<const char> : public true_type{};
template<> struct is_integral<const bool> : public true_type{};
template<> struct is_integral<const wchar_t> : public true_type{};

template<> struct is_integral<volatile unsigned char> : public true_type {};
template<> struct is_integral<volatile unsigned short int> : public true_type{};
template<> struct is_integral<volatile unsigned int> : public true_type{};
template<> struct is_integral<volatile unsigned long int> : public true_type{};
//template<> struct is_integral<volatile unsigned long long int> : public true_type{};
template<> struct is_integral<volatile signed char> : public true_type{};
template<> struct is_integral<volatile short> : public true_type{};
template<> struct is_integral<volatile int> : public true_type{};
template<> struct is_integral<volatile long int> : public true_type{};
//template<> struct is_integral<volatile long long int> : public true_type{};
template<> struct is_integral<volatile char> : public true_type{};
template<> struct is_integral<volatile bool> : public true_type{};
template<> struct is_integral<volatile wchar_t> : public true_type{};

template<> struct is_integral<volatile const unsigned char> : public true_type {};
template<> struct is_integral<volatile const unsigned short int> : public true_type{};
template<> struct is_integral<volatile const unsigned int> : public true_type{};
template<> struct is_integral<volatile const unsigned long int> : public true_type{};
//template<> struct is_integral<volatile const unsigned long long int> : public true_type{};
template<> struct is_integral<volatile const signed char> : public true_type{};
template<> struct is_integral<volatile const short> : public true_type{};
template<> struct is_integral<volatile const int> : public true_type{};
template<> struct is_integral<volatile const long int> : public true_type{};
//template<> struct is_integral<volatile const long long int> : public true_type{};
template<> struct is_integral<volatile const char> : public true_type{};
template<> struct is_integral<volatile const bool> : public true_type{};
template<> struct is_integral<volatile const wchar_t> : public true_type{};

}

#endif
