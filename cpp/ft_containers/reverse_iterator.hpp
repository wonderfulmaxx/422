
# ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP





namespace ft
{
    template <typename T>
	class reverse_iterator 
	{
		typedef T				value_type;
		typedef value_type*		pointer;
		typedef std::ptrdiff_t  difference_type;

        public:
			reverse_iterator(void): ptr(nullptr)
			{}

			reverse_iterator(pointer _ptr): ptr(_ptr)
			{}

			operator reverse_iterator<const T> () const  
			{
				return (reverse_iterator<const T>(this->ptr));
			}

			bool operator==(const reverse_iterator &other) const
			{
				return (this->ptr == other.ptr);
			}

			bool operator!=(const reverse_iterator lhs)
			{
				if (this->ptr == lhs.ptr)
					return (false);
				else
					return (true);
			}

			difference_type operator-(reverse_iterator other) const
			{
				return (this->ptr + other.ptr);
			}

			difference_type operator+(reverse_iterator other) const
			{
				return (this->ptr - other.ptr);
			}

			reverse_iterator &operator++()
			{
				this->ptr = this->ptr - 1;
				return (*this);
			}

			reverse_iterator operator++(int) 
			{
				reverse_iterator it((*this));
				this->ptr = this->ptr - 1;
				return (it);
			}

			reverse_iterator operator+=(difference_type j)
			{
				this->ptr = this->ptr - j;
				return (this->ptr);
			}

			reverse_iterator &operator--()
			{
				this->ptr = this->ptr + 1;
				return (*this);
			}

			reverse_iterator operator--(int)
			{
				reverse_iterator it((*this));
				this->ptr = this->ptr + 1;
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