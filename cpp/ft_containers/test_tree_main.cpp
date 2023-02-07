#include "map.hpp"
#include "tree.hpp"
#include "map_iterator.hpp"
#include <map>


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


int main()
{
	{
		ft::map<int, std::string> lol;

		lol.insert(ft::make_pair<int, std::string>(40, "40"));

		lol.insert(ft::make_pair<int, std::string>(-1, "-1"));
		lol.insert(ft::make_pair<int, std::string>(0, "0"));
		lol.insert(ft::make_pair<int, std::string>(5, "5"));

		lol.insert(ft::make_pair<int, std::string>(16, "(16)"));
		lol.insert(ft::make_pair<int, std::string>(-3, "Smallest(-3)"));
		lol.insert(ft::make_pair<int, std::string>(7, "(7)"));
		lol.insert(ft::make_pair<int, std::string>(50, "(50)"));
		lol.insert(ft::make_pair<int, std::string>(45, "(45)"));
		lol.insert(ft::make_pair<int, std::string>(55, "Biggest(55)"));
		lol.insert(ft::make_pair<int, std::string>(8, "(8)"));

		std::cout << "size =" << lol.size() << std::endl;

		

		ft::map<int, std::string>::iterator iterator;

		

		iterator = lol.begin();

		std::cout << "erase return = " << lol.erase(iterator)->second << std::endl;

		// for(; iterator != lol.end(); iterator ++ )
		// 	std::cout << "iterator on " << (*iterator).second << std::endl;
		
		

		// std::cout <<  std::endl << "lol.rend = " << lol.end()->second << " , lol.rbegin = " << lol.rbegin()->second <<std::endl << std::endl << "debut vers fin en dessous la"  << std::endl;

		// for(/*iterator = lol.rend()*/ ; iterator != lol.begin(); iterator -- )
		//  	std::cout << "iterator on " << (*iterator).second << std::endl;

		// std::cout << "finis car iterator(rend) = " << iterator->second << " et target(rbegin) = " << lol.rbegin()->second << std::endl;

		//print_map(lol.begin(), lol.end());		

	}
	std::cout<< std::endl << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"<< std::endl << std::endl;
	// {
	// 	std::map<int, std::string> lol;

	// 	lol.insert(std::make_pair<int, std::string>(40, "40"));

	// 	lol.insert(std::make_pair<int, std::string>(-1, "-1"));
	// 	lol.insert(std::make_pair<int, std::string>(0, "0"));
	// 	lol.insert(std::make_pair<int, std::string>(5, "5"));

	// 	lol.insert(std::make_pair<int, std::string>(16, "(16)"));
	// 	lol.insert(std::make_pair<int, std::string>(-3, "Smallest(-3)"));
	// 	lol.insert(std::make_pair<int, std::string>(7, "(7)"));
	// 	lol.insert(std::make_pair<int, std::string>(50, "(50)"));
	// 	lol.insert(std::make_pair<int, std::string>(45, "(45)"));
	// 	lol.insert(std::make_pair<int, std::string>(55, "Biggest(55)"));
	// 	lol.insert(std::make_pair<int, std::string>(8, "(8)"));

	// 	std::cout << "size =" << lol.size() << std::endl;

	// 	std::map<int, std::string>::iterator iterator;

	// 	iterator = lol.begin();

	// 	for(; iterator != lol.end(); iterator ++ )
	// 		std::cout << "iterator on " << (*iterator).second << std::endl;
			
	// 	std::cout << std::endl;

	// 	for(iterator = lol.end() ; iterator != lol.begin(); iterator -- )
	// 	 	std::cout << "iterator on " << (*iterator).second << std::endl;

	// 	//print_map(lol.begin(), lol.end());
	// }
}

