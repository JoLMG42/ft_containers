#include "includes/RBT.hpp"
#include "includes/map.hpp"
#include "includes/pair.hpp"
#include "includes/make_pair.hpp"
#include <iostream>
#include <iomanip>

  /*void printHelper(ft::Node *root, std::string indent, bool last) {
    if (root != NULL) {
      std::cout << indent;
      if (last) {
        std::cout << "R----";
        indent += "   ";
      } else {
        std::cout << "L----";
        indent += "|  ";
      }

      std::string sColor;
	if (root->m_color)
		sColor = "BLACK";
	else
		sColor = "RED";
		
      //std::string sColor = root->m_color ? "" : "false";
      std::cout << root->key << "(" << sColor << ")" << std::endl;
      printHelper(root->m_left, indent, false);
      printHelper(root->m_right, indent, true);
    }
  }

  void printTree(ft::RBT t) {
    if (t.getRoot()) {
      printHelper(t.getRoot(), "", true);
    }
    }*/
	void	real_print(ft::RBT<ft::map<int, int>::key_type, ft::map<int, int>::mapped_type, ft::map<int, int>::value_type, ft::map<int, int>::key_compare>::Node<int> *ptr, int space, ft::RBT<ft::map<int, int>::key_type, ft::map<int, int>::mapped_type, ft::map<int, int>::value_type, ft::map<int, int>::key_compare> test)
	{
		if (!ptr || ptr == test.getNULL())
		{
			return;
		}
		space += 4;
		real_print(ptr->m_right, space, test);
		std::cout
			<< (ptr->m_color == ft::s_black ? "\033[90m" : "\033[31m") << std::setw(space)
			<< ptr->p->first << "\033[0m" << std::endl;
		// getwchar();
		real_print(ptr->m_left, space, test);
	}

int	main(void)
{
	ft::map<int, int, std::less<int>, std::allocator<ft::pair<const int, int>> > M;
	//ft::RBT<char *, char *> test;
	/*M._tree.insertNode(ft::make_pair(50, 50));
	real_print(M._tree.getRoot(), 0, M._tree);
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	M._tree.insertNode(ft::make_pair(8, 8));
	real_print(M._tree.getRoot(), 0, M._tree);
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	M._tree.insertNode(ft::make_pair(99, 99));
	real_print(M._tree.getRoot(), 0, M._tree);
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	M._tree.insertNode(ft::make_pair(1, 1));
	real_print(M._tree.getRoot(), 0, M._tree);
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	M._tree.insertNode(ft::make_pair(54, 54));
	real_print(M._tree.getRoot(), 0, M._tree);
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	M._tree.insertNode(ft::make_pair(7, 7));
	real_print(M._tree.getRoot(), 0, M._tree);
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	M._tree.insertNode(ft::make_pair(16, 16));
	real_print(M._tree.getRoot(), 0, M._tree);
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	if (M.count(7))
		std::cout << "TROUVEEEE LOL\n";
	else
		std::cout << "OUINNNNN\n";
	if (M.count(86 ))
		std::cout << "TROUVEEEE LOL\n";
	else
		std::cout << "OUINNNNN\n";
	std::cout << "SIZZEEEE before clear(): " << M.size() << "\n";
	//real_print(M._tree.getRoot(), 0, M._tree);
	M.clear();
	std::cout << "SIZZEEEE after clear(): " << M.size() << "\n";*/
	/*M._tree.insertNode(ft::make_pair(1, 8));
	real_print(M._tree.getRoot(), 0, M._tree);
	M._tree.insertNode(ft::make_pair(2, 9));
	real_print(M._tree.getRoot(), 0, M._tree);
	M._tree.insertNode(ft::make_pair(3, 10));
	real_print(M._tree.getRoot(), 0, M._tree);*/
	M._tree.insertNode(ft::make_pair(50, 50));
	M._tree.insertNode(ft::make_pair(20, 20));
	//M._tree.insertNode(ft::make_pair(30, 30));
	//M._tree.insertNode(ft::make_pair(1, 1));
	real_print(M._tree.getRoot(), 0, M._tree);
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	//M.erase(M.begin());
	/*M._tree.insertNode(ft::make_pair(8, 8));
	real_print(M._tree.getRoot(), 0, M._tree);
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	M._tree.insertNode(ft::make_pair(99, 99));
	real_print(M._tree.getRoot(), 0, M._tree);
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	M._tree.insertNode(ft::make_pair(1, 1));
	real_print(M._tree.getRoot(), 0, M._tree);
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	M._tree.insertNode(ft::make_pair(54, 54));
	real_print(M._tree.getRoot(), 0, M._tree);
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	M._tree.insertNode(ft::make_pair(7, 7));
	real_print(M._tree.getRoot(), 0, M._tree);
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	M._tree.insertNode(ft::make_pair(16, 16));
	real_print(M._tree.getRoot(), 0, M._tree);
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "ADD MULTIPLE NODE\n";
	M._tree.insertNode(ft::make_pair(43, 43));
	M._tree.insertNode(ft::make_pair(71, 71));
	M._tree.insertNode(ft::make_pair(83, 83));
	M._tree.insertNode(ft::make_pair(987, 987));
	M._tree.insertNode(ft::make_pair(12, 12));
	M._tree.insertNode(ft::make_pair(52, 52));
	real_print(M._tree.getRoot(), 0, M._tree);
	M._tree.ft_test();*/
	/*M._tree.insertNode(ft::make_pair(1, 8));
	M._tree.insertNode(ft::make_pair(2, 9));
	M._tree.insertNode(ft::make_pair(3, 10));
	real_print(M._tree.getRoot(), 0, M._tree);*/
	//test.insertNode((char *)"salut1");
	//test.insertNode((char *)"salut2");
	//test.insertNode((char *)"salut");
	//test.insertNode((char *)"salut1");
	//test.insertNode((char *)"salut2");
	//real_print(test.getRoot(), 0, test);
	//test.initNode(test.getRoot());
	/*test.insertNode(2);
	//printTree(test);
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	test.insertNode(4);
	//printTree(test);
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	test.insertNode(1);
	//printTree(test);
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	test.insertNode(70);
	real_print(test.getRoot(), 0, test);
	//printTree(test);
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	test.insertNode(99);
	//printTree(test);
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	test.insertNode(77);
	real_print(test.getRoot(), 0, test);
	//printTree(test);
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	test.deleteNode(test.getRoot(), 70);
	real_print(test.getRoot(), 0, test);
	//printTree(test);*/
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
