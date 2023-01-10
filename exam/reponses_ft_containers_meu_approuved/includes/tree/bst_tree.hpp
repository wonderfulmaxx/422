#ifndef BST_TREE_HPP
#define BST_TREE_HPP

#include "bst_iterator.hpp"
#include "bst_node.hpp"

// https://www.codesdope.com/course/data-structures-binary-search-trees/

namespace ft
{
	template <typename Key, typename T, typename Compare = std::less<Key>, typename Allocator = std::allocator<ft::BSTNode<Key, T> > >
	class BSTree
	{
	public:
		typedef typename ft::BSTNode<Key, T> *node_pointer;
		typedef ft::bst_iterator<Key, T> iterator;

		BSTree() : root(NULL), alloc(Allocator()), size(0)
		{
			this->_end = NULL;
		}

		~BSTree() {}

		ft::pair<iterator, bool> insert(ft::pair<Key, T> p)
		{
			node_pointer x = this->root;
			node_pointer y = NULL;

			while (x && x != this->_end)
			{
				y = x;
				if (x->data.first == p.first)
					return (ft::make_pair(iterator(x), false));

				if (this->_comp(p.first, x->data.first))
					x = x->left;
				else
					x = x->right;
			}

			node_pointer new_node = this->alloc.allocate(1);
			this->alloc.construct(new_node, ft::BSTNode<Key, T>(p.first, p.second));

			new_node->parent = y;

			if (this->root == NULL || this->root == this->_end)
				this->root = new_node;
			else if (this->_comp(new_node->data.first, y->data.first))
				y->left = new_node;
			else
				y->right = new_node;

			this->size++;

			this->last_node();
			this->before_first_node();

			return (ft::make_pair(iterator(new_node), true));
		}

		void last_node()
		{
			node_pointer x = this->root;
			node_pointer y = NULL;

			if (!this->_end)
				this->_end = this->alloc.allocate(1);

			while (x && x->right)
			{
				y = x;
				x = x->right;
			}

			if (y)
				y->next = NULL;
			if (x)
			{
				x->next = this->_end;
				this->_end->previous = x;
			}

			if (!x && !y)
			{
				this->_end->previous = NULL;
				this->root = this->_end;
			}
		}

		void	before_first_node()
		{
			node_pointer x = this->root;
			node_pointer y = NULL;

			if (!x)
				return ;

			if (!this->_end)
				this->_end = this->alloc.allocate(1);
			
			while (x && x->left)
			{
				y = x;
				x = x->left;
			}

			if (y)
				y->previous = NULL;

			if (x)
			{
				x->previous = this->_end;
				this->_end->next = x;
			}

			if (!x && !y)
			{
				this->_end->next = NULL;
				this->root = this->_end;
			}
		}

		void transplant(node_pointer u, node_pointer v)
		{
			if (u->parent == NULL)
			{
				this->root = v;
			}
			else if (u == u->parent->left)
			{
				u->parent->left = v;
			}
			else
			{
				u->parent->right = v;
			}

			if (v != NULL)
			{
				v->parent = u->parent;
			}
		}

		void delete_node(const Key &key)
		{
			node_pointer root = this->find(key);

			if (!root)
				return ;

			this->size--;

			if (root->left == NULL)
			{
				transplant(root, root->right);
			}
			else if (root->right == NULL)
			{
				transplant(root, root->left);
			}
			else
			{
				node_pointer y = this->get_minimum_start(root->right);
				if (y->parent != root)
				{
					transplant(y, y->right);
					y->right = root->right;
					y->right->parent = y;
				}
				transplant(root, y);
				y->left = root->left;
				y->left->parent = y;
			}
		}

		void free_all(node_pointer root)
		{
			if (root == NULL)
				return;

			this->free_all(root->left);
			this->free_all(root->right);

			if (this->root == root)
			{
				this->alloc.destroy(this->root);
				this->size--;

				this->root->left = NULL;
				this->root->right = NULL;
				this->root = NULL;
			}
			else
			{
				this->alloc.destroy(root);
				this->size--;

				root->left = NULL;
				root->right = NULL;
				root = NULL;
			}

			if (this->size == 0)
			{
				this->root = NULL;
				this->_end = NULL;
			}
		}

		node_pointer get_root()
		{
			return (this->root);
		}

		node_pointer get_minimum() const
		{
			node_pointer x = this->root;

			while (x && x->left)
				x = x->left;

			return (x);
		}

		node_pointer get_maximum() const
		{
			node_pointer x = this->root;

			while (x && x->right)
				x = x->right;

			return (x);
		}

		node_pointer get_minimum_start(node_pointer start) const
		{
			node_pointer x = start;

			while (x && x->left)
				x = x->left;

			return (x);
		}

		node_pointer find(const Key &key) const
		{
			node_pointer x = this->root;

			while (x)
			{
				if (key == x->data.first)
					return (x);
				if (this->_comp(key, x->data.first))
					x = x->left;
				else
					x = x->right;
			}

			return (NULL);
		}

		size_t get_size() const
		{
			return (this->size);
		}

		node_pointer get_end() const
		{
			return (this->_end);
		}

		node_pointer root;

	private:
		node_pointer _end;
		Allocator alloc;
		Compare _comp;
		size_t size;
	};

}

#endif