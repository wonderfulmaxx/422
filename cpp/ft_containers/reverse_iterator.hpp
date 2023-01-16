
# ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP




namespace ft
{
    template <typename T>
	class reverse_iterator 
	{
		public:

		typedef T				value_type;
		typedef value_type*		pointer;
		typedef value_type&		reference;
		typedef std::ptrdiff_t  difference_type;

		reverse_iterator operator+(difference_type j) const { return (this->ptr - j); }
		reverse_iterator &operator++()
		{
			this->ptr = this->ptr - 1;
			return (*this);
		}
		reverse_iterator operator+=(difference_type j)
		{
			this->ptr = this->ptr - j;
			return (this->ptr);
		}
		reverse_iterator operator++(int)
		{
			reverse_iterator it((*this));
			this->ptr = this->ptr - 1;
			return (it);
		}

		reverse_iterator operator-(difference_type j) const { return (this->ptr + j); }
		difference_type operator-(reverse_iterator other) const { return (this->ptr + other.ptr); }
		reverse_iterator operator-=(difference_type j)
		{
			this->ptr = this->ptr + j;
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

		bool operator != ( reverse_iterator rhs)
		{
			return(this->ptr != rhs.ptr);
		}

		bool operator == ( reverse_iterator rhs)
		{
			return(this->ptr == rhs.ptr);
		}

		reference operator [] (difference_type n)
		{
			return (*(this->ptr - n - 1));
		}

		value_type operator * ()
		{
			return(*(this->ptr - 1));
		}



		private:

			pointer ptr;
	};
}




#endif