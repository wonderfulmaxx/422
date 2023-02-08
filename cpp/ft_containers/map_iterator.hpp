#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include <iterator>
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
		typedef std::ptrdiff_t                      difference_type;
		typedef std::bidirectional_iterator_tag     iterator_category;
		typedef T                                   value_type;

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

					_node = _node->previous;
				else
				{
					node_pointer ptr = _node->root;
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
				if (inspector->rip == target)
				{
					std::cout << "waza?\n";
					return (inspector);
				}
				//std::cout << "inspector = "<< inspector->donnees.second << " , target = " << target->donnees.second << std::endl;
				if ((inspector->is_invisible && (!target->is_invisible)) || inspector->donnees.first > target->donnees.first)
				{
					superior = inspector; 
					if (inspector->previous)
						inspector = inspector->previous;
					else
						inspector = inspector->gauche;
					return (recherche(target, inspector, superior));
				}
				// else if (inspector->is_invisible && target -> is_invisible)
				// {
				// 	return (inspector);
				// }
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
				//std::cout << "ici\n";	
				if ((target->is_invisible && (!inspector->is_invisible)) || inspector->donnees.first < target->donnees.first)
				{
					inferior = inspector;
						
					if (inspector -> next)
						inspector = inspector->next;
					else
						inspector = inspector->droit;
						
					return (_recherche(target, inspector, inferior));
				}
				// else if (target->is_invisible && inspector->is_invisible)
				// {
				// 	std::cout << "B\n";	
				// 	return (inspector);
				// }
				else if ( inspector->donnees.first > target->donnees.first)
				{	
				//	std::cout << "C\n";	
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



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////Riterators///////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	template <class Key, class T>
	class riterator
	{
	public:
		typedef ft::Noeud<ft::pair<Key, T> >		node;
		typedef node*                               node_pointer;
		typedef ft::pair<Key, T>                    pair;

	private:
		node_pointer _node;

	public:
		riterator() : _node(NULL) {}
		riterator(const node_pointer ptr) : _node(ptr) {}
		riterator(const riterator& other): _node(other._node) {}

		operator                    riterator<const Key, const T> () const     {return (riterator<const Key, const T>(this->_node)); }
		virtual ~riterator() {}

		pair& operator*() { return (_node->donnees); }
		pair* operator->(){ return &(_node->donnees); }
		bool operator !=(const riterator &other) const {return(_node != other._node);}
		bool operator ==(const riterator &other) const {return(_node == other._node);}

		riterator &operator--()
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

		riterator      operator--(int)                                         
        {
            riterator old = *this;
            operator--();
            return old;
        }

		riterator& operator ++()
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

					_node = _node->previous;
				else
				{
					node_pointer ptr = _node->root;
					_node = _recherche(_node, ptr);
				}
			}
			return(*this);
		}

		riterator operator++(int)
		{
			riterator old = *this;
            operator++();
            return old;
		}

		private:
			node_pointer recherche(node_pointer target, node_pointer inspector,node_pointer superior)
			{
				//std::cout << "again go we here\n Target = " << target->donnees.second << std::endl;
				if (((!inspector->is_invisible) && (target->is_invisible)) || inspector->donnees.first > target->donnees.first)
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
				//std::cout << "eject " << superior->donnees.second << std::endl;
				return (superior);
			}


			node_pointer recherche(node_pointer target, node_pointer inspector)
			{
				if ((target->is_invisible) ||inspector->donnees.first > target->donnees.first)
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