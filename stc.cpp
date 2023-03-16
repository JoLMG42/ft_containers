#include <stack>
#include <vector>

#include "includes/stack.hpp"

int	main(void)
{

	ft::stack<int> st;
	std::cout << "FT Stack size: " << st.size() << std::endl;
	std::cout << "FT Stack empty: " << st.empty() << std::endl;
	std::cout << "POP test: \n";
	st.pop();
	std::cout << "FT Stack size: " << st.size() << std::endl;
}
