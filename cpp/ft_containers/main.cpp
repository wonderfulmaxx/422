#include "vector.hpp"
#include "vector_iterator.hpp"

int main()
{

	ft::vector<int> vector_int;

	//ft::vector<int> vector_long(4,2);

	// vector_int.push_back(8);
	 vector_int.push_back(666); 


	
	//vector_int.pop_back();


	vector_int.push_back(777);

	vector_int.push_back(888);


	ft::vector<int>::iterator target = vector_int.begin();

	//vector_int.resize(7);

	ft::vector<int>::iterator index = vector_int.begin();
	 index ++ ;
	index ++ ;

	//ft::vector<int>::iterator zizi =  vector_int.insert(index,0,42);

	// std::cout << *zizi << std::endl;
	// zizi ++;
	// zizi ++;
	// std::cout << *zizi << std::endl;
	
	//std::cout << "size = " << vector_int.size() << std::endl;

	for (target = vector_int.begin();target != vector_int.end(); target ++)
		std::cout << '-' << *target << std::endl;

	std::cout << "size = " << vector_int.size() << std::endl;

	// vector_int.push_back(42);

	//const ft::vector<const int>::const_iterator target = vector_int.begin();



	// for (target = vector_int.begin();target != vector_int.end(); target ++)
	// 	std::cout << '-' << *target << std::endl;

	//std::cout << "-" <<vector_int.back() << std::endl;

	//std::cout << "begin : " << *target << std::endl;

	// if (target != vector_int.begin())
	// 	std::cout << "diff" << std::endl;
	// else 
	// 	std::cout << "same" << std::endl;


	//std::cout << "capacity = " << vector_long.capacity() << std::endl;

	//std::cout << "test here" ;
	 //vector_long.reserve(15);

	// std::cout << "capacity = " << vector_long.capacity() << std::endl;

	//std::cout << vector_int.front() << std::endl;

	//std::cout << "Max size =" << vector_int.max_size() << std::endl;

//	ft::vector<int>::iterator lol;

	std::cout << std::endl << "attention: pakompri vector_iterator.hpp x2" << std::endl;

}