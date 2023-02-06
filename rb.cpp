#include "includes/RBT.hpp"
#include <iostream>

int	main(void)
{
	ft::RBT test;
	test.insertNode(2);
	test.insertNode(4);
	test.insertNode(1);
	test.insertNode(5);
	test.insertNode(8);
	test.insertNode(70);
	test.insertNode(99);
	ft::Node *tmp = test.getRoot();
	if (tmp)
	{
		std::cout << "parent: " << test.getRoot()->key << "\n";
	}
	while (tmp->m_right)
	{
		if (tmp->m_right)
		{
			std::cout << "right child: " << test.getRoot()->m_right->key << "\n";
			tmp->m_right = tmp->m_right->m_right;
		}
	}
	tmp = test.getRoot();
	while (tmp->m_left)
	{
		if (tmp->m_left)
		{
			std::cout << "left child: " << test.getRoot()->m_left->key << "\n";
			tmp->m_left = tmp->m_left->m_left;
		}
	}
}
