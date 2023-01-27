#ifndef VECTOR_TPP

#define VECTOR_TPP
#include <iostream>
namespace ft
{

template <class T, class Alloc>
vector<T, Alloc>::vector(const allocator_type& alloc)
{
	_alloc = alloc;
	_size = 0;
	_capacity = _size;
	_tab = _alloc.allocate(_capacity);
}

template <class T, class Alloc>
vector<T, Alloc>::vector(size_type size, const value_type & val)
{
	_alloc = Alloc();
	_size = size;
	_capacity = _size;
	_tab = _alloc.allocate(_capacity);
	for (size_type i = 0; i < _size; ++i)
		_alloc.construct(_tab + i, val);
}

template <class T, class Alloc>
vector<T, Alloc>::vector(const vector & cpy)
{
	_alloc = Alloc();
	_size = cpy._size;
	_capacity = cpy._capacity;
	_tab = _alloc.allocate(_capacity);
	for (size_type i = 0; i < _size; ++i)
		_alloc.construct(_tab + i, cpy._tab[i]);
}

template <class T, class Alloc>
vector<T, Alloc>::~vector(void)
{
	if (_size >= 0)
	{
		for (size_type i = 0; i < _size; ++i)
			_alloc.destroy(_tab + i);
		_alloc.deallocate(_tab, _capacity);
	}
}

template <class T, class Alloc>
size_t vector<T, Alloc>::size(void) const
{
	return _size;
}

template <class T, class Alloc>
size_t vector<T, Alloc>::capacity(void) const
{
	return _capacity;
}

template <class T, class Alloc>
size_t vector<T, Alloc>::max_size(void) const
{
	return _alloc.max_size();
}

template <class T, class Alloc>
Alloc vector<T, Alloc>::get_allocator(void) const
{
	return _alloc;
}

template <class T, class Alloc>
T & vector<T, Alloc>::front(void) const
{
	return (_tab[0]);
}

template <class T, class Alloc>
T & vector<T, Alloc>::back(void) const
{
	return (_tab[_size - 1]);
}

template <class T, class Alloc>
bool vector<T, Alloc>::empty(void) const
{
	if (_size == 0)
		return (1);
	return (0);
}

template <class T, class Alloc>
T & vector<T, Alloc>::at(size_type idx)
{
	if (idx > _size || idx < 0)
		throw std::out_of_range("out_of_range");
	return _tab[idx];
}

template <class T, class Alloc>
T & vector<T, Alloc>::at(size_type idx) const
{
	if (idx > _size || idx < 0)
		throw std::out_of_range("out_of_range");
	return _tab[idx];
}

template <class T, class Alloc>
void vector<T, Alloc>::resize(size_type n, const value_type & val)
{
	if (n < _size)
	{
		for (size_type i = _size; i > n; --i)
			pop_back();
	}
	else if (n > _size)
	{
		if (n > _capacity)
			reserve(n);	
		for (size_type i = _size; i < n; ++i)
			push_back(val);
	}
}

template <class T, class Alloc>
void vector<T, Alloc>::newCapacity(size_type n)
{
	_capacity = n;
}

template <class T, class Alloc>
void vector<T, Alloc>::reserve(size_type n)
{
	if (n > _capacity)
	{
		T *tmp = _tab;
		this->newCapacity(_capacity * 2);
		_tab = _alloc.allocate(_capacity);
		for (size_type i = 0; i < _size; ++i)
			_tab[i] = tmp[i];
		for (size_type j = 0; j < _size; ++j)
			_alloc.destroy(tmp + j);
		_alloc.deallocate(tmp, _capacity / 2);
	}
}
		

template <class T, class Alloc>
void vector<T, Alloc>::push_back(const value_type & val)
{
	if (_capacity == 0)
		_capacity++;
	if (_size >= _capacity)
	{
		if (_size == _capacity)
			reserve(_size + 1);
		if (_size > _capacity)
			reserve(_size);
		T *tmp = _tab;
		_size++;
		_tab = _alloc.allocate(_capacity);
		for (size_type i = 0; i < _size - 1; ++i)
			_tab[i] = tmp[i];
		_tab[_size - 1] = val;
		for (size_type j = 0; j < _size - 1; ++j)
			_alloc.destroy(tmp + j);
		_alloc.deallocate(tmp, _capacity / 2);
	}
	else if (_size < _capacity)
	{
		T *tmp = _tab;
		_size++;
		_tab = _alloc.allocate(_capacity);
		for (size_type i = 0; i < _size - 1; ++i)
		{
			_alloc.construct(&_tab[i], tmp[i]);
		}
		_tab[_size - 1] = val;
		for (size_type j = 0; j < _size - 1; ++j)
			_alloc.destroy(tmp + j);
		_alloc.deallocate(tmp, _capacity);
	}
}

template <class T, class Alloc>
void vector<T, Alloc>::pop_back(void)
{
	
	T *tmp = _tab;
	_size--;
	_tab = _alloc.allocate(_capacity);
	for (size_type i = 0; i < _size + 1; ++i)
		_tab[i] = tmp[i];
	for (size_type j = 0; j < _size + 1; ++j)
		_alloc.destroy(tmp + j);
	_alloc.deallocate(tmp, _capacity);
}

template <class T, class Alloc>
void vector<T, Alloc>::clear(void)
{
	for (size_type i = 0; i < _size; i++)
		_alloc.destroy(_tab + i);
	_size = 0;
}

template <class T, class Alloc>
void vector<T, Alloc>::assign(size_type n, const value_type &val)
{
	clear();
	while (n)
	{
		push_back(val);
		n--;
	}
}

template <class T, class Alloc>
void vector<T, Alloc>::swap(vector<T, Alloc>& x)
{
	T		*tmp = _tab;
	size_type	tmp_size = _size;
	size_type	tmp_capacity = _capacity;
	Alloc		tmp_alloc = get_allocator();

	_tab = x._tab;
	_size = x.size();
	_capacity = x.capacity();
	_alloc = x.get_allocator();
	x._tab = tmp;
	x._size = tmp_size;
	x._capacity = tmp_capacity;
	x._alloc = tmp_alloc;

}
}
#endif

