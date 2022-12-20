#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>
# include <list>

template <typename T>
class MutantStack : public std::stack<T>
{

	public:

		MutantStack(){};
		MutantStack( MutantStack const & src ){ *this = src;}
		~MutantStack(){};

		typedef typename std::deque<T>::iterator iterator;

		iterator begin()
		{
			return this->c.begin();
		}
		iterator end()
		{
			return this->c.end();
		}

	private:


};

#endif /* ***************************************************** MUTANTSTACK_H */