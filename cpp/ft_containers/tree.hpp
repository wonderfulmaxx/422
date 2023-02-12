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
	Noeud <T>* rip;
	Noeud <T>* amigo_inv;
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
		node_pointer    invisible_node_inf;
		node_pointer    invisible_node_sup;
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
					//std::cout << "A\n";
					_node_alloc.destroy(smallest(this->racine)->previous);
					_node_alloc.deallocate(smallest(this->racine)->previous,1);
					smallest(this->racine)->previous = NULL;
					ptr = CreerNoeud(value); 
					ptr->previous = CreerNoeud();
					invisible_node_inf = ptr->previous;
					invisible_node_inf->amigo_inv = invisible_node_sup;
					//invisible_node_inf->previous = invisible_node_sup;
					//std::cout << "lors de sa creation, ini= " << invisible_node_inf << std::endl;
				}
				else if (biggest(this->racine) && value.first > biggest(this->racine)->donnees.first)
				{
					//std::cout << "B\n";
					_node_alloc.destroy(biggest(this->racine)->next);
					_node_alloc.deallocate(biggest(this->racine)->next,1);
					biggest(this->racine)->next = NULL;
					ptr = CreerNoeud(value);
					ptr->next = CreerNoeud();
					invisible_node_sup = ptr->next;
					invisible_node_sup->amigo_inv = invisible_node_inf;
					//invisible_node_sup->next = invisible_node_inf;
					//std::cout << "lors de sa creation, ins= " << invisible_node_sup << std::endl;
				}
				else if (!biggest(this->racine) && !smallest(this->racine))
				{
					//std::cout << "C\n";
					ptr = CreerNoeud(value);
					ptr->previous = CreerNoeud();
					ptr->next = CreerNoeud();
					invisible_node_inf = ptr->previous;
					invisible_node_sup = ptr->next;
					invisible_node_inf->amigo_inv=invisible_node_sup;
					//std :: cout << "dans inserer, amigo =" << invisible_node_inf->amigo_inv << std::endl;
					invisible_node_sup->amigo_inv=invisible_node_inf;
					//invisible_node_inf->previous = invisible_node_sup;
					//invisible_node_sup->next = invisible_node_inf;
				}
				else
				{
				//	std::cout << "D\n";
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
				//std::cout << "mager du caca" << std::endl;
				if (ptr != racine)
				{
					//std::cout << "mager du caca" << std::endl;
					if (parent->gauche == ptr)
					{
					//	std::cout << "parent = " << parent->donnees.second  << "ptr = " << ptr->donnees.second<< std::endl;
						if (smallest(this->racine) && ptr == smallest(this->racine))
						{
							
							parent->previous = ptr->previous;
							//parent->rip = ptr;
							
						}
						parent->rip = parent->gauche ;
						parent->gauche = NULL;
					}
					else
					{
						if (biggest(this->racine) && ptr == biggest(this->racine))
						{
						//	std::cout << "supp: biggest ("<< ptr->donnees.second << ") ->next =" << ptr->next->donnees.second << std::endl;
							parent->next = ptr->next;
						}
						parent->rip = parent->droit;
						parent->droit = NULL;
					}
				}
				else
				{
				//	std::cout << "A" << std::endl;
					racine_maj (racine,NULL);
					racine = NULL; 
					
				//	std::cout << "A" << std::endl;

					//here ptetre besoin de destroy next et previous
					//_node_alloc.destroy(ptr->previous);
				//		std::cout << "B" << std::endl;
					//_node_alloc.deallocate(ptr->previous,1);
				//	std::cout << "B" << std::endl;
					//_node_alloc.destroy(ptr->next);
					//_node_alloc.deallocate(ptr->next,1);
				//	std::cout << "C" << std::endl;
				}
				//std::cout << "D" << std::endl;
				_node_alloc.destroy(ptr);
				//std::cout << "E" << std::endl;
				_node_alloc.deallocate(ptr,1);
				//std::cout << "F" << std::endl;
			}
			else if (ptr->gauche && ptr->droit)
			{
				Noeud<T> *pere = ptr;
				 //std::cout << "ici vous pouvez utiliser le prédécesseur aussi\n";
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
				//	std::cout << "on descend \n";
					if (ptr == parent->gauche)
						parent->gauche = enfant;
					else
					{
						if (ptr == biggest(racine))
							enfant ->next = ptr ->next; //here gere dans lautre sens stp
						parent->droit = enfant;
					}
				}
				else
				{
					if (racine->previous)
						enfant->previous = racine->previous;
					if (racine->next)
						enfant ->next = racine ->next;
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
				return ptr;
			}
			else if (value < (ptr->donnees.first))
			{
				parent = ptr;
				return recherche(value, ptr->gauche, parent);
			}
			else
			{
				parent = ptr;
				return recherche(value, ptr->droit, parent);
			}
		}

	public:
        Tree ():  _size(0),racine(NULL), invisible_node_inf(NULL),invisible_node_sup(NULL) {}

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
		T &operator_hook(const I key)
		{
			node_pointer result = this->recherche(key);
			//std::cout << "result = " << result; 
			if (!result)
			{
				this->inserer(T(key));
				result = this->recherche(key);
				return (result->donnees);
			}
			return result->donnees;
		}

		template <typename I>
		bool supprimer(const I &value)
		{

			//std::cout << "welcome in supprimer, nous supprimerons " << value << std::endl;

			Noeud <T>* parent = NULL;
			//std::cout << "avant =" << buff->droit << std::endl;
			node_pointer buff = recherche(value,racine,parent);

			//std::cout << "apres recherhce, nous savons que next de " << buff->donnees.second << " (aka " << buff << ") = " << buff->next <<std::endl;
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

		Noeud<T>* smallest(Noeud<T>* root) const
		{
			if (!root)
			{
				//std::cout << "no root, ini = " << this->invisible_node_inf;
				//std::cout << " mon ami ins = " << this->invisible_node_sup << std::endl;
				return(this->invisible_node_inf);
			}
			Noeud <T>* target = racine;
			while (target -> gauche)
				target = target -> gauche;
			return target;
		}

		// Noeud<T>* smallest() const
		// {
		// 	if (!this->racine)
		// 	{
		// 		//std::cout << "pas de racine, ini = " << invisible_node_inf << std::endl;
		// 		return(this->invisible_node_inf);
		// 	}
		// 	Noeud <T>* target = racine;
		// 	while (target -> gauche)
		// 		target = target -> gauche;
		// 	return target;
		// }

		Noeud<T>* biggest(Noeud<T>* root) const
		{
			if (!root)
			{
				//std::cout << "no root, ins = " << this->invisible_node_sup;
				//std::cout << ", mon ami ini = " << this->invisible_node_inf << std::endl;
				return(this->invisible_node_sup);
			}
			Noeud <T>* target = racine;
			while (target -> droit)
				target = target -> droit;
			return target; 
		}

		Noeud<T>* biggest_inv(Noeud<T>* root) const
		{
			if (!root)
			{
				//std::cout << "no root, ins = " << this->invisible_node_sup ;
				//std::cout << ", mon ami ini = " << this->invisible_node_inf << std::endl;
				return(this->invisible_node_sup);
			}
			Noeud <T>* target = racine;
			while (target -> droit)
				target = target -> droit;
			if (target -> next)
			{
		//		std::cout << "good\n";
				target = target->next;
			}
			
		//	std::cout << "biggest_inv = " << target->donnees.second << std::endl;

			return target; 
		}

		Noeud<T>* smallest_inv(Noeud<T>* root) const
		{
			if (!root)
				return(this->invisible_node_inf);
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

		void free_all(node_pointer root)
		{
			if (root == NULL)
				return;

			this->free_all(root->gauche);
			this->free_all(root->droit);

			// if (root->previous)
			// {
			// 	this->_node_alloc.destroy(root->previous);
			// 	root->previous = NULL;
			// }
			// if (root -> next)
			// {
			// 	this->_node_alloc.destroy(root->next);
			// 	root->next = NULL;
			// }

			if (this->racine == root)
			{
				this->_node_alloc.destroy(this->racine);
				this->_size--;

				this->racine->gauche = NULL;
				this->racine->droit = NULL;
				this->racine = NULL;
			}
			else
			{
				this->_node_alloc.destroy(root);
				this->_size--;

				root->gauche = NULL;
				root->droit = NULL;
				//root = NULL;
			}

			if (this->_size == 0)
			{
				this->racine = NULL;
				this->invisible_node_inf = NULL;
				this->invisible_node_sup = NULL;
			}
		}

		size_t get_size() const
		{
			return (_size);
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