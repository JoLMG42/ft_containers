#ifndef REVERSE_ITERATOR_TPP

#define REVERSE_ITERATOR_TPP

#include <iostream>

namespace ft
{

template <class Iterator>
reverse_iterator<Iterator>::reverse_iterator(void)
{
	_it = iterator_type();
}

template <class Iterator>
reverse_iterator<Iterator>::reverse_iterator(iterator_type it)
{
	_it = it;
}

template <class Iterator>
reverse_iterator<Iterator>::reverse_iterator(const reverse_iterator<Iterator> &cpy)
{
	_it = cpy._it;
}

template <class Iterator>
typename reverse_iterator<Iterator>::iterator_type reverse_iterator<Iterator>::base(void) const
{
	return _it;
}

template <class Iterator>
typename reverse_iterator<Iterator>::reference &reverse_iterator<Iterator>::operator*(void) const
{
	Iterator tmp = _it;
	return (*--tmp);
}

template <class Iterator>
typename reverse_iterator<Iterator>::reference &reverse_iterator<Iterator>::operator[](difference_type n) const
{
	return base()[-n - 1];
}

template <class Iterator>
typename reverse_iterator<Iterator>::pointer reverse_iterator<Iterator>::operator->(void) const
{
	Iterator tmp = _it;
	return &(*--tmp);
}

template <class Iterator>
reverse_iterator<Iterator> &reverse_iterator<Iterator>::operator--(void)
{
	++(this->_it);
	return (*this);
}

template <class Iterator>
reverse_iterator<Iterator> reverse_iterator<Iterator>::operator--(int)
{
	reverse_iterator tmp = *this;
	--*this;
	return (tmp);
}

template <class Iterator>
reverse_iterator<Iterator> &reverse_iterator<Iterator>::operator++(void)
{
	--(this->_it);
	return (*this);
}

template <class Iterator>
reverse_iterator<Iterator> reverse_iterator<Iterator>::operator++(int)
{
	reverse_iterator tmp = *this;
	++(*this);
	return (tmp);
}

template <class Iterator>
reverse_iterator<Iterator> &reverse_iterator<Iterator>::operator-=(difference_type n)
{
	_it += n;
	return (*this);
}

template <class Iterator>
reverse_iterator<Iterator> &reverse_iterator<Iterator>::operator+=(difference_type n)
{
	_it -= n;
	return (*this);
}

template <class Iterator>
reverse_iterator<Iterator> reverse_iterator<Iterator>::operator-(difference_type n) const
{
	return reverse_iterator(_it + n);
}

template <class Iterator>
reverse_iterator<Iterator> reverse_iterator<Iterator>::operator+(difference_type n) const
{
	return reverse_iterator(_it - n);
}

template <class Iterator1, class Iterator2>
bool operator==(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
{
	return (lhs.base() == rhs.base());
}

template <class Iterator1, class Iterator2>
bool operator!=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
{
	return (lhs.base() != rhs.base());
}

template <class Iterator1, class Iterator2>
bool operator<(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
{
	return (lhs.base() > rhs.base());
}

template <class Iterator1, class Iterator2>
bool operator<=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
{
	return (lhs.base() >= rhs.base());
}

template <class Iterator1, class Iterator2>
bool operator>(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
{
	return (lhs.base() < rhs.base());
}

template <class Iterator1, class Iterator2>
bool operator>=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
{
	return (lhs.base() <= rhs.base());
}

template <class Iterator>
reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
{
	return (rev_it.base() - n);
}

template <class Iterator>
reverse_iterator<Iterator> operator-(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
{
	return (rev_it.base() + n);
}

/*template <class Iterator1, class Iterator2>
reverse_iterator<Iterator> operator-(typename reverse_iterator<Iterator1>::difference_type n, const reverse_iterator<Iterator2>& rev_it)
{
	return (rev_it.base() + n);
}

template <class Iterator1, class Iterator2>
reverse_iterator<Iterator> operator-(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
{
	return (lhs.base() - rhs.base());
}*/

}

#endif
