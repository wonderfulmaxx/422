#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include "vector_iterator.hpp"

namespace ft
{
	template <typename T, typename Allocator = std::allocator<T> >
	class vector
	{
		public:

			typedef Allocator allocator_type;
			typedef typename allocator_type::pointer pointer;
			typedef T value_type;
			typedef size_t size_type;
			typedef typename allocator_type::reference reference;

			explicit vector (const allocator_type& alloc = allocator_type())
			:
				_alloc(alloc),
				_start(nullptr),
				_end(nullptr),
				_end_capacity(nullptr)
			{}

			explicit vector (size_type n, const T& val = T(),
				 const allocator_type& alloc = allocator_type())
			:
				_alloc(alloc),
				_start(nullptr),
				_end(nullptr),
				_end_capacity(nullptr)
			{
				_start = _alloc.allocate( n );
				_end_capacity = _start + n;
				_end = _start;
				while (n--)
				{
					_alloc.construct(_end, val);
					_end++;
				}
			}

			reference operator[](size_type n)
			{
				return(*(_start + n));
			}

			reference at (size_type pos)
			{
				range_check(pos);
				return((*this)[pos]);
			}

			// const_reference at( size_type pos ) const
			// {
			// 	return()
			// }

			typedef typename ft::vectorIterator<T> iterator; 

			private:

			void range_check(size_type n)
			{
				if (n > this->size())
					throw (std::out_of_range("you searched for a too high index that is not in the vector"));
			}

			size_type size()
			{
				return(std::distance(this->_start, this->_end));
			}

			allocator_type _alloc;
			pointer _start;
			pointer _end;
			pointer _end_capacity;


	};
};


#endif