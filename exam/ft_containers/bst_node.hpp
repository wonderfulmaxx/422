#ifndef BST_NODE_HPP
#define BST_NODE_HPP

#include <cstddef>
#include <memory>
#include <iostream>

#include "utility.hpp"

namespace ft
{
	template < typename Key, typename T, typename Allocator = std::allocator< ft::pair< Key, T > > >
	class BSTNode
	{
		public:
			typedef typename ft::pair< Key, T >	pair;

			BSTNode(Key key, T value, Allocator alloc = Allocator()) :data(ft::make_pair(key, value)), left(NULL), right(NULL), parent(NULL), alloc(alloc) {
				this->previous = NULL;
				this->next = NULL;
			}

			~BSTNode() {
				this->previous = NULL;
				this->next = NULL;
			}

			pair data;
			BSTNode<Key, T> *left, *right, *parent, *previous, *next;

		private:
			Allocator alloc;
	};

} // namespace ft

#endif