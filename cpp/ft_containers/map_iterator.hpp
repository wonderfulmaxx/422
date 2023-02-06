#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include "tree.hpp"
//#include "map.hpp"

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
		bool operator !=(const iterator &other) const {return(_node != other._node);}
		bool operator ==(const iterator &other) const {return(_node == other._node);}

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
				while (_node->gauche)
					_node = _node->gauche;
			}
			else
			{
			//	std::cout << "attention: si index sur previous bug car !previous.first\n";
				node_pointer ptr = _node->root;
				_node = recherche(_node, ptr);
			}
			return (*this);
		}

		iterator      operator++(int)                                         
        {
            iterator old = *this;
            operator++();
            return old;
        }

		iterator& operator --()
		{
			//std::cout << "Hello there\n";
			if (_node->gauche)
			{
				//std::cout << "A" << std::endl;
				_node = _node->gauche;
				while (_node->droit)
					_node = _node->droit;
			}
			else
			{
				if (_node->previous)
				{
					//std::cout << "B" << std::endl;
					//std::cout << "theo bg\n";
					_node = _node->previous;
				}
				else
				{
				//	std::cout << "C" << std::endl;
					//std::cout << "on va chercher le lapin blanc, actuel = "<< _node->donnees.first <<"\n";
					node_pointer ptr = _node->root;
					//std::cout << ptr->donnees.first << std::endl;
					_node = _recherche(_node, ptr);
				}
			}
			return(*this);
		}

		iterator operator--(int)
		{
			iterator tmp(*this);
			--(*this);
			return (tmp);
		}

		private:
			node_pointer recherche(node_pointer target, node_pointer inspector,node_pointer superior)
			{
				if ((inspector->is_invisible && (!target->is_invisible)) || inspector->donnees.first > target->donnees.first)
				{
					superior = inspector; 
					if (inspector->previous)
						inspector = inspector->previous;
					else
						inspector = inspector->gauche;
					return (recherche(target, inspector, superior));
				}
				else if (inspector->donnees.first < target->donnees.first)
				{
					inspector = inspector->droit;
					return (recherche(target, inspector, superior));
				}
				return (superior);
			}


			node_pointer recherche(node_pointer target, node_pointer inspector)
			{
				if ((inspector->is_invisible) ||inspector->donnees.first > target->donnees.first)
				{
					node_pointer superior = inspector;
					if (inspector->previous)
						inspector = inspector->previous;
					else
						inspector = inspector->gauche;
					return (recherche(target, inspector, superior));
				}
				else 
				{
					inspector = inspector->droit;
					return (recherche(target, inspector, NULL));
				}
			}

			node_pointer _recherche(node_pointer target, node_pointer inspector, node_pointer inferior)
			{
					
				if ((target->is_invisible && (!inspector->is_invisible)) || inspector->donnees.first < target->donnees.first)
				{
					inferior = inspector;
						
					if (inspector -> next)
						inspector = inspector->next;
					else
						inspector = inspector->droit;
						
					return (_recherche(target, inspector, inferior));
				}
				else if ( inspector->donnees.first > target->donnees.first)
				{	
					inspector = inspector->gauche;
					return (_recherche(target, inspector, inferior));
				}
				
				return (inferior);
			}


			node_pointer _recherche(node_pointer target, node_pointer inspector)
			{

				if ((target->is_invisible) || inspector->donnees.first < target->donnees.first)
				{

					node_pointer inferior = inspector;
					
					if (inspector -> next)
						inspector = inspector->next;
					else if (inspector -> droit)
						inspector = inspector->droit;
						
					return (_recherche(target, inspector, inferior));
				}
				else 
				{
					inspector = inspector->gauche;
					return (_recherche(target, inspector, NULL));
				}
			}
	
	};
}

#endif