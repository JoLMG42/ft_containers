#include <stack>
#include <vector>

#include "includes/stack.hpp"

#if STD
        #define NAME_SPACE std
#else
        #define NAME_SPACE ft
#endif

#define TESTED_TYPE int

int	main(void)
{

	ft::stack<int> st;
	st.push(1);
	st.push(3);
	st.push(6);
	st.push(8);
	std::cout << "FT Stack size: " << st.size() << std::endl;
	std::cout << "FT Stack empty: " << st.empty() << std::endl;
	std::cout << "POP test: \n";
	st.pop();
	std::cout << "FT Stack size: " << st.size() << std::endl;
}
