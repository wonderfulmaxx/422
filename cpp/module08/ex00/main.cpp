#include "easyfind.hpp"

int main()
{
	std::list<int> l;
	std::list<int>::iterator cible;

	l.push_back(10);
	l.push_back(-15);
	l.push_back(0);
	l.push_back(2);

	try
	{
		easyfind(l,200);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}
}