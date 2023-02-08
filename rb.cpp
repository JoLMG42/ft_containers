#include "includes/RBT.hpp"
#include <iostream>

  void printHelper(ft::Node *root, std::string indent, bool last) {
    if (root != NULL) {
      std::cout << indent;
      if (last) {
        std::cout << "R----";
        indent += "   ";
      } else {
        std::cout << "L----";
        indent += "|  ";
      }

      std::string sColor = root->m_color ? "RED" : "BLACK";
      std::cout << root->key << "(" << sColor << ")" << std::endl;
      printHelper(root->m_left, indent, false);
      printHelper(root->m_right, indent, true);
    }
  }

  void printTree(ft::RBT t) {
    if (t.getRoot()) {
      printHelper(t.getRoot(), "", true);
    }
    }

int	main(void)
{
	ft::RBT test;
	test.insertNode(2);
	test.insertNode(4);
	test.insertNode(1);
	//test.insertNode(5);
	//test.insertNode(8);
	test.insertNode(70);
	test.insertNode(99);
	printTree(test);
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	test.deleteNode(test.getRoot(), 70);
	printTree(test);
	/*ft::Node *tmp = test.getRoot();
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
	}*/
}
