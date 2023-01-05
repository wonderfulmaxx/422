
# ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP





namespace ft
{
    
	class random_access_iterator_tag { };

    template <typename T>
    class random_access_iterator : ft::iterator<ft::random_access_iterator_tag, T>
	{
        public:
			random_access_iterator(void):{}

	};
}


#endif