#include "map.hpp"
#include "tree.hpp"
#include "map_iterator.hpp"
#include <map>


//note : voir 2.0.cpp


// void print_map(ft::map<int, std::string>::iterator first, ft::map<int, std::string>::iterator last)
// {
//     for (; first != last; ++first) {
//         std::cout << "K: " << first->first << " V: " << first->second << " ";
//     }
//     std::cout << std::endl;
// }

// void print_map(std::map<int, std::string>::iterator first, std::map<int, std::string>::iterator last)
// {
//     for (; first != last; ++first) {
//         std::cout << "K: " << first->first << " V: " << first->second << " ";
//     }
//     std::cout << std::endl;
// }

template <typename Key, typename T>
void print_map(ft::map<Key, T> &map)
{
	typename ft::map<Key, T>::iterator first = map.begin();
	typename ft::map<Key, T>::iterator last = map.end();

	std::cout << "Content: " << std::endl;
	for (; first != last; first++)
	{
		std::cout << ((*first).first) << " : " << ((*first).second) << "\n";
	}

	std::cout << std::endl;
	std::cout << "Size: " << map.size() << std::endl;
	std::cout << std::endl;
}


int main()
{
	ft::map<int, std::string> c;

		

		c.insert(ft::make_pair<int, std::string>(5, "Hello"));
		c.insert(ft::make_pair<int, std::string>(42, "quatre deux"));
		c.insert(ft::make_pair<int, std::string>(22, "Hola"));
		c.insert(ft::make_pair<int, std::string>(-8, "Halo"));
		c.insert(ft::make_pair<int, std::string>(8, "Salut"));

		print_map(c);

std::cout << "start erasse 42" << std::endl; //here
		c.erase(42);
std::cout << "end erase 42" << std::endl; //here
		print_map(c);

		c.erase(c.begin());

		std::cout << "pouet" << std::endl; //here

		print_map(c);

		std::cout << "pouet2" << std::endl;

		std::cout << "size (maxime) = " << c.size() << std::endl;

		ft::map <int ,std::string >::iterator iter;

		std::cout << "end =" << c.end()->second <<std::endl;

		for (iter = c.begin();iter != c.end(); iter ++)
			std::cout << "-" << iter->second <<std::endl;

		c.erase(c.begin(), c.end());

		std::cout << "pouet3" << std::endl;

		print_map(c);

		std::cout << "pouet4" << std::endl;
}

