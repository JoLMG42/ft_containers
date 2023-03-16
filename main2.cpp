#include <iostream>
#include <vector>
#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"

int	main(void)
{
	std::vector<int> toto(1, 1);
	toto.push_back(5);
	toto.push_back(6);
	toto.push_back(7);
	toto.push_back(5);
	toto.push_back(6);
	toto.push_back(7);
	toto.push_back(5);
	toto.push_back(6);
	toto.push_back(7);
	toto.push_back(5);
	toto.push_back(6);
	toto.push_back(7);
	toto.push_back(5);
	toto.push_back(6);
	toto.push_back(7);
	std::vector<int>::iterator it2 = toto.begin();
	std::vector<int>::reverse_iterator rev(it2);
	ft::reverse_iterator<std::vector<int>::iterator> it(it2);

	std::cout << "----- START * | [] | base test -----" << std::endl;
	std::cout << std::endl;
	std::cout << "*: " << std::endl;
	std::cout << "REAL: " << *rev << std::endl;
	std::cout << "FT: " << *it << std::endl;
	std::cout << std::endl;
	std::cout << "base: " << std::endl;
	std::cout << "REAL: " << *rev.base() << std::endl;
	std::cout << "FT: " << *it.base() << std::endl;
	std::cout << std::endl;
	std::cout << "[]: " << std::endl;
	std::cout << "REAL: " << rev[1] << std::endl;
	std::cout << "FT: " << it[1] << std::endl;
	std::cout << std::endl;
	std::cout << "----- END * | [] | base test -----" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "----- START arithmetics operator test -----" << std::endl;
	std::cout << std::endl;
	std::cout << "--x: " << std::endl;
	std::cout << "REAL: " << *rev << std::endl;
	std::cout << "FT: " << *it << std::endl;
	std::cout << "REVERSE DECREMENTATION" << std::endl;
	--rev;
	--it;
	std::cout << "REAL: " << *rev << std::endl;
	std::cout << "FT: " << *it << std::endl;
	std::cout << std::endl;
	std::cout << "x--: " << std::endl;
	std::cout << "REAL: " << *rev << std::endl;
	std::cout << "FT: " << *it << std::endl;
	std::cout << "REVERSE DECREMENTATION" << std::endl;
	rev--;
	it--;
	std::cout << "REAL: " << *rev << std::endl;
	std::cout << "FT: " << *it << std::endl;
	std::cout << std::endl;
	std::cout << "++x: " << std::endl;
	std::cout << "REAL: " << *rev << std::endl;
	std::cout << "FT: " << *it << std::endl;
	std::cout << "REVERSE INCREMENTATION" << std::endl;
	++rev;
	++it;
	std::cout << "REAL: " << *rev << std::endl;
	std::cout << "FT: " << *it << std::endl;
	std::cout << std::endl;
	std::cout << "x++: " << std::endl;
	std::cout << "REAL: " << *rev << std::endl;
	std::cout << "FT: " << *it << std::endl;
	std::cout << "REVERSE INCREMENTATION" << std::endl;
	rev++;
	it++;
	std::cout << "REAL: " << *rev << std::endl;
	std::cout << "FT: " << *it << std::endl;
	std::cout << std::endl;
	std::cout << "REVERSE -=: " << std::endl;
	rev -= 9;
	it -= 9;
	std::cout << "REAL: " << *rev << std::endl;
	std::cout << "FT: " << *it << std::endl;
	std::cout << std::endl;
	std::cout << "REVERSE +=: " << std::endl;
	rev += 1;
	it += 1;
	std::cout << "REAL: " << *rev << std::endl;
	std::cout << "FT: " << *it << std::endl;
	std::cout << std::endl;
	std::cout << "REVERSE -: " << std::endl;
	rev - 1;
	it - 1;
	std::cout << "REAL: " << *rev << std::endl;
	std::cout << "FT: " << *it << std::endl;
	std::cout << std::endl;
	std::cout << "REVERSE +: " << std::endl;
	rev + 2;
	it + 2;
	std::cout << "REAL: " << *rev << std::endl;
	std::cout << "FT: " << *it << std::endl;
	std::cout << std::endl;
	std::cout << "----- END arithmetics operators -----" << std::endl;
	
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "----- START comparaison operators -----" << std::endl;	
	std::cout << std::endl;
	ft::reverse_iterator<std::vector<int>::iterator> it3(it);
	std::vector<int>::reverse_iterator rev2(rev);

	std::cout << "lhs == rhs (lhs = rhs): " << std::endl;
	bool recup = rev == rev2;
	bool recup2 = it == it3;
	std::cout << "REAL: " << recup << std::endl;
	std::cout << "FT: " << recup2 << std::endl;
	it++;
	rev++;
	std::cout << "lhs == rhs (lhs != rhs): " << std::endl;
	recup = rev == rev2;
	recup2 = it == it3;
	std::cout << "REAL: " << recup << std::endl;
	std::cout << "FT: " << recup2 << std::endl;

	std::cout << std::endl;
	std::cout << "lhs != rhs (lhs = rhs): " << std::endl;
	recup = rev != rev2;
	recup2 = it != it3;
	std::cout << "REAL: " << recup << std::endl;
	std::cout << "FT: " << recup2 << std::endl;
	it--;
	rev--;
	std::cout << "lhs != rhs (lhs != rhs): " << std::endl;
	recup = rev != rev2;
	recup2 = it != it3;
	std::cout << "REAL: " << recup << std::endl;
	std::cout << "FT: " << recup2 << std::endl;

	std::cout << std::endl;
	std::cout << "lhs <= rhs (lhs <= rhs): " << std::endl;
	recup = rev <= rev2;
	recup2 = it <= it3;
	std::cout << "REAL: " << recup << std::endl;
	std::cout << "FT: " << recup2 << std::endl;
	std::cout << "lhs >= rhs (lhs >= rhs): " << std::endl;
	recup = rev >= rev2;
	recup2 = it >= it3;
	std::cout << "REAL: " << recup << std::endl;
	std::cout << "FT: " << recup2 << std::endl;

	std::cout << std::endl;
	std::cout << "lhs < rhs (lhs < rhs): " << std::endl;
	recup = rev < rev2;
	recup2 = it < it3;
	std::cout << "REAL: " << recup << std::endl;
	std::cout << "FT: " << recup2 << std::endl;
	std::cout << "lhs > rhs (lhs > rhs): " << std::endl;
	recup = rev > rev2;
	recup2 = it > it3;
	std::cout << "REAL: " << recup << std::endl;
	std::cout << "FT: " << recup2 << std::endl;

	std::cout << std::endl;
	std::cout << "----- END comparaison operators -----" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "----- START template -/+ -----" << std::endl;
	std::cout << std::endl;
	*it++;
	*rev++;
	std::cout << "n - rhs: " << std::endl;
	rev = rev - 5;
	it = it - 5;
	std::cout << "REAL: " << *rev << std::endl;
	std::cout << "FT: " << *it << std::endl;
	std::cout << "n + rhs: " << std::endl;
	rev = 23 + rev;
	it = 23 + it;
	std::cout << "REAL: " << *rev << std::endl;
	std::cout << "FT: " << *it << std::endl;

	std::cout << std::endl;
	std::cout << "----- END template -/+ -----" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	
	
}
