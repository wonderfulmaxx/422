#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

#include "iterators_traits.hpp"

#include <iostream>

namespace ft
{
	template<typename T>
	class vector_iterator
	{
		public:
			typedef std::random_access_iterator_tag				iterator_category;
			typedef T											value_type;
			typedef std::ptrdiff_t								difference_type;
			typedef value_type*									pointer;
			typedef value_type&									reference;

			vector_iterator(void) : _ptr(nullptr) {}
			vector_iterator(pointer ptr) : _ptr(ptr) {}
			vector_iterator(const vector_iterator &other) : _ptr(other._ptr) {}

			virtual ~vector_iterator() {}

			vector_iterator operator+(difference_type j) const { return (this->_ptr + j); }
			vector_iterator &operator++() { this->_ptr = this->_ptr + 1; return (*this); }
			vector_iterator	operator+=(difference_type j) { this->_ptr = this->_ptr + j; return (this->_ptr); }
			vector_iterator operator++(int) { vector_iterator	it((*this)); this->_ptr = this->_ptr + 1; return (it); }

			vector_iterator operator-(difference_type j) const { return (this->_ptr - j); }
			difference_type	operator-(vector_iterator other) const { return (this->_ptr - other._ptr); }
			vector_iterator	operator-=(difference_type j) { this->_ptr = this->_ptr - j; return (this->_ptr); }
			vector_iterator &operator--() { this->_ptr = this->_ptr - 1; return (*this); }
			vector_iterator	operator--(int) { vector_iterator	it((*this)); this->_ptr = this->_ptr - 1; return (it); }

			bool	operator!=(const vector_iterator &other) const { return (this->_ptr != other._ptr); }
			bool 	operator==(const vector_iterator &other) const { return (this->_ptr == other._ptr); }

			reference	operator[](difference_type j) const { return (*(this->_ptr + j)); }
			reference	operator*() { return (*this->_ptr); }
			pointer		operator ->() { return (this->_ptr); };

			operator vector_iterator<const T> () const { return (vector_iterator<const T>(this->_ptr)); }

			pointer base() const { return (this->_ptr); }

		private:
			pointer	_ptr;

	};

	template<typename T>
	ft::vector_iterator<T> operator+(typename ft::vector_iterator<T>::difference_type n, typename ft::vector_iterator<T>& it) { return (&(*it) + n); }

	template <typename T>
	typename ft::vector_iterator<T>::difference_type
	operator<(const ft::vector_iterator<T> lhs,
			  const ft::vector_iterator<T> rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <typename Iterator1, typename Iterator2>
	typename ft::vector_iterator<Iterator1>::difference_type
	operator<(const ft::vector_iterator<Iterator1> lhs,
			  const ft::vector_iterator<Iterator2> rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <typename T>
	typename ft::vector_iterator<T>::difference_type
	operator<=(const ft::vector_iterator<T> lhs,
			   const ft::vector_iterator<T> rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <typename Iterator1, typename Iterator2>
	typename ft::vector_iterator<Iterator1>::difference_type
	operator<=(const ft::vector_iterator<Iterator1> lhs,
			   const ft::vector_iterator<Iterator2> rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <typename T>
	typename ft::vector_iterator<T>::difference_type
	operator>(const ft::vector_iterator<T> lhs,
			  const ft::vector_iterator<T> rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <typename Iterator1, typename Iterator2>
	typename ft::vector_iterator<Iterator1>::difference_type
	operator>(const ft::vector_iterator<Iterator1> lhs,
			  const ft::vector_iterator<Iterator2> rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <typename T>
	typename ft::vector_iterator<T>::difference_type
	operator>=(const ft::vector_iterator<T> lhs,
			   const ft::vector_iterator<T> rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template <typename Iterator1, typename Iterator2>
	typename ft::vector_iterator<Iterator1>::difference_type
	operator>=(const ft::vector_iterator<Iterator1> lhs,
			   const ft::vector_iterator<Iterator2> rhs)
	{
		return (lhs.base() >= rhs.base());
	}
}

#endif