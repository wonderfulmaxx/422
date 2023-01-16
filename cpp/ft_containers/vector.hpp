#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include "vector_iterator.hpp"
#include "reverse_iterator.hpp"
#include "type_traits.hpp"

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
			typedef typename allocator_type::difference_type difference_type;

/////////////////////////////////////////////Member functions////////////////////////////////////

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

			template<class InputIt>
			vector(InputIt first, InputIt last, const Allocator& alloc = Allocator(),
			typename std::enable_if<!std::is_integral<InputIt>::value, InputIt>::type* = nullptr)  // here std a laplace de ft
			:
			_alloc(alloc),
			_start(nullptr),
			_end(nullptr),
			_end_capacity(nullptr)
			{
				for (; first != last; first++)
					this->push_back(*first);
			}

		 	vector (const vector& x): _start(nullptr), _end(nullptr)
			{
				pointer	first_x		=	x._start;
				pointer	end_x		=	x._end;

				difference_type	diff	=	 x.size();

				this->_start		=	this->_alloc.allocate(diff);
				this->_end			=	this->_start + diff;
				this->_end_capacity		=	this->_end;

				pointer	head		=	this->_start;
				while (head && head != (this->_end + 1) && first_x && first_x != end_x)
				{
					this->_allocator.construct(head, *first_x);
					first_x++;
					head++;
				}
			}
			
			vector& operator=( const vector& other )
			{
				this -> clear();
				for (const_iterator index = other.begin(); index != other.end(); index ++)
					this -> push_back(*index);
				return(*this);
			}

		~vector()
		{
			this -> clear();
			if (this -> _start)
				_alloc.deallocate(_start, capacity());
		}


		void assign( size_type count, const T& value )
		{
			if (count == 0)
					return ;

				this->clear();

				if (this->capacity() > 0)
					this->_alloc.deallocate(this->_start, this->capacity());

				this->_start = this->_alloc.allocate(count);
				pointer head = this->_start;
				for (size_t i = 0; i < count; i++)
				{
					this->_alloc.construct(head, value);
					head++;
				}
				this->_end = this->_start + count;
				this->_end_capacity = this->_end;
		}

		template< class InputIt >
		void assign( InputIt first, InputIt last,
		typename std::enable_if<!std::is_integral<InputIt>::value, InputIt>::type* = nullptr) // here std
		{
			this->clear();
			while (first != last)
			{
				this->push_back(*first);
				first++;
			}
		}

		allocator_type get_allocator() const
		{
			return(this->_alloc);
		}

/////////////////////////////////////////////Element access \/ ///////////////////////////////////


			reference at( size_type pos )
			{
				if (pos >= this->size())
					throw std::out_of_range("Invalid position.");

				pointer	head	=	this->_start;
				return (*(head + pos));
			}

			const_reference at( size_type pos ) const
			{
				if (pos >= this->size())
					throw std::out_of_range("Invalid position.");

				pointer	head	=	this->_start;
				return (*(head + pos));
			}

			reference operator[](size_type n)
			{
				return(*(_start + n));
			}

			const_reference operator[] (size_type n) const
			{
				return(*(_start + n));
			}

			reference front()
			{
				return((*this)[0]);
			}

			const_reference front() const
			{
				return((*this)[0]);
			}

			reference back()
			{
				return (*(this->_end - 1));
			}

			const_reference back() const
			{
				return (*(this->_end - 1));
			}
			
			T* data()
			{
				pointer p = this->_start;
				return(p);
			}

			const T* data() const
			{
				pointer	p	=	this->_start;
				return (p);
			}

/////////////////////////////////////////////Iterators////////////////////////////////////


			typedef ft::vector_iterator<T>               iterator;
			typedef ft::vector_iterator<const T>		const_iterator;

			typedef ft::reverse_iterator<T>				reverse_iterator;
			typedef ft::reverse_iterator<const T>		const_reverse_iterator;

			iterator begin()
			{
				return(iterator(this->_start));
			}
			
			const_iterator begin() const
			{
				return(const_iterator(this->_start));
			}

			iterator end()
			{
				if (this -> size() > 0)
					return(this->_end);
				else 
					return(this->_start);
			}
			
			const_iterator end() const
			{
				if (this -> size() > 0)
					return(this->_end);
				else 
					return(this->_start);
			}
			
			reverse_iterator rbegin()
			{
				if (this -> size() > 1)
					return(this->_end - 1);
				else 
					return(this->_start);
			}

			const_reverse_iterator rbegin() const
			{
				if (this -> size() > 1)
					return(this->_end - 1);
				else 
					return(this->_start);
			}
			reverse_iterator rend()
			{
				return(reverse_iterator(this->_start - 1));
			}
			const_reverse_iterator rend() const
			{
				return(const_reverse_iterator(this->_start - 1));
			}

/////////////////////////////////////////////Capacity////////////////////////////////////
			bool empty() const
			{
				if (this->_start == this -> _end)
					return (true);
				else
					return (false); 
			}
			
			size_type size() const
			{
				return(std::distance(this->_start, this->_end));
			}

			size_type max_size() const
			{
				return(allocator_type().max_size());
			}

			void reserve( size_type new_cap )
			{
				if (new_cap > this->max_size())
					throw(std::length_error("New reserved capacity is too big"));
				if (new_cap > this->capacity())
				{
						pointer prev_start = this->_start;
						pointer prev_start_const = this->_start;
						pointer prev_end = this->_end;
						
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
			}

			size_type capacity() const
			{
				return(this->_end_capacity - this->_start);
			}

/////////////////////////////////////////////Modifiers////////////////////////////////////
			void clear()
			{
				while(this->_end != this->_start)
					pop_back();
			}

			iterator insert( iterator pos, const T& value )
			{
				if (size() == 0 && pos == begin())
				{
					push_back(value);
					return(this->_start + 1);
				}

				int index = pos - this -> begin();
				int r_counter = this -> size();

				push_back(*(this->_end - 1));

				while (r_counter > index)
				{
					*(this->_start+r_counter ) = *(this->_start + r_counter - 1);
					r_counter --;
				}

				*(this->_start + index ) = value;

				return (this->_start + index );

			}

			void insert (const_iterator pos, size_type n, const value_type& value)
			{
				const vector::const_iterator begin = this ->begin();

				int index = pos - begin;
				size_type counter = 0;
				int r_counter = this -> size();

				while (counter < n)
				{
					push_back(*(this->_end - n));
					counter ++;
				}

				while (r_counter > index)
				{
					*(this->_start+r_counter + n) = *(this->_start + r_counter - 1);
					r_counter --;
				}
				counter = 0;

				while (counter < n)
				{
					*(this->_start + index ) = value;
					index ++;
					counter ++;
				}
			}

			iterator erase( iterator position )
			{
				if (this->empty())
					return (this->begin());

				difference_type index = (position - this->_start);

				pointer pos = (this->_start + index);

				iterator ret(pos);

				this->_alloc.destroy(pos);
				this->_alloc.construct(pos, *(pos + 1));

				for (; pos != (this->_end - 1); pos++)
					*pos = *(pos + 1);
				this->_alloc.destroy(pos);

				this->_end = this->_end - 1;
				return (ret);
				
				// if (this -> empty())
				// 	return (this -> begin());

				// value_type index = (pos - this->_start);

				// pointer position = (this->_start + index);

				// iterator ret = position;

				// _alloc.destroy(position);
				// _alloc.construct(position,*(position+1));

				// for (; position != (this->_end - 1); position ++)
				// 	*position = *(position + 1);
				
				// pop_back();

				// return(ret);


			}

			iterator erase( iterator first, iterator last )
			{
				iterator old (first);

				while (first != last)
				{
					old = this -> erase(old);
					first ++;
				}

				return(old);
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
				this->_end--;
			}

			void resize (size_type n, value_type val = value_type())
			{
				if (n > this->max_size())
					throw(std::length_error("New reserved capacity is too big"));

				while (this->size()  < n)
					push_back(val);
				while (this->size() > n)
					pop_back();

			}

			void swap( vector& other )
			{
				vector	copy_this(*this);

				(*this)	=	other;
				other = copy_this;
			}

/////////////////////////////////////////////Non-member functions////////////////////////////////////	
	// template< class T, class Alloc >
	// bool operator==( const std::vector<T,Alloc>& lhs,
    //              const std::vector<T,Alloc>& rhs )
	// 		{

	// 		}


			private:



			allocator_type _alloc;
			pointer _start;
			pointer _end;
			pointer _end_capacity;


	};

	template <class T, class Alloc>
	bool operator==(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
	{
		typename ft::vector< T >::const_iterator	left	=	lhs.begin();
		typename ft::vector< T >::const_iterator	right	=	rhs.begin();

		if (lhs.size() != rhs.size())
			return (false);

		while (left != lhs.end() && right != rhs.end())
		{
			if ((*left) != (*right))
				return (false);
			right++;
			left++;
		}
		return (true);
	}

	
	template <class T, class Alloc>
	bool operator!=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
	{
		return (!(lhs == rhs));
	}

	
	template <class T, class Alloc>
	bool operator<(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); 
	}

	
	template <class T, class Alloc>
	bool operator<=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
	{
		return ((lhs < rhs) || (lhs == rhs));
	}

	
	template <class T, class Alloc>
	bool operator>(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
	{
		return (rhs < lhs);
	}

	
	template <class T, class Alloc>
	bool operator>=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
	{
		return (!(lhs < rhs));
	}
};


#endif