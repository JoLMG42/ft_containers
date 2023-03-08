#include "includes/map.hpp"
#include "containers_test/srcs/base.hpp"

#define T1 int
#define T2 int
#define TESTED_NAMESPACE ft
#define _pair TESTED_NAMESPACE::pair

typedef TESTED_NAMESPACE::map<T1, T2>::value_type T3;
typedef TESTED_NAMESPACE::map<T1, T2>::iterator ft_iterator;
typedef TESTED_NAMESPACE::map<T1, T2>::const_iterator ft_const_iterator;

static int iter = 0;


template <typename T>
std::string     printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
        o << "key: " << iterator->first << " | value: " << iterator->second;
        if (nl)
                o << std::endl;
        return ("");
}

template <typename T_MAP>
void    printSize(T_MAP const &mp, bool print_content = 1)
{
        std::cout << "size: " << mp.size() << std::endl;
        std::cout << "max_size: " << mp.max_size() << std::endl;
        if (print_content)
        {
                typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
                std::cout << std::endl << "Content is:" << std::endl;
                for (; it != ite; ++it)
                        std::cout << "- " << printPair(it, false) << std::endl;
        }
        std::cout << "###############################################" << std::endl;
}


int		main(void)
{
	TESTED_NAMESPACE::map<T1, T2> mp;
	TESTED_NAMESPACE::map<T1, T2>::iterator it = mp.begin();
	TESTED_NAMESPACE::map<T1, T2>::const_iterator cit = mp.begin();

	TESTED_NAMESPACE::map<T1, T2>::reverse_iterator rit(it);

	TESTED_NAMESPACE::map<T1, T2>::const_reverse_iterator crit(rit);
	TESTED_NAMESPACE::map<T1, T2>::const_reverse_iterator crit_(it);
	TESTED_NAMESPACE::map<T1, T2>::const_reverse_iterator crit_2(cit);

	/* error expected
	TESTED_NAMESPACE::map<T1, T2>::reverse_iterator rit_(crit);
	TESTED_NAMESPACE::map<T1, T2>::reverse_iterator rit2(cit);
	TESTED_NAMESPACE::map<T1, T2>::iterator it2(rit);
	TESTED_NAMESPACE::map<T1, T2>::const_iterator cit2(crit);
	*/

	std::cout << "OK" << std::endl;
	return (0);
}
