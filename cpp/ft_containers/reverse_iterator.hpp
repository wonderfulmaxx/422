
# ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterators_traits.hpp"
#include <iostream>

namespace ft
{
    template <typename T>
	class reverse_iterator 
	{
		public:

		 typedef std::random_access_iterator_tag                     iterator_category;
            typedef T                                                   value_type;
            typedef value_type*                                         pointer;
            typedef value_type const *                                  const_pointer;
            typedef value_type&                                         reference;
            typedef value_type const &                                  const_reference;
            typedef std::ptrdiff_t                                      difference_type;
            typedef reverse_iterator< T >                 iterator;
            typedef reverse_iterator<const T>             const_iterator;

		reverse_iterator() : ptr(nullptr) {}
		reverse_iterator(const pointer _ptr) : ptr(_ptr) {}
		reverse_iterator (const reverse_iterator &other) : ptr(other.ptr) {}

		virtual ~ reverse_iterator() {}

		operator                            reverse_iterator<const T> () const                { return (reverse_iterator<const T>(this->ptr)); }

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
	
		int     operator-(reverse_iterator other) const          
		 { return ((ptr - (other.ptr)) * -1); }

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

		reference operator * ()
		{
			return(*(this->ptr - 1));
		}

		pointer operator -> ()
		{
			return(this->ptr);
		}

		pointer base() const { return (this->ptr); }

		private:

			pointer ptr;
	};

	

	template <class T>
    reverse_iterator<T>   operator+(typename reverse_iterator<T>::difference_type n, const reverse_iterator<T>& it )
    { 
        return (it + n); 
    }

	template <class T>
    reverse_iterator<T>   operator-(typename reverse_iterator<T>::difference_type n, const reverse_iterator<T>& it )
    { 
        return (it - n); 
    }

	template <typename T>
	typename ft::reverse_iterator<T>::difference_type
	operator<(const ft::reverse_iterator<T> lhs,
			  const ft::reverse_iterator<T> rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <typename Iterator1, typename Iterator2>
	typename ft::reverse_iterator<Iterator1>::difference_type
	operator<(const ft::reverse_iterator<Iterator1> lhs,
			  const ft::reverse_iterator<Iterator2> rhs)
	{
		return (lhs.base() < rhs.base());
	}


	template <typename T>
	typename ft::reverse_iterator<T>::difference_type
	operator<=(const ft::reverse_iterator<T> lhs,
			   const ft::reverse_iterator<T> rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <typename Iterator1, typename Iterator2>
	typename ft::reverse_iterator<Iterator1>::difference_type
	operator<=(const ft::reverse_iterator<Iterator1> lhs,
			   const ft::reverse_iterator<Iterator2> rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <typename T>
	typename ft::reverse_iterator<T>::difference_type
	operator>(const ft::reverse_iterator<T> lhs,
			  const ft::reverse_iterator<T> rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <typename Iterator1, typename Iterator2>
	typename ft::reverse_iterator<Iterator1>::difference_type
	operator>(const ft::reverse_iterator<Iterator1> lhs,
			  const ft::reverse_iterator<Iterator2> rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <typename T>
	typename ft::reverse_iterator<T>::difference_type
	operator>=(const ft::reverse_iterator<T> lhs,
			   const ft::reverse_iterator<T> rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template <typename Iterator1, typename Iterator2>
	typename ft::reverse_iterator<Iterator1>::difference_type
	operator>=(const ft::reverse_iterator<Iterator1> lhs,
			   const ft::reverse_iterator<Iterator2> rhs)
	{
		return (lhs.base() >= rhs.base());
	}

}




#endif