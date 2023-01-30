#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include "tree.hpp"

namespace ft
{
	template <class Key, class T>
	class iterator
	{
	public:
		typedef ft::Noeud<ft::pair<Key, T> >		node;
		typedef node*                               node_pointer;
		typedef ft::pair<Key, T>                    pair;

	private:
		node_pointer _node;

	public:
		iterator() : _node(NULL) {}
		iterator(const node_pointer ptr) : _node(ptr) {}
		iterator(const iterator& other): _node(other._node) {}

		operator                    iterator<const Key, const T> () const     {return (iterator<const Key, const T>(this->_node)); }
		virtual ~iterator() {}

		pair& operator*() { return (_node->value); }
		pair* operator->(){ return &(_node->value); }
		bool operator !=(const iterator &other) const {return(_node =! other.node);}
		bool operator ==(const iterator &other) const {return(_node == other.node);}

		// iterator & operator ++()
		// {
		// 	if (_node->droit)
		// 	{
		// 		_node = node->droit
		// 		while (node->gauche)
		// 		_node = node->gauche
		// 	}
				
		// }

	};
}

#endif