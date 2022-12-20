#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span()
{
}

Span::Span(unsigned int _max):max(_max)
{
}

Span::Span( const Span & src ):max(src.max),span(src.span)
{

}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &				Span::operator=( Span const & rhs )
{
	if ( this != &rhs )
	{
		this->max = rhs.max;
	}
	return *this;
}

// std::ostream &			operator<<( std::ostream & o, Span const & i )
// {
// 	//o << "Value = " << i.getValue();
// 	return o;
// }


/*
** --------------------------------- METHODS ----------------------------------
*/

void Span::addNumber(int number)
{
	if (this->span.size() < this->max)
	{
		span.push_back(number);
	}
	else
	{
		throw TooMany();
	}
}

int Span::shortestSpan()
{
	if (this->span.size() > 1)
	{
		this->span.sort();
		std::list<unsigned int>::iterator target = this->span.begin();
		std::list<unsigned int>::iterator target_next = ++(this->span.begin());
		
		unsigned int mini = (*target_next - *target);

		while (target_next != this->span.end())
		{
			if (mini > (*target_next - *target))
				mini = (*target_next - *target);
			target ++;
			target_next ++;
		}
		return (mini);
	}
	else 
	{
		throw DistanceNotFound();
	}
}

int						Span::longestSpan()
{
	if (this->span.size() < 2){
		throw DistanceNotFound();
	}
		int min = *std::min_element(this->span.begin(), this->span.end());
		int max = *std::max_element(this->span.begin(), this->span.end());

		return ((max) - (min));
}

void	Span::addNumberRange(std::list<int>::iterator it, std::list<int>::iterator ite)
{
	while ( it != ite )
	{
		this->addNumber(*it);
		it++;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */