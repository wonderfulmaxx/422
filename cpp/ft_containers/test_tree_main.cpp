#include "map.hpp"
#include "tree.hpp"
#include "map_iterator.hpp"

int main()
{

//	Note : il faut tester les supprimer en debut et fin d'arbre, tester si ils prennenent bien en compte previous et next, puis faire les iterateurs
//  Note : il faut changer les verif de node invisible et le rendre plus stable en l'inscrivant dans une variable pointeur par exemple.

	// ft::Tree<int,int> lol;
	// lol.inserer(42);
	// lol.inserer(20);
	// lol.inserer(10);
	// lol.inserer(3);
	// lol.inserer(12);

	// lol.supprimer(20);

	// std::cout << lol.recherche(10)->donnees;
	ft::map<int,std::string> lol;
	//ft::map<int,int> lol;

	//lol.insert(ft::make_pair<int, std::string>(5, "Hello"));

	try
	{
		// lol.insert(ft::make_pair<int,int>(6,666));
		// lol.insert(ft::make_pair<int,int>(9,999));

		

		lol.insert(ft::make_pair<int,std::string>(40,"racine(40)"));

		//lol.test(40);
		
		lol.insert(ft::make_pair<int,std::string>(-1,"(-1)"));
		lol.insert(ft::make_pair<int,std::string>(5,"(5)"));
		lol.insert(ft::make_pair<int,std::string>(16,"(16)"));
		lol.insert(ft::make_pair<int,std::string>(-3,"Smallest(-3)"));
		lol.insert(ft::make_pair<int,std::string>(7,"(7)"));
		lol.insert(ft::make_pair<int,std::string>(50,"(50)"));
		lol.insert(ft::make_pair<int,std::string>(45,"(45)"));
		lol.insert(ft::make_pair<int,std::string>(55,"Biggest(55)"));
		std::cout << lol.insert(ft::make_pair<int,std::string>(8,"(8)")).second << std::endl;
			//std::cout << "caca\n";

		ft::map<int,std::string>::iterator ite_end= lol.end();
		ft::map<int,std::string>::iterator ite_start= lol.begin();

		ft::map<int,std::string> loli(ite_start,ite_end);

		ft::map<int,std::string>::iterator pouet = loli.end();

		for (; pouet != loli.begin(); pouet--)
			std::cout << (*pouet).second << std::endl;


		std::cout << (*pouet).second << std::endl;
		-- pouet;
		std::cout <<"ite on -"<< (*pouet).first << "-" <<std::endl;

		// ++pouet;
		// std::cout <<"ite on "<< (*pouet).second << std::endl;


		// std::cout << "size = " << lol.size() << std::endl;
		// pouet = lol.end();

		// std::cout << (*pouet).second << std::endl;

		//lol.test();

		


	//	std::cout << (lol.at(45))<< std::endl;
		//std::cout << lol
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	

}


// #include <iostream>
// #include <map>
// #include "map_utils.hpp"
// int main()
// {
//     // Create a map of three (string, int) pairs
//     std::map<int, std::string> m;
 
// 	m.insert(ft::make_pair<int, std::string>(666,"Maxime"));


// 	std::cout << m.find("maxime")->second << std::endl;
// }