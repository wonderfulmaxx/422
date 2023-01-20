# ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterators_traits.hpp"
#include <iostream>

namespace ft
{
        template<class T>
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

        private:
            pointer    ptr;

        public:

            reverse_iterator(void) : ptr(NULL) {}
            reverse_iterator(const pointer ptr) : ptr(ptr) {}
            reverse_iterator(const reverse_iterator& other) : ptr(other.ptr) {}

            operator                            reverse_iterator<const T> () const                { return (reverse_iterator<const T>(this->ptr)); }
            virtual                             ~reverse_iterator()                               {}
            const_pointer                       base() const                                                    { return ptr; }

            reference                           operator*()                                                     { return (*ptr); }
            bool                                operator!=(const reverse_iterator &other) const   { return (ptr != other.ptr); }
            reverse_iterator      operator+(difference_type a) const                              { return (ptr - a); }
            reverse_iterator&     operator++()                                                    { ptr--; return (*this); }
            reverse_iterator      operator++(int)                                                 { ptr--; return (reverse_iterator(ptr + 1)); }
            reverse_iterator&     operator+=(difference_type a)                                   { ptr = ptr - a; return (*this); }
            reverse_iterator      operator-(difference_type a) const                              { return (ptr + a); }
            int                                 operator-(reverse_iterator other) const           { return ((ptr - (other.ptr)) * -1); }
            reverse_iterator&     operator--()                                                    { ptr++; return (*this); }
            reverse_iterator      operator--(int)                                                 { ptr++; return (reverse_iterator(ptr - 1)); }
            reverse_iterator&     operator-=(difference_type a)                                   { ptr = ptr + a; return (*this); }
            bool                                operator<(const const_iterator& other) const                    { return (ptr > other.base()); }
            bool                                operator<=(const const_iterator& other) const                   { return (ptr >= other.base()); }
            bool                                operator==(const reverse_iterator& other) const   { return (ptr == other.ptr); }
            bool                                operator>(const const_iterator& other) const                    { return (ptr < other.base()); }
            bool                                operator>=(const const_iterator& other) const                   { return (ptr <= other.base()); }
            reference                           operator[](difference_type a) const                             { return (*(ptr - a)); }
            pointer                             operator->()                                                    { return ptr; }
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


}



#endif