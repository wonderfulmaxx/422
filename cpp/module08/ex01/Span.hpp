#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <list>

class Span
{

	public:

		Span();
		Span(unsigned int _max);
		Span( Span const & src );
		~Span();

		void	addNumber(int number);
		int		shortestSpan();
		int		longestSpan();
		void	addNumberRange(std::list<int>::iterator it, std::list<int>::iterator ite);
		Span &		operator=( Span const & rhs );

		class TooMany : public std::exception
		{
			const char *what() const throw()
			{
				return ("Too many numbers in span\n");
			}
		};
		class DistanceNotFound : public std::exception
		{
			const char *what() const throw()
			{
				return ("Distance not found, maybe too few numbers in span\n");
			}
		};

	private:

		unsigned int max;
		std::list<unsigned int> span;
};

// std::ostream &			operator<<( std::ostream & o, Span const & i );

#endif /* ************************************************************ SPAN_H */