#include "map.hpp"
#include "tree.hpp"
#include "map_iterator.hpp"
#include <map>

#include <iterator>

//Note la recopie ne marche plus lol
//je pense quil faut que begin et end soit egaux si larbre est vide, or la il me semble quils sont sur invisible node inf et sup



int main()
{
	// ft::map<int, std::string> lol;

	// 	lol.insert(ft::make_pair<int, std::string>(40, "40"));

	// 	lol.insert(ft::make_pair<int, std::string>(-1, "-1"));
	// 	lol.insert(ft::make_pair<int, std::string>(1, "1"));
	// 	lol.insert(ft::make_pair<int, std::string>(5, "5"));

	// 	lol.insert(ft::make_pair<int, std::string>(16, "(16)"));
	// 	lol.insert(ft::make_pair<int, std::string>(-3, "Smallest(-3)"));
	// 	lol.insert(ft::make_pair<int, std::string>(7, "(7)"));
	// 	lol.insert(ft::make_pair<int, std::string>(50, "(50)"));
	// 	lol.insert(ft::make_pair<int, std::string>(45, "(45)"));
	// 	lol.insert(ft::make_pair<int, std::string>(55, "Biggest(55)"));
	// 	lol.insert(ft::make_pair<int, std::string>(8, "(8)"));

	// 	ft::map<int, std::string>::iterator m_start = lol.begin();
	// 	ft::map<int, std::string>::iterator m_end = std::advance(m_start,3);

	// 	//ft::map<int, std::string> m(lol.begin(),lol.begin()+3);


	// 	ft::map<int, std::string>::iterator iterator = lol.begin();

	// 	lol.erase(iterator);

	// 	ft::map<int, std::string>::iterator first = lol.begin();
	// 	ft::map<int, std::string>::iterator last = lol.end();

	// 	 for (; first != last; ++first) {
    //     std::cout << "K: " << first->first << " V: " << first->second << " ";
    // }
    // std::cout << std::endl;


	ft::map<int, std::string> lol;

	lol.insert(ft::make_pair<int, std::string>(40, "40"));

	//lol.insert(ft::make_pair<int, std::string>(-1, "-1"));
	//lol.insert(ft::make_pair<int, std::string>(1, "1"));
	//lol.insert(ft::make_pair<int, std::string>(5, "5"));

	//lol.insert(ft::make_pair<int, std::string>(16, "(16)"));
	lol.insert(ft::make_pair<int, std::string>(-3, "Smallest(-3)"));
	//lol.insert(ft::make_pair<int, std::string>(7, "(7)"));
	//lol.insert(ft::make_pair<int, std::string>(50, "(50)"));
	//lol.insert(ft::make_pair<int, std::string>(45, "(45)"));
	lol.insert(ft::make_pair<int, std::string>(55, "Biggest(55)"));
	//lol.insert(ft::make_pair<int, std::string>(8, "(8)"));

	//ft::map<int, std::string>::iterator m_start = lol.begin();

	//std::cout << lol[4] << std::endl;
	//std::cout << lol[4] << std::endl;

	//lol.at(-3);

	//std::cout << "-" << lol.test()->second << "-" << std::endl;

	lol.erase (lol.begin(),lol.end());
	//lol.erase (lol.begin());

	std :: cout << "lire a partir dici------------------------------\n";

	
	ft::map<int, std::string>::iterator last = lol.end();
	ft::map<int, std::string>::iterator first = lol.begin();

	lol.test();

std::cout << "etape 2 ------------------\n";

	for (; first != last; first++)
		std::cout << "-"<<first->second <<"-"<< std::endl;
	//std::cout << "-"<<last->second <<"-"<< std::endl;

	std::cout << "finis\n";

	// ft::map<int, std::string> m(lol);


	// std :: cout << "lol\n";

	// std::map<int, std::string> loli;
	// std::cout << loli[4] << std::endl;
	// std::cout << loli[4] << std::endl;



}


// int main()
// {
// 	std::map<int, std::string> lol;

// 	lol.insert(std::make_pair<int, std::string>(40, "40"));

// 	//lol.insert(std::make_pair<int, std::string>(-1, "-1"));
// 	//lol.insert(std::make_pair<int, std::string>(1, "1"));
// 	//lol.insert(std::make_pair<int, std::string>(5, "5"));

// 	//lol.insert(std::make_pair<int, std::string>(16, "(16)"));
// 	//lol.insert(std::make_pair<int, std::string>(-3, "Smallest(-3)"));
// 	//lol.insert(std::make_pair<int, std::string>(7, "(7)"));
// 	//lol.insert(std::make_pair<int, std::string>(50, "(50)"));
// 	//lol.insert(std::make_pair<int, std::string>(45, "(45)"));
// 	lol.insert(std::make_pair<int, std::string>(55, "Biggest(55)"));
// 	//lol.insert(std::make_pair<int, std::string>(8, "(8)"));

// 	//std::map<int, std::string>::iterator m_start = lol.begin();

// 	//std::cout << lol[4] << std::endl;
// 	//std::cout << lol[4] << std::endl;

// 	//lol.at(-3);

// 	//std::cout << "-" << lol.test()->second << "-" << std::endl;

// 	lol.erase (lol.begin(),lol.end());
// 	//lol.erase (lol.begin());

// 	std :: cout << "lire a partir dici------------------------------\n";

	
// 	std::map<int, std::string>::iterator last = lol.end();
// 	std::map<int, std::string>::iterator first = lol.begin();

// 	//lol.test();

// std::cout << "etape 2 ------------------\n";

// 	for (; first != last; first++)
// 		std::cout << "-"<<first->second <<"-"<< std::endl;
// 	//std::cout << "-"<<last->second <<"-"<< std::endl;

// 	std::cout << "finis\n";
// }