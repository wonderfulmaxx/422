#ifndef REVERSE_VECTOR_ITERATOR
#define REVERSE_VECTOR_ITERATOR

#include "iterators_traits.hpp"
#include <iostream>

namespace ft
{
	template <typename Iter>
	class reverse_iterator
	{
	public:
		typedef Iter iterator_type;
		typedef typename ft::iterator_traits<Iter>::iterator_category iterator_category;
		typedef typename ft::iterator_traits<Iter>::value_type value_type;
		typedef typename ft::iterator_traits<Iter>::difference_type difference_type;
		typedef typename ft::iterator_traits<Iter>::pointer pointer;
		typedef typename ft::iterator_traits<Iter>::reference reference;

		reverse_iterator() : _ite(nullptr){};
		explicit reverse_iterator(iterator_type x) : _ite(x){};

		template <class U>
		reverse_iterator(const reverse_iterator<U> &other) : _ite(other.base()){};

		template <class U>
		reverse_iterator &operator=(const reverse_iterator<U> &other) { this->_ite = other.base(); return (*this); }

		reference operator*() const { iterator_type tmp = this->_ite; return (*(--tmp)); }

		pointer operator->() const { return (&(operator*())); }

		reverse_iterator &operator++() { --this->_ite; return (*this); }

		reverse_iterator &operator--() { ++this->_ite; return (*this); }

		reverse_iterator operator++(int) { reverse_iterator tmp = *this; operator++(); return (tmp); }

		reverse_iterator operator--(int) { reverse_iterator tmp = *this; operator--(); return (tmp); }

		reverse_iterator operator+(difference_type n) const { return (reverse_iterator(this->_ite - n)); }

		reverse_iterator operator-(difference_type n) const { return (reverse_iterator(this->_ite + n)); }

		reverse_iterator &operator+=(difference_type n) { this->_ite = this->_ite - n; return (*this); }

		reverse_iterator &operator-=(difference_type n) { this->_ite = this->_ite + n; return (*this); }

		reference operator[](difference_type n) const { return (this->base()[-n-1]); }

		iterator_type base() const { return (this->_ite); }

		private:
			iterator_type _ite;
	};

	template <class Iterator1, class Iterator2>
	bool operator==(const ft::reverse_iterator<Iterator1> &lhs,
					const ft::reverse_iterator<Iterator2> &rhs)
	{ return (lhs.base() == rhs.base()); }

	template <typename Itertor>
	bool operator==(const ft::reverse_iterator<Itertor> lhs, const ft::reverse_iterator<Itertor> rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <class Iterator1, class Iterator2>
	bool operator!=(const ft::reverse_iterator<Iterator1> &lhs, const ft::reverse_iterator<Iterator2> &rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <typename Itertor>
	bool operator!=(const ft::reverse_iterator<Itertor> lhs, const ft::reverse_iterator<Itertor> rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <class Iterator1, class Iterator2>
	bool operator<(const ft::reverse_iterator<Iterator1> &lhs, const ft::reverse_iterator<Iterator2> &rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <typename Itertor>
	bool operator<(const ft::reverse_iterator<Itertor> & lhs, const ft::reverse_iterator<Itertor> & rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <class Iterator1, class Iterator2>
	bool operator<=(const ft::reverse_iterator<Iterator1> &lhs, const ft::reverse_iterator<Iterator2> &rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template <typename Itertor>
	bool operator<=(const ft::reverse_iterator<Itertor> lhs, const ft::reverse_iterator<Itertor> rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template <class Iterator1, class Iterator2>
	bool operator>(const ft::reverse_iterator<Iterator1> &lhs, const ft::reverse_iterator<Iterator2> &rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <typename Itertor>
	bool operator>(const ft::reverse_iterator<Itertor> lhs, const ft::reverse_iterator<Itertor> rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <class Iterator1, class Iterator2>
	bool operator>=(const ft::reverse_iterator<Iterator1> &lhs, const ft::reverse_iterator<Iterator2> &rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <typename Itertor>
	bool operator>=(const ft::reverse_iterator<Itertor> lhs, const ft::reverse_iterator<Itertor> rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <class Iter>
	ft::reverse_iterator<Iter>
	operator+(typename ft::reverse_iterator<Iter>::difference_type n,
			  const ft::reverse_iterator<Iter> &it)

	{
		return (reverse_iterator<Iter>(it.base() - n));
	}

	template <class Iterator1, class Iterator2>
	typename ft::reverse_iterator<Iterator1>::difference_type
	operator-(const ft::reverse_iterator<Iterator1> &lhs,
			  const ft::reverse_iterator<Iterator2> &rhs)
	{
		return (rhs.base() - lhs.base());
	}
}

#endif