#include "vector.hpp"

int main()
{

	ft::vector<int> vector_int;

	//ft::vector<int> vector_long(4,2);

	vector_int.push_back(8);
	vector_int.push_back(666); 


	std::cout << vector_int[0] << std::endl;
	std::cout << vector_int[1] << std::endl;

	vector_int.pop_back();

	std::cout << vector_int[1] << std::endl;

	vector_int.push_back(777);

	std::cout << vector_int[1] << std::endl;

	//std::cout << "capacity = " << vector_long.capacity() << std::endl;

	//std::cout << "test here" ;
	 //vector_long.reserve(15);

	// std::cout << "capacity = " << vector_long.capacity() << std::endl;

	//std::cout << vector_int.front() << std::endl;

	//std::cout << "Max size =" << vector_int.max_size() << std::endl;

//	ft::vector<int>::iterator lol;

	std::cout << std::endl << "attention pas de flags dans le makefile \n\
	+ verif pop back pop au bon endroit?" << std::endl;

}