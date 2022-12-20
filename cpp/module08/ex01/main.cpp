#include "Span.hpp"

// int main()
// {
// 	Span a(2);

// 	try
// 	{
// 		a.addNumber(100);
// 		a.addNumber(11);
// 		std::cout << a.shortestSpan();
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what();
// 	}
	
	
// }

// int main()
// {
// Span sp = Span(5);
// sp.addNumber(6);
// sp.addNumber(3);
// sp.addNumber(17);
// sp.addNumber(9);
// sp.addNumber(11);
// std::cout << sp.shortestSpan() << std::endl;
// std::cout << sp.longestSpan() << std::endl;
// return 0;
// }

int main()
{
	int test_size = 10000;
    Span lst(test_size);

	std::list<int> mylst;

	mylst.push_back(6);
	mylst.push_back(3);
	mylst.push_back(17);
	mylst.push_back(9);
	mylst.push_back(11);

    try
    {
    	lst.addNumberRange(mylst.begin(), mylst.end());	
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << lst.longestSpan() << std::endl;    
    std::cout << lst.shortestSpan()<< std::endl;

}