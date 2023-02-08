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
            typedef             ft::Noeud<value_type_2>*                                node_pointer;
            typedef             ft::iterator<Key, T>                                    iterator;
            typedef             ft::iterator<Key, T>                                    const_iterator;
            typedef             ft::riterator<Key, T>                                   reverse_iterator;
            typedef             ft::riterator<Key, T>                                   const_reverse_iterator;
            typedef             ptrdiff_t                                               difference_type;


        private:
            allocator_type          _allocator;
            ft::Tree<value_type_2, key_compare>    _tree;
            key_compare             _comp;

        public:

        map() {}

        explicit map(const key_compare& comp, const allocator_type& alloc = allocator_type()) : _allocator(alloc), _comp(comp) {}
        
        template<class InputIt>
        map(InputIt first, InputIt last, const key_compare& comp = key_compare(), const allocator_type alloc = allocator_type()) : _allocator(alloc), _comp(comp)
        {
            this->insert(first, last);
        }
        ~map() {}

        map &operator=(const map &x)
        {
            this->clear();
            this->insert(x.begin(), x.end());
            return (*this);
        }

        void clear ()
        {
            this->_tree.free_all(this->_tree.get_root());
        }

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

        template <class InputIterator>
        void insert (InputIterator first, InputIterator last)
        {
            for (; first != last; first++){
                value_type_2 tmp((*first).first, (*first).second);
                //std::cout << "-insert: " << tmp.first << ", droit = " << tmp.droit<< std::endl;
                this->insert(tmp);
            }
        }

        iterator begin()
        {
          return iterator(this->_tree.smallest(this->_tree.get_root()));
        }

        const_iterator              begin() const                       { return iterator(this->_tree.smallest(this->_tree.get_root()));}
        const_iterator              end() const                         { return iterator(_tree.biggest_inv(_tree.get_root()));} 

        reverse_iterator rbegin()
        {
          return reverse_iterator(_tree.biggest(_tree.get_root()));
        }

        const_reverse_iterator rbegin() const
        {
          return reverse_iterator(_tree.biggest(_tree.get_root()));
        }

        iterator end()
        {
            return iterator(_tree.biggest_inv(_tree.get_root()));
        }

        reverse_iterator rend() 
        {
            return reverse_iterator(this->_tree.smallest_inv(this->_tree.get_root()));
        }

        const_reverse_iterator rend()  const
        {
            return reverse_iterator(this->_tree.smallest_inv(this->_tree.get_root()));
        }

        void affichage_racine()
        {
            _tree.affichage_racine();
        }

        size_t size()
        {
            return(_tree.get_size());
        }
        
        void erase( iterator pos )
        {
           this->_tree.supprimer(pos->first);
        }

        void erase( iterator first, iterator last )
        {
            //  while (first != last){
			// 	    this->erase(first++);
            //     }

            iterator buff_next = first;
            buff_next ++;

            while (buff_next != last)
            {
               // std::cout << "suppression de " << first->second;
               //if (first != this->_tree.smallest_inv(this->_tree.get_root())) 
                this->_tree.supprimer(first->first);
                //std::cout << " fait";
                first = buff_next;
                buff_next ++;
                //std::cout << "   Now buff_next = "<< buff_next->second << std::endl;
            }
          //  std::cout << "prout" << std::endl;
           // std::cout << "buff_next = " << buff_next->second << std::endl;
           // if (!buff_next->is_invisible)
          //  {
              //  buff_next ++;
                //std::cout << "suppression de " << first->second;
               // std::cout << "lolilol" << std::endl;
                //if (last == this->_tree.biggest_inv(this->_tree.get_root()))
                //    std::cout << "is invisible\n";

            //    std::cout << "first = " << first->second << std::endl;
             //    std::cout << "A LIRE A PERTIR D'ICI\n" ;
                this->_tree.supprimer(first->first);
              //  std::cout << "last = " << last->second << std::endl;

                if (last != this->_tree.smallest_inv(this->_tree.get_root()))
                    this->_tree.supprimer(last->first);
            //   std::cout << "lolilol" << std::endl;
        //    }
           //  std::cout << " fait" << std::endl;


           // return(buff_next);
        }


        size_type erase( const Key& key )
        {
             iterator f = this->recherche(key);

                if (f == NULL || f == this->_tree.biggest_inv())
                    return (0);

                this->_tree.supprimer(key);
                return (1);
        }

};
}

#endif