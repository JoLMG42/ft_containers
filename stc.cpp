#include <stack>
#include <vector>

#include "stack.hpp"

int	main(void)
{

	ft::vector<int> test(3, 3);
	ft::stack<int> st;
	std::vector<int> real(3, 3);
	std::stack<int> realst;
	std::cout << "REAL Stack size: " << realst.size() << std::endl;
	std::cout << "FT Stack size: " << st.size() << std::endl;
	std::cout << "REAL Stack empty: " << realst.empty() << std::endl;
	std::cout << "FT Stack empty: " << st.empty() << std::endl;
	std::cout << "REAL Stack pop: " << std::endl; // << st.pop() << std::endl;
	std::cout << "FT Stack pop: " << std::endl; // << ft.pop() << std::endl;
	std::cout << "REAL Stack size: " << realst.size() << std::endl;
	std::cout << "FT Stack size: " << st.size() << std::endl;

	

}
