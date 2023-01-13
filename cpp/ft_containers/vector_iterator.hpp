
# ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP





namespace ft
{
    template <typename T>
	class vector_iterator 
	{
		typedef T				value_type;
		typedef value_type*		pointer;
		typedef std::ptrdiff_t  difference_type;

        public:
			vector_iterator(void): ptr(nullptr)
			{}

			vector_iterator(pointer _ptr): ptr(_ptr)
			{}

			operator vector_iterator<const T> () const  
			{
				return (vector_iterator<const T>(this->ptr));
			}

			bool operator==(const vector_iterator &other) const
			{
				return (this->ptr == other.ptr);
			}

			bool operator!=(const vector_iterator lhs)
			{
				if (this->ptr == lhs.ptr)
					return (false);
				else
					return (true);
			}

			difference_type operator-(vector_iterator other) const
			{
				return (this->ptr - other.ptr);
			}

			difference_type operator+(vector_iterator other) const
			{
				return (this->ptr + other.ptr);
			}

			vector_iterator &operator++()
			{
				this->ptr = this->ptr + 1;
				return (*this);
			}

			vector_iterator operator++(int) // pakompri
			{
				vector_iterator it((*this));
				this->ptr = this->ptr + 1;
				return (it);
			}

			vector_iterator operator+=(difference_type j)
			{
				this->ptr = this->ptr + j;
				return (this->ptr);
			}

			vector_iterator &operator--()
			{
				this->ptr = this->ptr - 1;
				return (*this);
			}

			vector_iterator operator--(int)
			{
				vector_iterator it((*this));
				this->ptr = this->ptr - 1;
				return (it);
			}

			value_type operator*()
			{
				return (*this->ptr);
			}

			value_type operator*() const
			{
				return (*this->ptr);
			}

		private:

			pointer ptr;
	};
}




#endif