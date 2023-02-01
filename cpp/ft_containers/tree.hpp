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
	Noeud(const T& val) : donnees(val), gauche(NULL), droit(NULL), previous(NULL), next(NULL){}
	Noeud ():donnees(0), gauche(NULL), droit(NULL), previous(NULL), next(NULL){}

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
		node_alloc      _node_alloc;

        Noeud <T>* racine;

        Noeud <T>* CreerNoeud (const T& valeur)
		{
			Noeud<T> *temp = _node_alloc.allocate(1);
			_node_alloc.construct(temp, Node(valeur));
			temp->root = racine;
			return temp;
		}

		 Noeud <T>* CreerNoeud ()
		{
			Noeud<T> *temp = _node_alloc.allocate(1);
			_node_alloc.construct(temp, Node());
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
				if (smallest() && value.first < smallest()->donnees.first)
				{
					_node_alloc.destroy(smallest()->previous);
					_node_alloc.deallocate(smallest()->previous,1);
					smallest()->previous = NULL;
					ptr = CreerNoeud(value);
					ptr->previous = CreerNoeud();
				}
				else if (biggest() && value.first > biggest()->donnees.first)
				{
					_node_alloc.destroy(biggest()->next);
					_node_alloc.deallocate(biggest()->next,1);
					biggest()->next = NULL;
					ptr = CreerNoeud(value);
					ptr->next = CreerNoeud();
				}
				else if (!biggest() && !smallest())
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

			std::cout << ptr->donnees.second << " \n";

			global_counter ++;
   			test = infixe (ptr -> droit, target);
			if (test)
				return (test);

			if (global_counter == target)
				return (ptr);
			else 
				return (NULL);
		}

        void prefixe (Noeud <T>* ptr) const; // Fonction d'aide
        void postfixe (Noeud <T>* ptr) const; // Fonction d'aide
		
        Noeud <T>* successeur (Noeud <T>* ptr, Noeud <T>*& parent) const
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
			if (ptr->gauche == 0 && ptr->droit == 0)
			{
				//cout << ptr->donnees << parent->donnees << endl;
				if (ptr != racine)
				{
					if (parent->gauche == ptr)
					{
						if (smallest() && ptr == smallest())
						{
							parent->previous = ptr->previous;
						}
						parent->gauche = NULL;
					}
					else
					{
						if (biggest() && ptr == biggest())
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
				Noeud<T> *succ = successeur(ptr->droit, pere);
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
					racine = enfant;

				_node_alloc.destroy(ptr);
				_node_alloc.deallocate(ptr,1);
			}

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
        Tree ():racine(NULL){}//,compteur(0){}

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
		void supprimer(const I &value)
		{

			Noeud <T>* parent = NULL;
			supprimer(recherche(value,racine,parent), parent);


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

		Noeud<T>* smallest()
		{
			if (!racine)
				return(NULL);
			Noeud <T>* target = racine;
			while (target -> gauche)
				target = target -> gauche;
			return target;
		}

		Noeud<T>* biggest()
		{
			if (!racine)
				return(NULL);
			Noeud <T>* target = racine;
			while (target -> droit)
				target = target -> droit;
			return target; 
		}

		// int search_pos(Noeud <T>* k)
        // {
        //     int counter;
        //     while (_tree.infixe(counter) != k)
        //         counter ++;
        //     return (counter);
        // }

        void prefixe () const;
        void postfixe () const;
        int taille () const;
        bool estVide () const;
};
}



#endif