#include "includes/vector.hpp"
#include "includes/reverse_iterator.hpp"
#include "includes/iterator_traits.hpp"
#include <iterator>
#include <iostream>
#include <vector>
#include <stdio.h>


#define NAME_SPACE ft

int	main(void)
{
	NAME_SPACE::vector<int>	ft(3, 1);
	//NAME_SPACE::vector<int>	ft2(3);
	//NAME_SPACE::vector<int>::const_iterator o = ft.begin();
	//NAME_SPACE::vector<int>::const_reverse_iterator p(o);
	ft.clear();
	ft.empty();
}

