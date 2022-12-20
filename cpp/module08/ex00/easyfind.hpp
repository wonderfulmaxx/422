# include <iostream>
# include <string>
# include <list>

class NotFound : public std::exception
{
	const char *what() const throw()
	{
		return ("Not found");
	}
};

template<typename T>
void easyfind (T tab, int i)
{
	typename T::iterator it;

	it = find(tab.begin(), tab.end(),i);
	if (*it == i)
		std::cout << "Number found : " << i << std::endl;
	else 
		throw NotFound();
};