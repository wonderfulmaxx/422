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
		lol.insert(ft::make_pair<int, std::string>(1, "1"));
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
		ft::map<int, std::string>::iterator iterator_bis;
		ft::map<int, std::string>::iterator end_iterator;

		iterator = lol.begin();
		iterator_bis = iterator;
		iterator_bis ++;
		end_iterator = lol.end();

		// // std::cout << "here :" << iterator->second << std::endl;

		while (iterator != end_iterator)
		{
			std::cout << "iterator a supp = " << iterator->second ;
			lol.erase(iterator);
			std::cout << "ok" << std::endl;
			iterator = iterator_bis;
			iterator_bis ++;
		}

		//  std::cout << "here :" << end_iterator->second << std::endl;
		
		
		
		// //iterator ++;

		// // for (; iterator != end_iterator; iterator ++)
		// // {
		// // 	std::cout << iterator->second<< std::endl;
		// // }
		

	}
	// std::cout<< std::endl << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"<< std::endl << std::endl;
	// {
	// 	std::map<int, std::string> lol;

	// 	lol.insert(std::make_pair<int, std::string>(40, "40"));

	// 	lol.insert(std::make_pair<int, std::string>(-1, "-1"));
	// 	lol.insert(std::make_pair<int, std::string>(1, "1"));
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
	// 	std::map<int, std::string>::iterator iterator_bis;
	// 	std::map<int, std::string>::iterator end_iterator;
	// 	iterator = lol.begin();
	// 	iterator_bis = iterator;
	// 	end_iterator = lol.end();
	// 	//end_iterator --;
	// 	//end_iterator --;

	// 	std::cout << "here :" << end_iterator->second << std::endl;

	// 	//std::cout << "result :" << lol.erase(iterator,end_iterator)->second << std::endl;

	// 	iterator_bis ++;
	// 	lol.erase(iterator);
	// 	iterator = iterator_bis;
	// 	std::cout<<iterator->second << std::endl;

	// 	// std::cout << "here :" << end_iterator->second << std::endl;
		
	// 	// // end_iterator --;
	// 	// // end_iterator --;

	// 	// // std::cout << "here :" << end_iterator->second << std::endl;

	// 	// for (; iterator != end_iterator; iterator ++)
	// 	// {
	// 	// 	std::cout << iterator->second<< std::endl;
	// 	// }
	// }
}

