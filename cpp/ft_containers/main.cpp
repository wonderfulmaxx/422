#include "vector.hpp"


#include <vector>

template <typename T>
void PRINT_LINE (std::string txt, T var)
{
	std::cout << txt << var << std::endl;
}

int main()
{

	//std::string b_string[] = {"Jadore" , "Dior", "et ta soeur"};
	int	b_int[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	size_t b_size = sizeof(b_int) / sizeof(b_int[0]);

	// std::vector<int> std_v;
	// ft::vector<int> v;

	// int counter = 0;
	// while (counter < 10)
	// {
	// 	std_v.push_back(666);
	// 	v.push_back(666);
	// 	counter ++;
	// }


	// 	// std::vector<std::string>::iterator std_it = std_v.insert(std_v.end(),b_string[1]);
    //     // ft::vector<std::string>::iterator it = v.insert(v.end(), b_string[1]);

    //     // PRINT_LINE("It:", *it);
	// 	// PRINT_LINE("std_it:",*std_it);
    //     // //PRINT_LINE(v, 0);

	// 	std::vector<int>::iterator std_it = std_v.begin();
	// 	ft::vector<int>::iterator it = v.begin();

        // //v.insert(v.begin() + 5, 9, -1);

		// std_v.insert(std_v.begin() + 5, 9, -1);
		// v.insert(v.begin() + 5,9,-1);

		// for (std_it = std_v.begin();std_it != std_v.end();std_it++)
		// 	std::cout << *std_it << " ";
		// std::cout<<std::endl;
		// for (it = v.begin();it != v.end();it++)
		// 	std::cout << *it << " ";
		// std::cout<<std::endl;
		
		ft::vector<int> v(b_int, b_int + b_size);
		std::vector<int> vs(b_int, b_int + b_size);

        ft::vector<int>::reverse_iterator it1 = v.rbegin();
        ft::vector<int>::reverse_iterator it2 = it1;
		std::vector<int>::reverse_iterator it1s = vs.rbegin();
        std::vector<int>::reverse_iterator it2s = it1s;

        PRINT_LINE("It1:", *it1);
        PRINT_LINE("It2:", *it2);
		PRINT_LINE("It1s:", *it1s);
        PRINT_LINE("It2s:", *it2s);

       // CHECK_AND_PRINT_ALL(v);

        // v.insert(v.begin() + 5, 9, -1);

        // //CHECK_AND_PRINT_ALL(v);

        // ft::vector<int>::iterator it2 = v.insert(v.begin(), 64);

        // PRINT_LINE("It:", *it2);
        // // CHECK_AND_PRINT_ALL(v);

        // for (int i = 0; i < 23; ++i) {
        //     it2 = v.insert(v.begin() + i + 2, i);
        //     PRINT_LINE("It:", *it2);
        //     // CHECK_AND_PRINT_ALL(v);
        // }




	ft::vector<int> vector_int;

	std::vector<int> std_vector;

	//ft::vector<int> vector_long(4,2);

	vector_int.push_back(8);
	vector_int.push_back(666); 

	std_vector.push_back(8);
	std_vector.push_back(666); 




	
	//vector_int.pop_back();


	// vector_int.push_back(777);

	// vector_int.push_back(888);

	// std::cout << vector_int.at(2);

	// ft::vector<int> vector_cpy(vector_int);

	//ft::vector<int>::iterator target = vector_int.begin();

	//vector_int.resize(7);

	ft::vector<int>::reverse_iterator index = vector_int.rbegin();
	//index ++ ;

	std::vector<int>::reverse_iterator std_index  = std_vector.rbegin();
	//std_index ++;

	std::cout << "-"<<*index <<"-"<< std::endl;
	//std::cout << *(42 + std_index  ) << std::endl;
	std::cout << "-"<<*std_index<<"-" <<std::endl;

	// ft::vector<int>::iterator index2 = vector_int.end();


	// ft::vector<int> vector_cpy(index,index2);

	// vector_cpy.assign(1,2);

	//ft::vector<int>::iterator zizi =  vector_int.insert(index,0,42);

	//vector_int.erase(index, vector_int.rend());

	// std::cout << *zizi << std::endl;
	// zizi ++;
	// zizi ++;
	// std::cout << *zizi << std::endl;
	
	//std::cout << "size = " << vector_int.size() << std::endl;

	// for (index = vector_int.begin();index != vector_int.end(); index ++)
	// 	std::cout << '-' << *index << std::endl;

	// std::cout << "size = " << vector_int.size() << std::endl;

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

	std::cout << std::endl << "attention: here std * 3" << std::endl;

}