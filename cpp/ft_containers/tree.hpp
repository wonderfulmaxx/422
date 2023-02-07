#ifndef TREE_HPP
#define TREE_HPP
 
#include <iostream>
#include "map_utils.hpp"
#include "map.hpp"
 
namespace ft
{

	static int global_counter ;

// Définition du noeud en tant que struct
template <typename T>
struct Noeud
{
//	Noeud () : donnees(NULL),gauche(),droit() {}
	Noeud(const T& val) : is_invisible(false), donnees(val), gauche(NULL), droit(NULL), previous(NULL), next(NULL){}
	Noeud (): is_invisible(true), gauche(NULL), droit(NULL), previous(NULL), next(NULL){}

	bool is_invisible;
    T donnees;
    Noeud <T>* gauche;
    Noeud <T>* droit;
	Noeud <T>* previous;
	Noeud <T>* next;
	Noeud <T>* root;
};

// Définition de la classe Liste
 template<class T, class Compare = std::less<T>,
        class Node = Noeud<T>, class node_alloc = std::allocator<Node> >
class Tree
{	
	public:
	 typedef        Node*                             node_pointer;

    private:

		size_t       _size;
		node_alloc      _node_alloc;
        Noeud <T>* racine;
		 node_pointer    invisible_node;
		//key_compare     _comp;

        Noeud <T>* CreerNoeud (const T& valeur)
		{
			Noeud<T> *temp = _node_alloc.allocate(1);
			_node_alloc.construct(temp, Node(valeur));
			temp->root = racine;
			_size ++;
			return temp;
		}

		 Noeud <T>* CreerNoeud ()
		{
			Noeud<T> *temp = _node_alloc.allocate(1);
			_node_alloc.construct(temp, Node());
			temp->root = racine;
			return temp;
		}

		void detruire (Noeud <T>* ptr)
		{
			if (!ptr)
				{return;}
	
    		detruire (ptr -> gauche); // détruire le sous-arbre gauche
   			detruire (ptr -> droit); // détruire le sous-arbre droit
   		 	//std::cout << "destruction\n";
			_node_alloc.destroy(ptr);
			_node_alloc.deallocate(ptr,1); // détruire la racine
		}

        bool inserer (const T& value, Noeud <T>*& ptr)
		{
			// si l'arbre vide, inserer comme racine
			if (!ptr)
			{
				if (smallest(this->racine) && value.first < smallest(this->racine)->donnees.first)
				{
					_node_alloc.destroy(smallest(this->racine)->previous);
					_node_alloc.deallocate(smallest(this->racine)->previous,1);
					smallest(this->racine)->previous = NULL;
					ptr = CreerNoeud(value); 
					ptr->previous = CreerNoeud();
				}
				else if (biggest(this->racine) && value.first > biggest(this->racine)->donnees.first)
				{
					_node_alloc.destroy(biggest(this->racine)->next);
					_node_alloc.deallocate(biggest(this->racine)->next,1);
					biggest(this->racine)->next = NULL;
					ptr = CreerNoeud(value);
					ptr->next = CreerNoeud();
				}
				else if (!biggest(this->racine) && !smallest(this->racine))
				{
					ptr = CreerNoeud(value);
					ptr->previous = CreerNoeud();
					ptr->next = CreerNoeud();
				}
				else
				{
					ptr = CreerNoeud(value);
				}
				return (true);
			}
			// si la value est inférieure à la value de racine,
			// insérer le noeud dans le sous-arber gauche
			else if (value.first < ptr->donnees.first)
			{
				return (inserer(value, ptr->gauche));
			}
			// Sinon, insérer le noeud dans le sous-arber droit
			else if (value.first > ptr->donnees.first)
			{
				return(inserer(value, ptr->droit));
			}
			else return (false);
		}

		Noeud <T>* infixe (Noeud <T>* ptr, int target) const
		{
			Noeud<T>* test = NULL;

			if (!ptr)
				return(NULL);
			test = infixe (ptr -> gauche, target);
			if (test)
				return (test);
			
			if (global_counter == target)
				return (ptr);

			//std::cout << ptr->donnees.second << " \n";

			global_counter ++;
   			test = infixe (ptr -> droit, target);
			if (test)
				return (test);

			if (global_counter == target)
				return (ptr);
			else 
				return (NULL);
		}

        // void prefixe (Noeud <T>* ptr) const; // Fonction d'aide
        // void postfixe (Noeud <T>* ptr) const; // Fonction d'aide
		
        Noeud <T>* successeur (Noeud <T>* ptr) const
		{
			if (!ptr)
				return(NULL);
			
			Noeud<T> *temp = ptr;

			while (temp->gauche != NULL)
			{
				temp = temp->gauche;
			}

			return (temp);

		}

		Noeud <T>* predecesseur (Noeud <T>* ptr, Noeud <T>*& parent) const; // Fonction d'aide

        void supprimer (Noeud <T>* ptr, Noeud <T>* parent)
		{
			//std::cout << "booba"<< std::endl;
			//std::cout << "dans supprimer, " << ptr->donnees.first << " -> gauche = " << ptr->gauche << ", droit = " << ptr->droit << std::endl;
			if (ptr->gauche == 0 && ptr->droit == 0)
			{
			//	std::cout << "mager du caca" << std::endl;
				if (ptr != racine)
				{
					
					if (parent->gauche == ptr)
					{
						
						if (smallest(this->racine) && ptr == smallest(this->racine))
						{
							
							parent->previous = ptr->previous;
							
						}
						parent->gauche = NULL;
					}
					else
					{
						if (biggest(this->racine) && ptr == biggest(this->racine))
						{
							parent->next = ptr->next;
						}
						parent->droit = NULL;
					}
				}
				else
				{
					racine = NULL; 

					//here ptetre besoin de destroy next et previous
					_node_alloc.destroy(ptr->previous);
					_node_alloc.deallocate(ptr->previous,1);
					_node_alloc.destroy(ptr->next);
					_node_alloc.deallocate(ptr->next,1);
				}

				_node_alloc.destroy(ptr);
				_node_alloc.deallocate(ptr,1);
			}
			else if (ptr->gauche && ptr->droit)
			{
				Noeud<T> *pere = ptr;
				// ici vous pouvez utiliser le prédécesseur aussi
				Noeud<T> *succ = successeur(ptr->droit);
				T val = succ->donnees;
				supprimer(succ, pere);
				ptr->donnees = val;
			}
			else
			{
				Noeud<T> *enfant = (ptr->gauche) ? ptr->gauche : ptr->droit;
				if (ptr != racine)
				{
					if (ptr == parent->gauche)
						parent->gauche = enfant;
					else
						parent->droit = enfant;
				}
				else
				{
					if (racine->previous)
						enfant->previous = racine->previous;
					if (racine->next)
						enfant ->previous = racine ->previous;
					racine = enfant;
					racine_maj(racine,racine);
				}

				_node_alloc.destroy(ptr);
				_node_alloc.deallocate(ptr,1);
			}
			_size --;
		}

		void racine_maj(Noeud<T>* target, Noeud<T>*racine)
		{
			target -> root = racine;

			if (target->gauche)
				racine_maj(target->gauche, racine);
			if (target->droit)
				racine_maj(target->droit, racine);
			if (target -> next)
				target ->next -> root = racine;
			if (target -> previous)
				target ->previous -> root = racine;

		}

		template <typename I>
		node_pointer recherche(const I &value, node_pointer ptr, Noeud<T> *&parent) const
		{
			if (!ptr)
			{
				// Arbre est vide
				return NULL;
			}
			else if ((ptr->donnees.first) == value)
			{
				// la value recherchée est stockée dans la racine
				return ptr;
			}
			else if (value < (ptr->donnees.first))
			{
				parent = ptr;
				// la value recherchée est dans le sous-arbre gauche
				return recherche(value, ptr->gauche, parent);
			}
			else
			{
				parent = ptr;
				// sinon, la value recherchée est dans le sous-arbre droit
				return recherche(value, ptr->droit, parent);
			}
		}

	public:
        Tree ():  _size(0),racine(NULL), invisible_node(NULL) {}

		//explicit map( const Compare& comp, const Allocator& alloc = Allocator() ) {}

        ~Tree () 
		{
			if (racine)
				detruire();
		}

        bool inserer (const T& value)
		{
			return(inserer(value,racine));
		}
        void detruire ()
		{
			detruire(racine);
			racine = NULL;
		}
		template <typename I>
		bool supprimer(const I &value)
		{

			Noeud <T>* parent = NULL;
			//std::cout << "avant =" << buff->droit << std::endl;
			node_pointer buff = recherche(value,racine,parent);
			///std::cout << "bro look: "<< buff->donnees.first << "droit =" << buff->droit << std::endl;
			if (buff == NULL)
			{
				//std::cout << "buff = null, on annule\n";
			 return false;
			}
			//std::cout << "buff =" << buff->donnees.first<< std::endl;// << buff->gauche->donnees.first << " " << buff->droit->donnees.first << std::endl;
			supprimer(buff, parent);
			return true;


			// Noeud<T> *parent = 0;
			// Noeud<T> *del = recherche(value, racine, parent);
			// if (del == 0)
			// {
			// 	std::cout << "Le noeud n'appartient pas a l'arbre" << std::endl;
			// }
			// else
			// {
			// 	supprimer(del, parent);
			// }
		}

		template <typename I>
		Noeud <T>* recherche (const I& value) const
		{
			Noeud <T>* parent = NULL;
			return(recherche(value,racine,parent));
		}

		
        Noeud<T>* infixe (int target) const
		{
			
			return(infixe(racine, target));
		}

		Noeud<T>* smallest(Noeud<T>* root)
		{
			if (!root)
				return(this->invisible_node);
			Noeud <T>* target = racine;
			while (target -> gauche)
				target = target -> gauche;
			return target;
		}

		Noeud<T>* biggest(Noeud<T>* root)
		{
			if (!root)
				return(this->invisible_node);
			Noeud <T>* target = racine;
			while (target -> droit)
				target = target -> droit;
			return target; 
		}

		Noeud<T>* biggest_inv(Noeud<T>* root)
		{
			if (!root)
				return(this->invisible_node);
			Noeud <T>* target = racine;
			while (target -> droit)
				target = target -> droit;
			if (target -> next)
				target = target->next;
			return target; 
		}

		Noeud<T>* smallest_inv(Noeud<T>* root)
		{
			if (!root)
				return(this->invisible_node);
			Noeud <T>* target = racine;
			while (target -> gauche)
				target = target -> gauche;
			if (target -> previous)
				target = target -> previous;
			return target;
		}


		Noeud<T>* get_root() const
        {
            return (this->racine);
        }

		size_t get_size()
		{
			return (_size);
		}

		void affichage_racine()
		{
			std::cout << "racine = " << (*racine).donnees.second << std::endl;
		}

		// int search_pos(Noeud <T>* k)
        // {
        //     int counter;
        //     while (_tree.infixe(counter) != k)
        //         counter ++;
        //     return (counter);
        // }

        // void prefixe () const;
        // void postfixe () const;
        // int taille () const;
        // bool estVide () const;
};
}



#endif