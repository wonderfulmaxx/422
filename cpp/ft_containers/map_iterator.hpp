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
					std::cout << "theo bg\n";
					_node = _node->previous;
				}
				else
				{
					std::cout << "theo bgggg\n";
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

				// node_pointer _recherche(node_pointer target, node_pointer inspector)
				// {
				// 	if (!target->donnees.first || inspector->donnees.first < target->donnees.first)
				// 	{
				// 		//node_pointer theo = inspector;
				// 		node_pointer inferior = inspector;
				// 		if (inspector->next)
				// 		{
				// 			std::cout << "lol" << std::endl;
				// 			inspector = inspector->next;
				// 		}
				// 		else
				// 		{
				// 			std::cout << "pouet" << std::endl;
				// 			inspector = inspector->droit;
				// 		}
				// 		if (inspector->donnees.first == target->donnees.first)
				// 		{
				// 			std::cout << "Belle bite, gg" << std::endl;
				// 			return (inferior);
				// 		}
				// 		else 
				// 			return (_recherche(target,inspector));
				// 	}
				// 	else
				// 	{
				// 		std::cout << "pas gerer, inspector: "<<inspector->donnees.first << " > target : "<< target->donnees.first<< std::endl;
				// 		return(_recherche(target,inspector,NULL));
				// 	}
				// }

				// node_pointer _recherche(node_pointer target, node_pointer inspector, node_pointer inferior)
				// {
				// 	if (!target->donnees.first || inspector->donnees.first < target->donnees.first)
				// 	{
				// 		//node_pointer theo = inspector;
				// 		node_pointer inferior = inspector;
				// 		if (inspector->next)
				// 		{
				// 			std::cout << "lol" << std::endl;
				// 			inspector = inspector->next;
				// 		}
				// 		else
				// 		{
				// 			std::cout << "pouet" << std::endl;
				// 			inspector = inspector->droit;
				// 		}
				// 		if (inspector->donnees.first == target->donnees.first)
				// 		{
				// 			std::cout << "Belle bite, gg" << std::endl;
				// 			return (inferior);
				// 		}
				// 		else 
				// 			return (_recherche(target,inspector));
				// 	}
				// 	else
				// 	{
				// 		std::cout << "pas gerer, inspector: "<<inspector->donnees.first << " > target : "<< target->donnees.first<< std::endl;
				// 		return(inferior);
				// 	}
				//}

				// }
			};
}

#endif