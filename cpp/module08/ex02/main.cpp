#include "MutantStack.hpp"

int main()
{
{
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl;
mstack.pop();
std::cout << mstack.size() << std::endl;
mstack.push(3);
mstack.push(5);
mstack.push(737);
//[...]
mstack.push(0);
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
++it;
--it;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
std::stack<int> s(mstack);
}
{
std::cout << "std::list" << std::endl << std::endl;
		std::list< int >	stack;

		std::cout << "List push 10" << std::endl;
		stack.push_back(10);
		std::cout << "List push 7" << std::endl;
		stack.push_back(7);

		std::cout << "List first: " << *stack.begin() << std::endl;

		std::cout << "List pop" << std::endl;
		stack.pop_back();

		std::cout << "List size: " << stack.size() << std::endl;

		std::cout << "List push 3, 5, 737, 0" << std::endl;
		stack.push_back(3);
		stack.push_back(5);
		stack.push_back(737);
		stack.push_back(0);

		std::list<int>::iterator	it = stack.begin();
		std::list<int>::iterator	ite = stack.end();

		std::cout << std::endl;
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << std::endl;

}


return 0;
}