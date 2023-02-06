#include "map.hpp"
#include "tree.hpp"
#include "map_iterator.hpp"
#include <map>


void print_map(ft::map<int,int>::iterator first, ft::map<int,int>::iterator last)
{
    for (; first != last; ++first) {
        std::cout << "K: " << first->first << " V: " << first->second << " ";
    }
    std::cout << std::endl;
}

void print_map(std::map<int,int>::iterator first, std::map<int,int>::iterator last)
{
    for (; first != last; ++first) {
        std::cout << "K: " << first->first << " V: " << first->second << " ";
    }
    std::cout << std::endl;
}


int main()
{
	{
		ft::map<int, int> lol;

		//lol.insert(ft::make_pair<int, int>(40, 40));

		//lol.insert(ft::make_pair<int, int>(-1, -1));
		//lol.insert(ft::make_pair<int, int>(0, 0));
		//lol.insert(ft::make_pair<int, int>(5, 5));

		// lol.insert(ft::make_pair<int, int>("16", "(16)"));
		// lol.insert(ft::make_pair<int, int>("-3", "Smallest(-3)"));
		// lol.insert(ft::make_pair<int, int>("7", "(7)"));
		// lol.insert(ft::make_pair<int, int>("50", "(50)"));
		// lol.insert(ft::make_pair<int, int>("45", "(45)"));
		// lol.insert(ft::make_pair<int, int>("55", "Biggest(55)"));
		// lol.insert(ft::make_pair<int, int>("8", "(8)"));

		std::cout << "size =" << lol.size() << std::endl;

		ft::map<int,int>::iterator iterator;
		ft::map<int,int>::iterator finish;

		iterator = lol.begin();

		//std::cout << "check\n";

		finish = lol.end();

		//std::cout << "check\n";

		for(; iterator != lol.end(); iterator ++ )
			std::cout << "iterator on " << (*iterator).second << std::endl;
		
		

		std::cout << std::endl;

		for(iterator = lol.end() ; iterator != lol.begin(); iterator -- )
		 	std::cout << "iterator on " << (*iterator).second << std::endl;

		print_map(lol.begin(), lol.end());		

	}
	std::cout<< std::endl << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"<< std::endl << std::endl;
	{
		std::map<int, int> lol;

		//lol.insert(std::make_pair<int, int>(40, 40));

		//lol.insert(std::make_pair<int, int>(-1, -1));
		//lol.insert(std::make_pair<int, int>(0, 0));
		//lol.insert(std::make_pair<int, int>(5, 5));

		// lol.insert(ft::make_pair<int, int>("16", "(16)"));
		// lol.insert(ft::make_pair<int, int>("-3", "Smallest(-3)"));
		// lol.insert(ft::make_pair<int, int>("7", "(7)"));
		// lol.insert(ft::make_pair<int, int>("50", "(50)"));
		// lol.insert(ft::make_pair<int, int>("45", "(45)"));
		// lol.insert(ft::make_pair<int, int>("55", "Biggest(55)"));
		// lol.insert(ft::make_pair<int, int>("8", "(8)"));

		std::cout << "size =" << lol.size() << std::endl;

		std::map<int,int>::iterator iterator;

		for(iterator = lol.begin(); iterator != lol.end(); iterator ++ )
			std::cout << "iterator on " << (*iterator).second << std::endl;
			
		std::cout << std::endl;

		for(iterator = lol.end() ; iterator != lol.begin(); iterator -- )
		 	std::cout << "iterator on " << (*iterator).second << std::endl;

		print_map(lol.begin(), lol.end());
	}
}

