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
				std::cout << "attention: si index sur previous bug car !previous.first\n";
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
			if (_node->gauche)
			{
				_node = _node->gauche;
				while (_node->droit)
					_node = _node->droit;
			}
			else
			{
				if (_node->previous)
				{
					//std::cout << "theo bg\n";
					_node = _node->previous;
				}
				else
				{
					std::cout << "on va chercher le lapin blanc, actuel = "<< _node->donnees.first <<"\n";
					node_pointer ptr = _node->root;
					_node = _recherche(_node, ptr);
				}
			}
			return(*this);
		}

			private:
				node_pointer recherche(node_pointer target, node_pointer inspector, node_pointer theo, node_pointer superior)
				{
					if (inspector->donnees.first > target->donnees.first)
					{
						node_pointer theo = inspector;
						superior = theo;
						inspector = inspector->gauche;
						return (recherche(target, inspector, theo, superior));
					}
					else if (inspector->donnees.first < target->donnees.first)
					{
						node_pointer theo = inspector;
						inspector = inspector->droit;
						return (recherche(target, inspector, theo, superior));
					}
					return (superior);
				}


				node_pointer recherche(node_pointer target, node_pointer inspector)
				{

					if (inspector->donnees.first > target->donnees.first)
					{
						node_pointer theo = inspector;
						node_pointer superior = inspector;
						inspector = inspector->gauche;
						return (recherche(target, inspector, theo, superior));
					}
					else // if (inspector->donnees.first < target->donnees.first)
					{
						node_pointer theo = inspector;
						inspector = inspector->droit;
						return (recherche(target, inspector, theo, NULL));
					}
				}

				node_pointer _recherche(node_pointer target, node_pointer inspector, node_pointer theo, node_pointer inferior)
				{
					std::cout << "nous voici dans la boucle Neo\n";
					if ((!target->donnees.first && inspector->donnees.first) || inspector->donnees.first < target->donnees.first)
					{
						
						node_pointer theo = inspector;
						inferior = theo;
						std::cout << "check 0\n";
						std::cout << "check1: inspector.donnee.first = " << inspector->donnees.first << std::endl;
						inspector = inspector->droit;
						
						return (_recherche(target, inspector, theo, inferior));
					}
					else if (inspector->donnees.first > target->donnees.first)
					{
						std::cout << "check2\n";
						node_pointer theo = inspector;
						inspector = inspector->gauche;
						return (_recherche(target, inspector, theo, inferior));
					}
					return (inferior);
				}


				node_pointer _recherche(node_pointer target, node_pointer inspector)
				{

					if ((!target->donnees.first) || inspector->donnees.first < target->donnees.first)
					{
						std::cout << "on va descendre encore un peu\n";
						node_pointer theo = inspector;
						node_pointer inferior = inspector;
						
						inspector = inspector->droit;
						
						return (_recherche(target, inspector, theo, inferior));
					}
					else // if (inspector->donnees.first < target->donnees.first)
					{
						std::cout << "on est passer dans le else\n";
						node_pointer theo = inspector;
						inspector = inspector->gauche;
						return (_recherche(target, inspector, theo, NULL));
					}
				}
			};
}

#endif