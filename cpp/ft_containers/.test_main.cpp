#include <iostream>
#include <string>
#include <deque>
#include <vector>


int main()
{
	std::vector<int> vector_int;

	std::vector<int>::iterator target;

	vector_int.push_back(11);
	vector_int.push_back(11);

	vector_int.assign(7,4);

	for (target = vector_int.begin(); target != vector_int.end(); target ++)
		std::cout << (*target)<< std::endl;

	return(0);
}