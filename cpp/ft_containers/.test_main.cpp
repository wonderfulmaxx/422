#include <iostream>
#include <string>
#include <deque>
#include <vector>


int main()
{
	std::vector<int> vector_int;

	std::vector<int>::iterator target;
	//target += 3;

	vector_int.insert(target,4002);

	for (target = vector_int.begin(); target != vector_int.end(); target ++)
		std::cout << (*target)<< std::endl;

	return(0);
}