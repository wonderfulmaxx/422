#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "map_utils.hpp"
#include "tree.hpp"
#include "map_iterator.hpp"

namespace ft
{

template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Alloc = std::allocator<ft::pair<const Key, T> >
> class map
{
    public:
		 	typedef             Key                                                     key_type;
            typedef             T                                                       mapped_type;
            typedef             ft::pair<const key_type, mapped_type>                   value_type;
            typedef             ft::pair<key_type, mapped_type>                         value_type_2;
            typedef             Compare                                                 key_compare;
            typedef             Alloc                                                   allocator_type;
            typedef typename    Alloc::reference                                        reference;
            typedef typename    Alloc::const_reference                                  const_reference;
            typedef typename    Alloc::pointer                                          pointer;
            typedef typename    Alloc::const_pointer                                    const_pointer;
            typedef             size_t                                                  size_type;
            typedef             ft::Noeud<value_type_2>*                                   node_pointer;
            typedef             ft::iterator<Key, T>                      iterator;
            typedef             ft::iterator<Key, T>                      const_iterator;
            // typedef             ft::riterator<Key, T>                     reverse_iterator;
            // typedef             ft::riterator<Key, T>                     const_reverse_iterator;
            typedef             ptrdiff_t                                               difference_type;


        private:
            allocator_type          _allocator;
            ft::Tree<value_type_2, key_compare>    _tree;
            key_compare             _comp;

        public:

        map() {}
        ~map() {}

        mapped_type &at(const key_type &k)
        {
            node_pointer node_ptr = this->_tree.recherche(k);
            if (node_ptr)
                return node_ptr->donnees.second;
            else
                throw std::out_of_range(" map::at:  key not found");
        }

        ft::pair<iterator, bool> insert(const value_type_2 &value)
        {
            bool ret = this->_tree.inserer(value);
            node_pointer testptr = this->_tree.recherche(value.first);

            ft::pair<iterator, bool> result(testptr, ret);
            return result;
        }

        iterator begin()
        {
           return (_tree.infixe(0));
        }

        iterator end()
        {
            return (_tree.biggest()->next);
        }

        void test(const key_type &lol)
        {
            this->_tree.supprimer(lol);
        }
        


};
}

#endif