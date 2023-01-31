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

		pair& operator*() { return (_node->donnees); }
		pair* operator->(){ return &(_node->donnees); }
		bool operator !=(const iterator &other) const {return(_node =! other.node);}
		bool operator ==(const iterator &other) const {return(_node == other.node);}

		iterator &operator++()
		{
			if (_node->next)
			{
				_node = _node->next;
				return (*this);
			}
			if (_node->droit)
			{
				_node = _node->droit;
				while (_node->droit)
					_node = _node->gauche;
			}
			else
			{
				std::cout << "impossible lol(++)\n";
			}
			return (*this);
		}

		// }

	};
}

#endif