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

        map(const map &other) : _allocator(other._allocator), _comp(other._comp)
        {
            this->insert(other.begin(), other.end());
        }

        explicit map(const key_compare& comp, const allocator_type& alloc = allocator_type()) : _allocator(alloc), _comp(comp) {}
        
        template<class InputIt>
        map(InputIt first, InputIt last, const key_compare& comp = key_compare(), const allocator_type alloc = allocator_type()) : _allocator(alloc), _comp(comp)
        {
            this->insert(first, last);
        }
        ~map() {}

        class value_compare : public std::binary_function<value_type_2, value_type_2, bool>
        {
        public:
            value_compare(){};
            ~value_compare(){};

            bool operator()(const value_type_2 &lhs, const value_type_2 &rhs) const { return (comp(lhs.first, rhs.first)); }

        protected:
            Compare comp;
        };

        key_compare key_comp() const
        {
            return this->_comp;
        }

        iterator upper_bound (const key_type& k)
            {
                iterator it = this->begin();

                while (it != this->end()){
                    if (this->_comp(k, it->first))
                        return it;
                    it++;
                }
                return this->end();
            }

            const_iterator upper_bound (const key_type& k) const
            {
                const_iterator it = this->begin();

                while (it != this->end()){
                    if (this->_comp(k, it->first))
                        return it;
                    it++;
                }
                return this->end();
            }

            iterator lower_bound (const key_type& k)
            {
                iterator it = this->begin();

                while (it != this->end()){
                    if (!this->_comp(it->first, k))
                        return it;
                    it++;
                }
                return this->end();
            }

            const_iterator lower_bound (const key_type& k) const
            {
                const_iterator it = this->begin();

                while (it != this->end()){
                    if (!this->_comp(it->first, k))
                        return it;
                    it++;
                }
                return this->end();
            }


        allocator_type get_allocator() const
        {
            return this->_allocator;
        }

        value_compare value_comp() const
        {
            return value_compare();
        }

        map &operator=(const map &x)
        {
            this->clear();
            this->insert(x.begin(), x.end());
            return (*this);
        }

        void clear ()
        {
            std::cout << "meu\n" << std::endl;
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

        const mapped_type &at(const key_type &k) const
        {
          node_pointer node_ptr = this->_tree.recherche(k);
            if (node_ptr)
                return node_ptr->donnees.second;
            else
                throw std::out_of_range(" map::at:  key not found");
        }

         mapped_type&                operator[] (const key_type& k)      { return (this->_tree.operator_hook(k)).second; }

            ft::pair<iterator, bool> insert(const value_type_2 &value)
            {
                bool ret = this->_tree.inserer(value);
                node_pointer testptr = this->_tree.recherche(value.first);

                ft::pair<iterator, bool> result(testptr, ret);
                return result;
            }

            template <class InputIterator>
            void insert(InputIterator first, InputIterator last)
            {
                for (; first != last; first++)
                {
                    value_type_2 tmp((*first).first, (*first).second);
                    // std::cout << "-insert: " << tmp.first << ", droit = " << tmp.droit<< std::endl;
                    this->insert(tmp);
                }
            }

            size_type count (const key_type& k) const
            {
                if (this->_tree.recherche(k))
                    return 1;
                return 0;
            }

            bool                        empty() const                       { return this->size() == 0; }
             iterator                    find (const key_type& k)            { return iterator(this->_tree.recherche(k)); }
            const_iterator              find (const key_type& k) const      { return const_iterator(this->_tree.recherche(k)); }

            pair<const_iterator,const_iterator> equal_range (const key_type& k) const
            {
                return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
            }

            pair<iterator,iterator>             equal_range (const key_type& k)
            {
                return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
            }

            void swap(map &other)
            {
                ft::map<Key, T> other_copy;
                for (const_iterator it = other.begin(); it != other.end(); it++)
                    other_copy.insert(*it);

                other.clear();
                for (const_iterator it = this->begin(); it != this->end(); it++)
                    other.insert(*it);

                this->clear();
                for (const_iterator it = other_copy.begin(); it != other_copy.end(); it++)
                    this->insert(*it);
            }

            // iterator begin()
            // {
            //     std::cout << "here\n";
            //     return iterator(this->_tree.smallest());
            // }

            const_iterator begin() const { return iterator(this->_tree.smallest(this->_tree.get_root())); }
            const_iterator end() const { return iterator(_tree.biggest_inv(_tree.get_root())); }

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

            const_reverse_iterator rend() const
            {
                return reverse_iterator(this->_tree.smallest_inv(this->_tree.get_root()));
            }

            void affichage_racine()
            {
                _tree.affichage_racine();
            }

            size_t size() const
            {
                return (_tree.get_size());
            }

            void erase(iterator pos)
            {
                this->_tree.supprimer(pos->first);
            }

            void erase(iterator first, iterator last)
            {
                //  while (first != last){
                // 	    this->erase(first++);
                //     }

                iterator buff_next = first;
                buff_next++;

                while (buff_next != last)
                {
                    // std::cout << "suppression de " << first->second;
                    // if (first != this->_tree.smallest_inv(this->_tree.get_root()))
                    this->_tree.supprimer(first->first);
                    // std::cout << " fait";
                    first = buff_next;
                    buff_next++;
                    // std::cout << "   Now buff_next = "<< buff_next->second << std::endl;
                }
                //  std::cout << "prout" << std::endl;
                // std::cout << "buff_next = " << buff_next->second << std::endl;
                // if (!buff_next->is_invisible)
                //  {
                //  buff_next ++;
                // std::cout << "suppression de " << first->second;
                // std::cout << "lolilol" << std::endl;
                // if (last == this->_tree.biggest_inv(this->_tree.get_root()))
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
             iterator f = this->find(key);

                if (f == NULL || f == this->_tree.biggest_inv(this->_tree.get_root()))
                    return (0);

                this->_tree.supprimer(key);
                return (1);
        }
        };
}

#endif