#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include "vector_iterator.hpp"
//#include <cstddef>

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
			typedef typename allocator_type::reference const_reference;

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

			// vector & operator = (const vector &rhs)
			// 	:
			// 	_alloc(alloc),
			// 	_start(rhs._start),
			// 	_end(nullptr),
			// 	_end_capacity(nullptr)
			// {
				
			// }


			reference operator[](size_type n)
			{
				return(*(_start + n));
			}

			const_reference operator[] (size_type n) const
			{
				return(*(_start + n));
			}

			reference at (size_type pos)
			{
				range_check(pos);
				return((*this)[pos]);
			}

			const_reference at( size_type pos ) const
			{
				range_check(pos);
				return((*this)[pos]);
			}

			reference front()
			{
				return((*this)[0]);
			}

			const_reference front() const
			{
				return((*this)[0]);
			}


			size_type capacity() const
			{
				return(this->_end_capacity - this->_start);
			}

			void reserve( size_type new_cap )
			{
				if (new_cap > this->capacity())
					if (new_cap <= this->max_size())
						{
							pointer prev_start = this->_start;
							pointer prev_start_const = this->_start;
							pointer prev_end = this->_end;
							

							size_type prev_size = this->size();
							size_type prev_capacity = this->capacity();

							this->_start =_alloc.allocate(new_cap);
							this->_end = this->_start;
							this->_end_capacity = new_cap + this->_start;

							

							while (prev_start != prev_end)
							{
								_alloc.construct(this->_end,*prev_start);
								prev_start ++;
								this->_end ++;
							}
							_alloc.deallocate(prev_start_const, prev_capacity);
						}
					else
					{
						throw(std::length_error("New reserved capacity is too big"));
					}
			}

			size_type size() const
			{
				return(std::distance(this->_start, this->_end));
			}

			size_type max_size() const
			{
				return(allocator_type().max_size());
			}

			void push_back( const T& value )
			{
				if (this->_end == _end_capacity)
				{
					if (this ->size() == 0)
						reserve (1);
					else
						reserve (this->capacity() * 2);
				}
				_alloc.construct(this->_end,value);
				this->_end++;
			}

			void pop_back()
			{
				_alloc.destroy(this->_end - 1);
				_end--;
			}

			void resize (size_type n, value_type val = value_type())
			{
				int counter = 0;

				if (n > this->max_size())
					throw(std::length_error("New reserved capacity is too big"));

				while (n - counter > this->size())
				{
					push_back(val);
					counter ++;
				}
				counter = 0;
				while (n + counter < this->size())
				{
					pop_back();
					counter ++;
				}

			}

			typedef random_access_iterator<T>               iterator;

			iterator begin()
			{
				return(_start);
			}

			iterator end()
			{
				return(this->_end);
			}


			private:

			void range_check(size_type const n) const
			{
				if (n > this->size())
					throw (std::out_of_range("you searched for a too high index that is not in the vector"));
			}


			allocator_type _alloc;
			pointer _start;
			pointer _end;
			pointer _end_capacity;


	};
};


#endif