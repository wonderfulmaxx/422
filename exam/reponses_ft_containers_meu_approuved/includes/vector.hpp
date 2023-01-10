#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>

// https://learn.microsoft.com/fr-fr/cpp/standard-library/vector-class
// https://en.cppreference.com/w/cpp/container/vector/vector
// https://cplusplus.com/reference/vector/vector/?kw=vector
// https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits

# include <stdexcept>

#include "vector_iterator.hpp"
#include "reverse_iterator.hpp"
#include "type_traits.hpp"

namespace ft
{
	template < class T, class Allocator = std::allocator< T > >
	class vector
	{
		public:

			/**
			 * 	The first template parameter (T)
			 *	Type representing the type of data stored in a vector.
			 */
			typedef T												value_type;

			/**
			 * The second template parameter (Allocator)
			 */
			typedef Allocator										allocator_type;

			/**
			 * Type that provides a reference to an element stored in a vector.
			 * Used in 'at' function.
			 */
			typedef typename allocator_type::reference				reference;

			/**
			 * Type that provides a reference to a const element stored in a vector. 
			 * It is used to read and perform const operations.
			 * 
			 * Can't be used to modify an element value.
			 */
			typedef typename allocator_type::const_reference		const_reference;

			/**
			 * Type that provides a pointer to an element of a vector.
			*/
			typedef typename allocator_type::pointer				pointer;

			/**
			 * Type that provides a pointer to a constant element of a vector.
			*/
			typedef typename allocator_type::const_pointer			const_pointer;

			/// Iterator
			typedef ft::vector_iterator<value_type>					iterator;
			/// Const vector_iterator
			typedef ft::vector_iterator<const value_type>			const_iterator;

			/// reverse_iterator
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			/// const_reverse_iterator
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;

			/**
			 * Type that provides the difference between two iterators
			 * that refer to elements of the same vector.
			 */
			typedef typename allocator_type::difference_type	difference_type;

			/**
			 * Type that counts the number of elements in a vector.
			 */
			typedef typename allocator_type::size_type 			size_type;

			/**
			 * @brief Construct a new vector object
			 * @details Create an empty vecto with the default-constructed allocator.
			 */
			vector() : _start(nullptr), _end(nullptr), _end_capacity(nullptr) {}

			/**
			 * @brief Construct a new vector object
			 * @details Create an empty vector with the given allocator.
			 * @param alloc 
			 */
			explicit vector( const allocator_type & alloc ) : _allocator(alloc), _start(nullptr), _end(nullptr), _end_capacity(nullptr) {}

			template<class InputIt>
			vector(InputIt first, InputIt last, const Allocator& alloc = Allocator(),
			typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = nullptr) : _allocator(alloc), _start(nullptr), _end(nullptr), _end_capacity(nullptr)
			{
				for (; first != last; first++)
					this->push_back(*first);
			}

			/**
			 * @brief Construct a new vector object
			 * @details Constructs the vector with count copies of elements with value.
			 * @param count Space to allocate.
			 * @param value Value to insert.
			 * @param alloc Allocator object.
			 */
			explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator()) : _allocator(alloc), _start(nullptr), _end(nullptr)
			{
				if (count <= 0)
					return ;

				this->_start	= this->_allocator.allocate(count);
				this->_end		= this->_start + count;
				this->_end_capacity	= this->_end;

				pointer	head 	= this->_start;
				while (head && head != (this->_end))
				{
					this->_allocator.construct(head, value);
					head++;
				}
			}

			/**
			 * @brief Construct a new vector object
			 * 
			 * @param x Reference to vector.
			 */
			vector (const vector& x) : _start(nullptr), _end(nullptr)
			{
				pointer	first_x		=	x._start;
				pointer	end_x		=	x._end;

				difference_type	diff	=	 x.size();

				this->_start		=	this->_allocator.allocate(diff);
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

			/**
			 * @brief Destroy the vector object
			 * 
			 */
			~vector() {
				this->clear();
				if (this->_start)
					this->_allocator.deallocate(this->_start, this->capacity());
			};

			/**
			 * @brief Assign the content of the vector x to the vector.
			 * 
			 * @param x 
			 * @return vector& 
			 */
			vector& operator= (const vector& x)
			{
				this->clear();
				for (const_iterator it = x.begin(); it != x.end(); it++)
					this->push_back(*it);
				return (*this);
			}

			/**
			 * @brief Assign values to the vector.
			 * 
			 * @tparam InputIt 
			 * @param first 
			 * @param last 
			 */
			template< class InputIt >
			void assign( InputIt first, InputIt last,
			typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = nullptr)
			{
				this->clear();

				while (first != last)
				{
					this->push_back(*first);
					first++;
				}
			}

			/**
			 * @brief Assign values to the vector.
			 * 
			 * @param count 
			 * @param value 
			 */
			void assign( size_type count, const T& value )
			{
				if (count == 0)
					return ;

				this->clear();

				if (this->capacity() > 0)
					this->_allocator.deallocate(this->_start, this->capacity());

				this->_start = this->_allocator.allocate(count);
				pointer head = this->_start;
				for (size_t i = 0; i < count; i++)
				{
					this->_allocator.construct(head, value);
					head++;
				}
				this->_end = this->_start + count;
				this->_end_capacity = this->_end;
			}

			/**
			 * @brief returns the associated allocator
			 * 
			 * @return allocator_type 
			 */
			allocator_type get_allocator() const
			{
				return (this->_allocator);
			}

			/**
			 * @brief Access specified element with bounds checking 
			 * 
			 * @param pos 
			 * @return reference 
			 */
			reference at( size_type pos )
			{
				if (pos >= this->size())
					throw std::out_of_range("Invalid position.");

				pointer	head	=	this->_start;
				return (*(head + pos));
			}

			/**
			 * @brief Access specified element with bounds checking 
			 * 
			 * @param pos 
			 * @return const_reference 
			 */
			const_reference at( size_type pos ) const
			{
				if (pos >= this->size())
					throw std::out_of_range("Invalid position.");

				pointer	head	=	this->_start;
				return (*(head + pos));
			}

			/**
			 * @brief Access to specified element.
			 * 
			 * @param pos 
			 * @return * reference 
			 */
			reference operator[]( size_type pos )
			{
				pointer	head	=	this->_start;
				return (*(head + pos));
			}

			/**
			 * @brief Access to specified element.
			 * 
			 * @param pos 
			 * @return const_reference 
			 */
			const_reference operator[]( size_type pos ) const
			{
				pointer	head	=	this->_start;
				return (*(head + pos));
			}

			/**
			 * @brief Access the first element 
			 * 
			 * @return reference 
			 */
			reference front()
			{
				return (*this->_start);
			}

			/**
			 * @brief Access the first element 
			 * 
			 * @return const_reference 
			 */
			const_reference front() const
			{
				return (*this->_start);
			}

			/**
			 * @brief Access the last element 
			 * 
			 * @return reference 
			 */
			reference back()
			{
				return (*(this->_end - 1));
			}

			/**
			 * @brief Access the last element 
			 * 
			 * @return const_reference 
			 */
			const_reference back() const
			{
				return (*(this->_end - 1));
			}

			/**
			 * @brief  direct access to the underlying array 
			 * 
			 * @return T* 
			 */
			T* data()
			{
				pointer	p	=	this->_start;
				return (p);
			}

			/**
			 * @brief direct access to the underlying array 
			 * 
			 * @return const T* 
			 */
			const T* data() const
			{
				pointer	p	=	this->_start;
				return (p);
			}

			/**
			 * @brief returns an iterator to the beginning 
			 * 
			 * @return iterator 
			 */
			iterator begin()
			{
				return (this->_start);
			}

			/**
			 * @brief returns an iterator to the beginning 
			 * 
			 * @return const_iterator 
			 */
			const_iterator begin() const
			{
				return (this->_start);
			}

			/**
			 * @brief returns an iterator to the end 
			 * 
			 * @return iterator 
			 */
			iterator end()
			{
				return (this->_end);
			}

			/**
			 * @brief returns an iterator to the end 
			 * 
			 * @return const_iterator 
			 */
			const_iterator end() const
			{
				return (this->_end);
			}
			
			/**
			 * @brief returns a reverse iterator to the beginning 
			 * 
			 * @return reverse_iterator 
			 */
			reverse_iterator rbegin()
			{
				return (reverse_iterator(this->end()));
			}
			
			/**
			 * @brief returns a reverse iterator to the beginning 
			 * 
			 * @return const_reverse_iterator 
			 */
			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(this->end()));
			}

			/**
			 * @brief returns a reverse iterator to the end 
			 * 
			 * @return reverse_iterator 
			 */
			reverse_iterator rend()
			{
				return (reverse_iterator(this->begin()));
			}
			
			/**
			 * @brief returns a reverse iterator to the end 
			 * 
			 * @return const_reverse_iterator 
			 */
			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(this->begin()));
			}

			/**
			 * @brief checks whether the container is empty 
			 * 
			 * @return true 
			 * @return false 
			 */
			bool empty() const
			{
				return (this->_start == this->_end);
			}

			/**
			 * @brief returns the number of elements 
			 * 
			 * @return size_type 
			 */
			size_type size() const
			{
				return (this->_end - this->_start);
			}

			/**
			 * @brief returns the maximum possible number of elements 
			 * 
			 * @return size_type 
			 */
			size_type max_size() const
			{
				return (allocator_type().max_size());
			}

			/**
			 * @brief reserves storage 
			 * 
			 * @param new_cap 
			 */
			void	reserve(size_t new_cap)
			{
				if (new_cap > this->max_size())
					throw std::length_error("The new size is greater than the max_size.");

				if (new_cap <= this->capacity() || new_cap == 0)
					return ;

				difference_type	count	=	0;

				pointer	head			=	this->_start;

				pointer	new_start		=	this->_allocator.allocate(new_cap);
				pointer	ns_ptr			=	new_start;

				for (size_t i = 0; i < this->size(); i++)
				{
					this->_allocator.construct(ns_ptr, (*head));
					this->_allocator.destroy(head);
					ns_ptr++;
					count++;
					head++;
				}

				if (this->capacity() > 0)
					this->_allocator.deallocate(this->_start, this->capacity());

				this->_start			=	new_start;
				this->_end				=	new_start +	count;
				this->_end_capacity		=	new_start + new_cap;
			}

			/**
			 * @brief returns the number of elements that can be held in currently allocated storage 
			 * 
			 * @return size_type 
			 */
			size_type capacity() const
			{
				return (this->_end_capacity - this->_start);
			}

			/**
			 * @brief clears the contents 
			 * 
			 */
			void clear()
			{
				pointer	head		=	this->_start;
				while (head != (this->_end))
				{
					this->_allocator.destroy(head);
					head++;
				}

				this->_end	=	this->_start;
			}

			/**
			 * @brief inserts elements 
			 * 
			 * @tparam InputIt 
			 * @param position 
			 * @param first 
			 * @param last 
			 */
			template <class InputIt>
			void insert (iterator position, InputIt first, InputIt last,
			typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = nullptr)
			{
				while (first != last)
				{
					position = this->insert(position, *first) + 1;
					first++;
				}
			}

			/**
			 * @brief inserts elements 
			 * 
			 * @param position 
			 * @param val 
			 * @return iterator 
			 */
			iterator insert (iterator position, const value_type& val)
			{
				difference_type index = position - this->begin();

				if (this->empty())
					this->reserve(this->size() + 1);

				iterator	it_offset = this->begin() + index;

				vector copy(it_offset, this->end());

				for (size_t i = 0; i < copy.size(); i++)
					this->pop_back();

				this->push_back(val);

				it_offset = copy.begin();
				for (size_t i = 0; i < copy.size(); i++, it_offset++)
					this->push_back(*it_offset);

				return (this->begin() + index);
			}

			/**
			 * @brief inserts elements 
			 * 
			 * @param position 
			 * @param n 
			 * @param val 
			 */
			void insert (iterator position, size_type n, const value_type& val)
			{
				if ((this->size() + n) > this->max_size())
					throw std::length_error("Trying to add more values than the max capacity.");

				for (size_t i = 0; i < n; i++)
					position = this->insert(position, val);
			}

			/**
			 * @brief erases elements 
			 * 
			 * @param position 
			 * @return iterator 
			 */
			iterator erase(iterator position)
			{
				if (this->empty())
					return (this->begin());

				difference_type index = (position - this->_start);

				pointer pos = (this->_start + index);

				iterator ret(pos);

				this->_allocator.destroy(pos);
				this->_allocator.construct(pos, *(pos + 1));

				for (; pos != (this->_end - 1); pos++)
					*pos = *(pos + 1);
				this->_allocator.destroy(pos);

				this->_end = this->_end - 1;
				return (ret);
			}

			/**
			 * @brief erases elements 
			 * 
			 * @param first 
			 * @param last 
			 * @return iterator 
			 */
			iterator erase (iterator first, iterator last)
			{
				iterator	old(first);
				while (first != last)
				{
					old = this->erase(old);
					first++;
				}
				
				return (old);
			}

			/**
			 * @brief adds an element to the end 
			 * 
			 * @param val 
			 */
			void push_back (const value_type& val)
			{
				if ((this->size() + 1) > this->capacity())
					this->reserve(this->size() + 1);

				this->_allocator.construct(this->_end, val);

				this->_end++;
			}
			
			/**
			 * @brief removes the last element 
			 * 
			 */
			void pop_back()
			{
				this->_allocator.destroy(&this->back());
				this->_end--;
			}

			/**
			 * @brief changes the number of elements stored 
			 * 
			 * @param n 
			 * @param val 
			 */
			void resize (size_type n, value_type val = value_type())
			{
				this->reserve(n);

				if (n <= this->size())
				{
					pointer	ptr_save	=	this->_start + n;
					while (ptr_save != this->_end)
						this->_allocator.destroy(ptr_save++);
					this->_end = this->_start + n;
					return ;
				}

				difference_type	diff	=	( n - this->size() );

				pointer	ptr_start	=	this->_start + this->size();
				while (ptr_start != (this->_end + diff ))
					this->_allocator.construct((ptr_start++), val);
				this->_end = this->_end + diff;
			}

			/**
			 * @brief swaps the contents 
			 * 
			 * @param x 
			 */
			void swap (vector& x)
			{
				vector	copy_this(*this);

				(*this)	=	x;
				x = copy_this;
			}

		private:
			allocator_type	_allocator;
			pointer			_start;
			pointer			_end;
			pointer			_end_capacity;
	};

	/**
	 * @brief operator ==
	 * 
	 * @tparam T 
	 * @tparam Alloc 
	 * @param lhs 
	 * @param rhs 
	 * @return true 
	 * @return false 
	 */
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

	/**
	 * @brief operator !=
	 * 
	 * @tparam T 
	 * @tparam Alloc 
	 * @param lhs 
	 * @param rhs 
	 * @return true 
	 * @return false 
	 */
	template <class T, class Alloc>
	bool operator!=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
	{
		return (!(lhs == rhs));
	}

	/**
	 * @brief operator <
	 * 
	 * @tparam T 
	 * @tparam Alloc 
	 * @param lhs 
	 * @param rhs 
	 * @return true 
	 * @return false 
	 */
	template <class T, class Alloc>
	bool operator<(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	/**
	 * @brief operator <=
	 * 
	 * @tparam T 
	 * @tparam Alloc 
	 * @param lhs 
	 * @param rhs 
	 * @return true 
	 * @return false 
	 */
	template <class T, class Alloc>
	bool operator<=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
	{
		return ((lhs < rhs) || (lhs == rhs));
	}

	/**
	 * @brief operator >
	 * 
	 * @tparam T 
	 * @tparam Alloc 
	 * @param lhs 
	 * @param rhs 
	 * @return true 
	 * @return false 
	 */
	template <class T, class Alloc>
	bool operator>(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
	{
		return (rhs < lhs);
	}

	/**
	 * @brief operator >=
	 * 
	 * @tparam T 
	 * @tparam Alloc 
	 * @param lhs 
	 * @param rhs 
	 * @return true 
	 * @return false 
	 */
	template <class T, class Alloc>
	bool operator>=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
	{
		return (!(lhs < rhs));
	}

	/**
	 * @brief specializes the swap algorithm 
	 * 
	 * @tparam T 
	 * @tparam Alloc 
	 * @param lhs 
	 * @param rhs 
	 */
	template <class T, class Alloc>
	void swap(ft::vector<T, Alloc> &lhs, ft::vector<T, Alloc> &rhs)
	{
		lhs.swap(rhs);
	}
}

#endif