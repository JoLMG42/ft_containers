#include "vector.hpp"

#define TESTED_TYPE int
#define TESTED_NAMESPACE ft

int		main(void)
{
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(5);
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct2;
	const int cut = 3;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 7;

	vct2.insert(vct2.begin(), vct.begin(), vct.begin() + cut);
	vct2.insert(vct2.begin(), vct.begin() + cut, vct.end());
	vct2.insert(vct2.end(), vct.begin(), vct.begin() + cut);

	std::cout << "insert return:" << std::endl;

	std::cout << *vct2.insert(vct2.end(), 42) << std::endl;
	std::cout << *vct2.insert(vct2.begin() + 5, 84) << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	return (0);
}
